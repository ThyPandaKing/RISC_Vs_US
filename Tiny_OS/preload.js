const {ipcRenderer} = require ('electron');

// All of the Node.js APIs are available in the preload process.
// It has the same sandbox as a Chrome extension.
window.addEventListener ('DOMContentLoaded', () => {
  let saveButton = document.getElementById ('saveButton');

  saveButton.addEventListener ('click', () => {
    console.log("Inside click event")  
    let code = document.getElementById ('hiddenCodeWriter');
    const defaultCode = `int main(){
  /*Write your code here*/
  return -1;
}`;

    const myCode = code.value == '' ? defaultCode : code.value;

    ipcRenderer.send ('saveCode', myCode);
  });

  let runButton = document.getElementById('runButton');

  runButton.addEventListener('click', ()=> {
    console.log("Inside click event")  
      ipcRenderer.send('runCode', '../User/userCode.txt');
  });

  let display = document.getElementById ('display');
  
  display.addEventListener ('click', () => {
        console.log("Inside click event")      
        var interval = setInterval(() => {
        // Write logic for reading file here
        var result_data = ipcRenderer.send ('refreshDisplay');
        console.log(result_data);
        display_div.innerHTML = result_data
    
        display_div.style.display = 'none'
        // display_div.style.display = 'block
    }, 500);
  });


});
