## System Integration

System Integration Notes

Till Checkpoint 3
HDMI and micro usb port for Display(mpi7002 v2.4: http://www.lcdwiki.com/7inch_HDMI_Display-C )
https://digilent.com/reference/programmable-logic/zybo-z7/demos/hdmi 

https://www.youtube.com/watch?v=sMOZxOCfkBU&t=319s HDMI FPGA | FGPA4fun code updated to Vivado 2020.1

Zybo ref: https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/189530183/Zynq-7000 
Hello world.c vitis application program
Install minicom [DOESNT WORK ALWAYS] use putty

Booting petalinux: https://docs.xilinx.com/r/2021.1-English/ug1144-petalinux-tools-reference-guide/Steps-to-Boot-a-PetaLinux-Image-on-Hardware-with-JTAG 


https://www.youtube.com/watch?v=fOVX1d_2lvI 
The Zynq presets file takes care of mapping the correct MIO pins to the UART 1 controller and uses the following default protocol parameters: 115200 baud rate, 1 stop bit, no parity, 8-bit
character length.
ls /dev/ttyUSB*
Go to petalinux project (built into ./os): petalinux-boot --jtag --prebuilt 3
In new terminal: sudo putty
In putty terminal window: boot. Account:root, password:root
Ethernet connection established!
Keyboard power is coming , connect HDMI display
Os-dnf package manager https://docs.xilinx.com/r/en-US/ug1144-petalinux-tools-reference-guide/Package-Management 
petalinux-package --boot --force --fsbl images/linux/<zynq_type>_fsbl.elf --fpga images/linux/system.bit --u-boot
Make blink counter vivado project
A software application will be created that utilizes hardware interrupts on the Zynq development board.
This application will run on the Zynq processing system, communicating with the AXI GPIO blocks implemented in the PL.
Project name: counter–book-eg2 from the zynq book



Run verilog code directly: try!!!
https://www.youtube.com/watch?v=aeMQJEfGsPY 
Old- https://students.iitk.ac.in/eclub/assets/tutorials/Verilog-xilinx.pdf 
https://www.rs-online.com/designspark/lab1-verilog 
Slide data: http://www.ioe.nchu.edu.tw/Pic/CourseItem/4468_20_Zynq_Architecture.pdf 


Till Checkpoint 2
Steps for init: https://www.realdigital.org/doc/4ddc6ee53d1a2d71b25eaccc29cdec4b 
https://www.youtube.com/watch?v=_odNhKOZjEo (arty)
https://www.youtube.com/watch?v=Mb-cStd4Tqs 
Select Boards for project. 
Create a simple Zynq embedded system which implements a General Purpose Input/Output (GPIO) controller in the PL of the Zynq device.
A Verilog source file is created to define the circuits behavior.
a constraints files is created to define how the Verilog circuit is mapped into the Xilinx logic device
the Verilog source file and constraints file are synthesized into a “.bit” file that can be programmed onto your board; and
the device is configured with the circuit.

OS:
https://github.com/Digilent/Petalinux-Zybo-Z7-10 
https://github.com/Digilent/digilent-apps 
https://digilent.com/reference/programmable-logic/zybo/reference-manual 
load os into zybo znq
https://jeremyherbert.net/get/digilent_zybo_zynq_getting_started 
https://miscircuitos.com/tutorial-zybo-linux-i-how-to-load-linux-debian-in-zybo-zynq-with-a-sd-card/ 
https://nuclearrambo.com/wordpress/running-petalinux-on-zynq-soc-from-scratch-zybo-board/ 

Help for FPGA:
https://www.fpga4fun.com/
https://github.com/Digilent/Zybo-Z7-10-HDMI 

https://www.mathworks.com/help/hdlcoder/ug/define-and-register-custom-board-and-reference-design-for-zynq-workflow.html 
https://www.instructables.com/Digital-Oscilloscope-using-Digilent-Zybo-Board/ 
Till Checkpoint 1

Main goal and features:
Setting up the FPGA-based System -
 
Installing and setting up Vivado, Vitis, and Digilent Board Files from XILINX.  The tool melds FPGA logic design and embedded ARM software development into a design flow
Writing script and connecting HDMI cable to FPGA board for video display and running the script.
Bitstream for Processor -
Bitstream is a file which contains config details of FPGA board in binary format stored as human readable hex file.
Last step of FPGA design flow before physically programming for FPGA.
After “Bitstream Generation Completed” dialog we can see Implemented Design to view how your design will be placed onto the FPGA.


Connecting GPIO for Keyboard and Display-
A GPIO pin is a generic pin which will be used for connecting devices and whose behavior can be programmed through software. 
Enable GPIO clock in register
set the pin as input
Config the Pull-up pin


Connect AXI GPIO peripherals 
Change the block properties.
Make the GPIO external.
Add the Xilinx Design Constraint (XDC) file for your board.
Booting Tiny OS -
BIOS and setup program after switch on
POST power on self test of components like memory, drivers etc by BIOS
OS loading into main memory
System Configuration and utility loading into memory
Login

