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

