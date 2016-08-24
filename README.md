## Swaloo SDK Examples


* Usage

1. Setting up a development environment (arm-none-eabi-gcc)
The steps are explained in depth at https://launchpad.net/gcc-arm-embedded

2. And swatools/bin

On Windows:

Download gcc-arm-embedded
Please note that you will have to add the directory with executables 
(arm-none-eabi-gcc, arm-none-eabi-as etc.) to your PATH variable in both cases. 


On Mac OS X:
Install the PX4 Toolchain. ARM maintains a pre-built GNU toolchain with a GCC source branch targeted 
at Embedded ARM Processors, namely Cortex-R/Cortex-M processor families. 

After installing, ensure that the symbolic link installed by Homebrew points to the correct version 
of the debugger.

$ brew tap PX4/homebrew-px4
$ brew update
$ brew install gcc-arm-none-eabi-49
$ arm-none-eabi-gcc --version  

On Linux:
arm-none-eabi-gcc can be installed with apt-get as documented below. 

$ sudo apt-get remove binutils-arm-none-eabi gcc-arm-none-eabi 
$ sudo add-apt-repository ppa:terry.guo/gcc-arm-embedded 
$ sudo apt-get update 
$ sudo apt-get install gcc-arm-none-eabi
$ sudo apt-get install gdb-arm-none-eabi