# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BINARY_7Z "")
set(CPACK_BINARY_BUNDLE "")
set(CPACK_BINARY_CYGWIN "")
set(CPACK_BINARY_DEB "")
set(CPACK_BINARY_DRAGNDROP "")
set(CPACK_BINARY_FREEBSD "")
set(CPACK_BINARY_IFW "")
set(CPACK_BINARY_NSIS "")
set(CPACK_BINARY_NUGET "")
set(CPACK_BINARY_OSXX11 "")
set(CPACK_BINARY_PACKAGEMAKER "")
set(CPACK_BINARY_PRODUCTBUILD "")
set(CPACK_BINARY_RPM "")
set(CPACK_BINARY_STGZ "")
set(CPACK_BINARY_TBZ2 "")
set(CPACK_BINARY_TGZ "")
set(CPACK_BINARY_TXZ "")
set(CPACK_BINARY_TZ "")
set(CPACK_BINARY_WIX "")
set(CPACK_BINARY_ZIP "")
set(CPACK_BUILD_SOURCE_DIRS "D:/01_Projekte/P_01_Soft_Tissue_Robotics/11_Demostrators/05_SummerSchool2019/01_HapticDevice/Communication/paho.mqtt.cpp-master;D:/01_Projekte/P_01_Soft_Tissue_Robotics/11_Demostrators/05_SummerSchool2019/01_HapticDevice/Communication/paho.mqtt.cpp-master/build")
set(CPACK_CMAKE_GENERATOR "Visual Studio 15 2017")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_GENERATOR "ZIP")
set(CPACK_INSTALL_CMAKE_PROJECTS "D:/01_Projekte/P_01_Soft_Tissue_Robotics/11_Demostrators/05_SummerSchool2019/01_HapticDevice/Communication/paho.mqtt.cpp-master/build;paho-mqtt-cpp;ALL;/")
set(CPACK_INSTALL_PREFIX "D:\01_Projekte\P_01_Soft_Tissue_Robotics\11_Demostrators\05_SummerSchool2019\01_HapticDevice\Communication\paho.mqtt.c-master\build\src\Debug")
set(CPACK_MODULE_PATH "D:/01_Projekte/P_01_Soft_Tissue_Robotics/11_Demostrators/05_SummerSchool2019/01_HapticDevice/Communication/paho.mqtt.cpp-master/cmake")
set(CPACK_NSIS_DISPLAY_NAME "paho-mqtt-cpp 1")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "paho-mqtt-cpp 1")
set(CPACK_OUTPUT_CONFIG_FILE "D:/01_Projekte/P_01_Soft_Tissue_Robotics/11_Demostrators/05_SummerSchool2019/01_HapticDevice/Communication/paho.mqtt.cpp-master/build/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "C:/Program Files/CMake/share/cmake-3.12/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "paho-mqtt-cpp built using CMake")
set(CPACK_PACKAGE_FILE_NAME "paho-mqtt-cpp-1-win32")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "paho-mqtt-cpp 1")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "paho-mqtt-cpp 1")
set(CPACK_PACKAGE_NAME "paho-mqtt-cpp")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Humanity")
set(CPACK_PACKAGE_VERSION "1")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_RESOURCE_FILE_LICENSE "C:/Program Files/CMake/share/cmake-3.12/Templates/CPack.GenericLicense.txt")
set(CPACK_RESOURCE_FILE_README "C:/Program Files/CMake/share/cmake-3.12/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "C:/Program Files/CMake/share/cmake-3.12/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_7Z "ON")
set(CPACK_SOURCE_CYGWIN "")
set(CPACK_SOURCE_GENERATOR "7Z;ZIP")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "D:/01_Projekte/P_01_Soft_Tissue_Robotics/11_Demostrators/05_SummerSchool2019/01_HapticDevice/Communication/paho.mqtt.cpp-master/build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_RPM "")
set(CPACK_SOURCE_TBZ2 "")
set(CPACK_SOURCE_TGZ "")
set(CPACK_SOURCE_TXZ "")
set(CPACK_SOURCE_TZ "")
set(CPACK_SOURCE_ZIP "ON")
set(CPACK_SYSTEM_NAME "win32")
set(CPACK_TOPLEVEL_TAG "win32")
set(CPACK_WIX_SIZEOF_VOID_P "4")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "D:/01_Projekte/P_01_Soft_Tissue_Robotics/11_Demostrators/05_SummerSchool2019/01_HapticDevice/Communication/paho.mqtt.cpp-master/build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
