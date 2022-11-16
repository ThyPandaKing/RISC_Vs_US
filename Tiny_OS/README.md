## Tiny OS

### Getting Started

```bash
# Clone this repository
git clone https://github.com/PandaKing9660/RISC_Vs_US.git
# Go into the repository
cd Tiny_OS
# Install dependencies
npm install
# Run the app
npm start
```

### About the OS

The Tiny OS is a virtualization of various OS components so that we can explore the vairous components and the concepts behind them. 
Our computer System is balanced between two systems - 
1. A Linux host system that runs Vivado and the electron.js OS user interface 
2. An FPGA board (Zybo Z7) with 2 chips - an ARM processor and a programmable chip

Figure 1: The schematic diagram of the various components that comprise the system

![Integrated System Schematic](../Integrated%20Computer%20System%20Diagram.png)

### The Host Linux Machine:

The electron.js user interface provides a GUI for the user to interact with the OS. The user can run programs, view the output of the programs given by the processor, and interact through the virtual keyboard to pass commands to the machine.


The electron.js user interface communicates with the FPGA board using linux system calls tied together using bash scripts. The host machine and the board communicate over SSH. 


### The FPGA Board

The FPGA board has two chips - an ARM processor and a programmable chip. The ARM processor is used to run the OS and the user interface. The programmable chip is used to run the processor and the memory. The processor and the memory are connected to the ARM processor through a serial connection. The ARM processor and the programmable chip communicate through the host machine which we handle manually through Vivado.


### Authors
1. Debeshee Das
2. Aditya Sharma
3. Sai Srujan
* Sowmya



# electron-quick-start

**Clone and run for a quick way to see Electron in action.**

This is a minimal Electron application based on the [Quick Start Guide](https://electronjs.org/docs/latest/tutorial/quick-start) within the Electron documentation.

A basic Electron application needs just these files:

- `package.json` - Points to the app's main file and lists its details and dependencies.
- `main.js` - Starts the app and creates a browser window to render HTML. This is the app's **main process**.
- `index.html` - A web page to render. This is the app's **renderer process**.

You can learn more about each of these components within the [Quick Start Guide](https://electronjs.org/docs/latest/tutorial/quick-start).

## To Use

To clone and run this repository you'll need [Git](https://git-scm.com) and [Node.js](https://nodejs.org/en/download/) (which comes with [npm](http://npmjs.com)) installed on your computer. From your command line:



