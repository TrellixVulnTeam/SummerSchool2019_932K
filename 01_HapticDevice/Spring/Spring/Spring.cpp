/*
// Spring.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <stdio.h>
#include "include\dhdc.h"

//#pragma comment(lib, "lib/dhdms.lib")

#define K   1000.0



// simple spring model which pulls the device
// towards the center of the workspace;
// if the user lifts the device 5cm above the center,
// the application exits
int
compute_my_forces(double px, double py, double pz,
	double *fx, double *fy, double *fz)
{
	// spring model
	*fx = -K * px;
	*fy = -K * py;
	*fz = -K * pz;

	// exit condition
	if (pz > 0.05) return 1;
	else           return 0;
}



int
main(int  argc,
	char **argv)
{
	int    done = 0;
	double px, py, pz;
	double fx, fy, fz;

	if (dhdOpen() < 0) {
		printf("error: cannot open device\n");
	}

	printf("spring model applied...\n");

	while (!done) {

		// get end-effector position
		dhdGetPosition(&px, &py, &pz);
		//sendPositionOut(px, py, pz);


		// compute force model
		done = compute_my_forces(px, py, pz, &fx, &fy, &fz);
		//printf("Position: %f, %f, %f, Forces:  %f, %f, %f\n", px, py, pz , fx, fy, fz);
		//printf("Forces: %f, %f, %f\n", fx, fy, fz);

		// apply forces
		//receiveForces(&fx, &fy, &fz);
		dhdSetForce(fx, fy, fz);

		// exit if the button is pushed
		done += dhdGetButton(0);
	}
	while (false)
	{
		printf("Position: %f, %f, %f, Forces:  %f, %f, %f\n", px, py, pz, fx, fy, fz);
		//
	}
	printf("exiting application\n");

	dhdClose();

	return 0;
}
*/


#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <future>
#include <atomic>
#include <chrono>
#include <cstring>
#include "mqtt\async_client.h"
#include "mqtt\thread_queue.h"

using namespace std;
using namespace std::chrono;

const std::string DFLT_SERVER_ADDRESS{ "tcp://localhost:1883" };

const size_t	DFLT_PAYLOAD_SIZE = 1024;
const int		DFLT_N_MSG = 1000,
DFLT_QOS = 1;

const string TOPIC{ "test/speed" };

const char* LWT_PAYLOAD = "pub_speed_test died unexpectedly.";

// Queue for passing tokens to the wait thread
mqtt::thread_queue<mqtt::delivery_token_ptr> que;

// Get the current time on the steady clock
steady_clock::time_point now() { return steady_clock::now(); }

// Convert a duration to a count of milliseconds
template <class Rep, class Period>
int64_t msec(const std::chrono::duration<Rep, Period>& dur) {
	return (int64_t)duration_cast<milliseconds>(dur).count();
}

// --------------------------------------------------------------------------
// Thread function will wait for all the tokens to complete.
// Any exceptions thrown from here will be caught in main().

void token_wait_func()
{
	while (true) {
		mqtt::delivery_token_ptr tok = que.get();
		if (!tok) break;
		//cout.put('x');
		tok->wait();
	}
}

// --------------------------------------------------------------------------

int main(int argc, char* argv[])
{
	string	address = (argc > 1) ? string(argv[1]) : DFLT_SERVER_ADDRESS;
	int		nMsg = (argc > 2) ? atoi(argv[2]) : DFLT_N_MSG;
	size_t	msgSz = (size_t)((argc > 3) ? atol(argv[3]) : DFLT_PAYLOAD_SIZE);
	int		qos = (argc > 4) ? atoi(argv[4]) : DFLT_QOS;

	cout << "Initializing for server '" << address << "'..." << flush;
	mqtt::async_client cli(address, "");

	mqtt::message willmsg(TOPIC, LWT_PAYLOAD, 1, true);
	mqtt::will_options will(willmsg);

	mqtt::connect_options connOpts;
	connOpts.set_clean_session(true);
	connOpts.set_will(will);

	// Create a payload
	mqtt::binary payload;
	for (size_t i = 0; i<msgSz; ++i)
		payload.push_back('a' + i % 26);

	cout << "OK" << endl;

	try {
		// Create the message (move payload into it)
		auto msg = mqtt::make_message(TOPIC, std::move(payload), qos, false);

		// Connect to the broker
		cout << "\nConnecting..." << flush;
		auto start = now();
		cli.connect(connOpts)->wait();
		auto end = now();
		cout << "OK" << endl;

		cout << "Connected in " << msec(end - start) << "ms" << endl;

		auto fut = std::async(launch::async, token_wait_func);

		// Publish the messages
		cout << "\nPublishing " << nMsg << " messages..." << flush;
		start = now();
		for (int i = 0; i<nMsg; ++i) {
			auto dtok = cli.publish(msg);
			//cout.put('^');
			que.put(std::move(dtok));
		}
		auto pubend = now();
		que.put(mqtt::delivery_token_ptr());

		// Wait for all the tokens to complete
		fut.get();
		end = now();

		cout << "OK" << endl;
		auto ms = msec(pubend - start);
		cout << "Published in    " << ms << "ms " << (nMsg / ms) << "k msg/sec" << endl;
		ms = msec(end - start);
		cout << "Acknowledged in " << ms << "ms " << (nMsg / ms) << "k msg/sec" << endl;

		// Disconnect
		cout << "\nDisconnecting..." << flush;
		start = now();
		cli.disconnect(seconds(10))->wait();
		end = now();
		cout << "OK" << endl;
		cout << "Disconnected in " << msec(end - start) << "ms" << endl;
	}
	catch (const mqtt::exception& exc) {
		que.put(mqtt::delivery_token_ptr{});
		cerr << exc.what() << endl;
		return 1;
	}

	return 0;
}


