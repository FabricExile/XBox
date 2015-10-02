XBox
=========
A KL extension for the XBox controller

XBox allows you to read the input information, such as sticks and buttons, from the XBox controller.

extension status
================

This extension has been built and tested against Fabric Engine 2.0.0. Higher release might work, but this hasn't been validated. Feel free to use this code for reference or training purposes, it's meant to be an example of how to integrate custom libraries into KL.

structure
=========

The XBox extension uses the KL2EDK tool to generate the required C++ headers. Since the number of callbacks is quite small, they are handcrafted and don't use KL2EDK's advanced codegen functionality.

The latest KL2EDK documentation can be found here: http://documentation.fabricengine.com/FabricEngine/latest/HTML/ExtensionAuthoringGuide/kl2edk.html

Additional it uses KL2DFG to generate Canvas presets for each function of the API. These can be found in the stage output folder after building.

supported platforms
===================

XBox is currently only actively supported on Windows, should work on all OSes however, since the base library is cross-platform.
For Fabric Engine 2.0.0 the extension has to be built using Visual Studio 2013 (through scons).

building
========

A scons (http://www.scons.org/) build script is provided. XBox depends on
* A static build of boost (1.55.0 or higher)

To inform scons where to find the Fabric Engine includes as well as the thirdparty libraries, you need to set the following environment variables:

* FABRIC_DIR: Should point to Fabric Engine's installation folder.
* BOOST_INCLUDE_DIR: Should point to Boost include folder.
* BOOST_LIBRARY_DIR: Should point to Boost library folder.

The temporary files will be built into the *build* folder, while the structured output files will be placed in the *stage* folder. Optionally you can define the FABRIC_EXTS_INSTALL_DIR environment variable, to which the extension will be installed.

To build the extension you need to be in an Fabric Engine enabled shell, define the mentioned environment variables (FABRIC_DIR) will already be defined, and type

    scons

Note: The build-env.sh exists purely for Fabric Engine internal use, but you can use it as a guide for your own build setup.


usage in canvas
==================

To use the extension inside of Canvas, simply cd into the repo's root folder and source deploy.sh

    cd XBox && deploy.sh

You can of course add this to your .bashrc file, for example. Alternatively inspect deploy.sh to see the required environment variables.

samples
=======

The Canvas sample files in the canvas folder can be run with the canvas standalone command line tool.

license
==========

The license used for this extensions is the new BSD license. You can find it in the root folder of the repository.
