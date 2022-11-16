# System Integration 

---

## Final PPT

#### File IO
- https://support.xilinx.com/s/question/0D52E00006hplq6SAA/why-fopen-command-not-work-in-sdk?language=en_US
- https://support.xilinx.com/s/question/0D52E00006iHm9LSAS/vivado-cannot-find-data-file-for-my-system-verilog-simulation?language=en_US 
- `/home/user/Documents/xilinx/CPU/CPU.sim/sim_1/behav/xsim` - output.txt copied in this path.
- There is something called `vivado.log` file which stores all the output.

#### Run verilog code on vivado
- https://www.youtube.com/watch?v=aPDT0sPr4jE bitstream done
- Remember to install cable driver : `bash ~/xilinx/Vivado/2022.1/data/xicom/cable_drivers/lin64/install_script/install_drivers/install_drivers.sh`
- https://www.youtube.com/watch?v=aeMQJEfGsPY Simulation. Codes: https://verilogcodes.blogspot.com/ 
  - ![image](https://user-images.githubusercontent.com/66141447/202178200-e3d752ca-a7c5-4784-90fb-3b5a6720a6c2.png)

- Add Constraints file from : https://github.com/Digilent/digilent-xdc/blob/master/Zybo-Z7-Master.xdc
- Tutorial: https://www.rs-online.com/designspark/lab1-verilog 
  - ![image](https://user-images.githubusercontent.com/66141447/202178293-5b6c39f6-1bce-41a0-b2fb-400c8049378f.png)

- More ref data: http://www.ioe.nchu.edu.tw/Pic/CourseItem/4468_20_Zynq_Architecture.pdf 

#### Example - Full adder:
- Code ![image](https://user-images.githubusercontent.com/66141447/202178387-bc61a323-725e-4ba4-b333-04e98b05b80c.png)
- Design ![image](https://user-images.githubusercontent.com/66141447/202178435-924b4e6e-2787-4a3b-be05-424bdf59f0ef.png)
- XDC config ![image](https://user-images.githubusercontent.com/66141447/202178476-172ea532-3412-46d3-ad44-499459ea5401.png)



#### CPU.v run from processor team
- Simulation ![image](https://user-images.githubusercontent.com/66141447/202178538-a7187de7-7e70-4bca-ab21-3a04ca6aaa16.png)


- Make sure to read input from file like this for input to RAM: 
```
initial begin
    $readmemb("/home/user/Documents/xilinx/CPU/CPU.srcs/sim_1/new/ram_data.mem", memory, 0, 63);
end 
```
  
  
 
---
 
## Till Checkpoint 3
#### Display and IO
- HDMI and micro usb port for Display(mpi7002 v2.4: http://www.lcdwiki.com/7inch_HDMI_Display-C ), https://digilent.com/reference/programmable-logic/zybo-z7/demos/hdmi 
- Display ![image](https://user-images.githubusercontent.com/66141447/202178892-674fc390-a787-4d5f-a2eb-dae06c286ece.png)
- https://www.youtube.com/watch?v=sMOZxOCfkBU&t=319s HDMI FPGA | FGPA4fun code updated to Vivado 2020.1

#### Vitis application project
- Zybo ref: https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/189530183/Zynq-7000 
- Hello world.c vitis application program: https://www.youtube.com/watch?v=Mb-cStd4Tqs&t=309s
- ![image](https://user-images.githubusercontent.com/66141447/202179060-635f4ea6-c113-4e2a-83b3-85a202a20dae.png)
- Install putty. minicom [DOESNT WORK ALWAYS] so use putty

#### Petalinux
- Booting petalinux: https://docs.xilinx.com/r/2021.1-English/ug1144-petalinux-tools-reference-guide/Steps-to-Boot-a-PetaLinux-Image-on-Hardware-with-JTAG 
- ![image](https://user-images.githubusercontent.com/66141447/202179248-759a718d-7431-4af7-82b2-ccadc7628716.png)
- https://www.youtube.com/watch?v=fOVX1d_2lvI 
  - The Zynq presets file takes care of mapping the correct MIO pins to the UART 1 controller and uses the following default protocol parameters: 115200 baud rate, 1 stop bit, no parity, 8-bit character length.
  - ls /dev/ttyUSB*
  - Go to petalinux project (built into ./os): petalinux-boot --jtag --prebuilt 3
  - In new terminal: sudo putty
  - In putty terminal window: boot. Account:root, password:root
- Ethernet connection established!
- Keyboard power is coming , connect HDMI display
- Os-dnf package manager https://docs.xilinx.com/r/en-US/ug1144-petalinux-tools-reference-guide/Package-Management 
- ![image](https://user-images.githubusercontent.com/66141447/202179757-67542117-f4ec-4f43-bcbf-35785ea0e56f.png)
- Command: `petalinux-package --boot --force --fsbl images/linux/<zynq_type>_fsbl.elf --fpga images/linux/system.bit --u-boot`

#### Make blink counter vivado project
- A software application will be created that utilizes hardware interrupts on the Zynq development board.
- This application will run on the Zynq processing system, communicating with the AXI GPIO blocks implemented in the PL.
- Project name: counter–book-eg2 from the zynq book
- ![image](https://user-images.githubusercontent.com/66141447/202180074-9b2d610d-9976-46cb-8f42-4954372cf27c.png)


---





## Till Checkpoint 2
#### Steps for init:
- Tutorial: 
  - https://www.realdigital.org/doc/4ddc6ee53d1a2d71b25eaccc29cdec4b 
  - https://www.youtube.com/watch?v=_odNhKOZjEo (arty)
  - https://www.youtube.com/watch?v=Mb-cStd4Tqs 
- Guide steps:
  - Select Boards for project. 
  - Create a simple Zynq embedded system which implements a General Purpose Input/Output (GPIO) controller in the PL of the Zynq device.
  - A Verilog source file is created to define the circuits behavior.
  - Aconstraints files is created to define how the Verilog circuit is mapped into the Xilinx logic device
  - The Verilog source file and constraints file are synthesized into a “.bit” file that can be programmed onto your board; and
the device is configured with the circuit.

#### OS Research:
- https://github.com/Digilent/Petalinux-Zybo-Z7-10 
- https://github.com/Digilent/digilent-apps 
- https://digilent.com/reference/programmable-logic/zybo/reference-manual 

#### Load os into zybo 
- https://jeremyherbert.net/get/digilent_zybo_zynq_getting_started 
- https://miscircuitos.com/tutorial-zybo-linux-i-how-to-load-linux-debian-in-zybo-zynq-with-a-sd-card/ 
- https://nuclearrambo.com/wordpress/running-petalinux-on-zynq-soc-from-scratch-zybo-board/ 
#### Help for FPGA:
- https://www.fpga4fun.com/
- https://github.com/Digilent/Zybo-Z7-10-HDMI 
- https://www.mathworks.com/help/hdlcoder/ug/define-and-register-custom-board-and-reference-design-for-zynq-workflow.html 
- https://www.instructables.com/Digital-Oscilloscope-using-Digilent-Zybo-Board/ 


---

## Till Checkpoint 1

#### Main goal and features:
1) **Setting up the FPGA-based System **-
 
- Installing and setting up Vivado, Vitis, and Digilent Board Files from XILINX.  The tool melds FPGA logic design and embedded ARM software development into a design flow
- Writing script and connecting HDMI cable to FPGA board for video display and running the script.

2) **Bitstream for Processor **-
- Bitstream is a file which contains config details of FPGA board in binary format stored as human readable hex file.
- Last step of FPGA design flow before physically programming for FPGA.
- After “Bitstream Generation Completed” dialog we can see Implemented Design to view how your design will be placed onto the FPGA.

3) **Connecting GPIO for Keyboard and Display **-
- A GPIO pin is a generic pin which will be used for connecting devices and whose behavior can be programmed through software. 
- Enable GPIO clock in register
- Set the pin as input
- Config the Pull-up pin
- Connect AXI GPIO peripherals 
- Change the block properties.
- Make the GPIO external.
- Add the Xilinx Design Constraint (XDC) file for your board.


4) **Booting Tiny OS **-
- BIOS and setup program after switch on
- POST power on self test of components like memory, drivers etc by BIOS
- OS loading into main memory
- System Configuration and utility loading into memory
- Login

