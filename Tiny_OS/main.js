// Modules to control application life and create native browser window
const {app, BrowserWindow, ipcMain} = require ('electron');
const path = require ('path');
const fse = require ('fs-extra');
const fs = require ('fs');
const {exec} = require ('child_process');
var child = require ('child_process').execFile;
var executablePath = 'D:\\Projects\\RISC_Vs_US\\Tiny_OS\\a.exe';
const console = require ('console');
app.console = new console.Console (process.stdout, process.stderr);

// Enable live reload for all the files inside your project directory
require ('electron-reload') ('./');
console.log ('hi');

function createWindow () {
  // Create the browser window.
  const mainWindow = new BrowserWindow ({
    width: 800,
    height: 600,
    webPreferences: {
      contextIsolation: true,
      nodeIntegration: true,
      preload: path.resolve ('./preload.js'),
    },
  });

  // and load the index.html of the app.
  mainWindow.loadFile ('index.html');
  // Open the DevTools.
  // mainWindow.webContents.openDevTools()
}

ipcMain.on ('saveCode', (event, myCode) => {
  console.log (myCode);

  fse.outputFile ('../User/userCode.txt', myCode, err => {
    if (err) {
      console.log (err);
    } else {
      console.log ('The file has been saved!');
    }
  });
});

ipcMain.on('sendCode', (event, destIp) => {
  console.log(destIp);
  // TODO: Put passwords and path dynamically
  let destPath = ':/run/media/mmcblk0p2/binaries/RISC_Vs_US-main';
  let password = "root";
  let command = 'cd ../User && sshpass -p "'+ password +'" scp userCode.txt ' + 'root@' + destIp + destPath;
  exec (
    command,
    [],
    (err, stdout, stderr) => {
      if (err) {
        console.error (`exec error: ${err}`);
        return;
      }
      if (stderr) {
        console.error (`std exec error: ${stderr}`);
        return;
      }
      console.log (stdout);
    }
  );

})

ipcMain.on ('runCode', (event, filePath) => {
  exec (
    'cd ../Compiler && ./parser < ../User/userCode.txt > ../User/TAC.tac',
    [],
    (err, stdout, stderr) => {
      if (err) {
        console.error (`exec error: ${err}`);
        return;
      }
      if (stderr) {
        console.error (`std exec error: ${stderr}`);
        return;
      }
      console.log (stdout);
    }
  );

  exec (
    'cd ../VM_VMC_Translator/ && python3 main.py ../User/TAC.tac > ../User/Assembly.asm',
    [],
    (err, stdout, stderr) => {
      if (err) {
        console.error (`exec error: ${err}`);
        return;
      }
      if (stderr) {
        console.error (`std exec error: ${stderr}`);
        return;
      }
      console.log (stdout);
    }
  );

  exec (
  'cd ../Assembler/ && make all && ./assemble.o < ../User/Assembly.asm > ../User/byteCode.byte',
  [],
  (err, stdout, stderr) => {
    if (err) {
      console.error (`exec error: ${err}`);
      return;
    }
    if (stderr) {
      console.error (`std exec error: ${stderr}`);
      return;
    }
    console.log (stdout);
  }
);

});

ipcMain.on ('runcCode', (event, filePath) => {
  exec (
    'cd ../Compiler && ./parser < ../User/userCode.txt > ../User/TAC.tac',
    [],
    (err, stdout, stderr) => {
      if (err) {
        console.error (`exec error: ${err}`);
        return;
      }
      if (stderr) {
        console.error (`std exec error: ${stderr}`);
        return;
      }
      console.log (stdout);
    }
  );
});


ipcMain.on ('runvCode', (event, filePath) => {
  exec (
    'cd ../Compiler && ./parser < ../User/userCode.txt > ../User/TAC.tac',
    [],
    (err, stdout, stderr) => {
      if (err) {
        console.error (`exec error: ${err}`);
        return;
      }
      if (stderr) {
        console.error (`std exec error: ${stderr}`);
        return;
      }
      console.log (stdout);
    }
  );

  exec (
    'cd ../VM_VMC_Translator/ && python3 main.py ../User/TAC.tac > ../User/Assembly.asm',
    [],
    (err, stdout, stderr) => {
      if (err) {
        console.error (`exec error: ${err}`);
        return;
      }
      if (stderr) {
        console.error (`std exec error: ${stderr}`);
        return;
      }
      console.log (stdout);
    }
  );
});

ipcMain.on('findDisplayValues', (event) => {
  
    let result = "";
    console.log("hello from here")

    try {

      let command = "head -2 /home/user/xilinx-projects/CPU/CPU.srcs/sim_1/new/memory_binary.mem | tail -4 > ../Device_Buffers/display_memory.txt";

      exec (
        command,
        [],
        (err, stdout, stderr) => {
          if (err) {
            console.error (`exec error: ${err}`);
            return;
          }
          if (stderr) {
            console.error (`std exec error: ${stderr}`);
            return;
          }
          console.log (stdout);
        }
      );
    

        let data = fs.readFileSync('../Device_Buffers/display_memory.txt', 'utf8');
        data = data.split('\n');
        let start = Math.pow(2, 0)-1;
        let end = Math.min(Math.pow(2,19), data.length);
        


      for(let i=start; i< end; i+=2){

        let data_type = parseInt(data[i], 2);
        let data_val = parseInt(data[i+1],2);
        console.log(data_type, data_val)

        if (data_type == 0)
        {
            result += data_val;
            
        }else if(data_type == 1){
            result += String.fromCharCode(data_val)
        }

        
      }


    } catch (err) {
      console.error(err);
    }


    try {
      fs.writeFileSync('../Device_Buffers/memory_map.txt', result);
      // file written successfully
    } catch (err) {
      console.error(err);
    }


})


ipcMain.handle ('refreshDisplay', async event => {
  console.log ('yo yo yo');
  // Write code here to read the file with the updated display information
  // and send it to the renderer process
  const data = fs.readFileSync ('../Device_Buffers/memory_map.txt', 'utf-8');
  console.log (data);
  return data;
});

// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.whenReady ().then (() => {
  createWindow ();

  app.on ('activate', function () {
    // On macOS it's common to re-create a window in the app when the
    // dock icon is clicked and there are no other windows open.
    if (BrowserWindow.getAllWindows ().length === 0) createWindow ();
  });
});

// Quit when all windows are closed, except on macOS. There, it's common
// for applications and their menu bar to stay active until the user quits
// explicitly with Cmd + Q.
app.on ('window-all-closed', function () {
  if (process.platform !== 'darwin') app.quit ();
});

// In this file you can include the rest of your app's specific main process
// code. You can also put them in separate files and require them here.
