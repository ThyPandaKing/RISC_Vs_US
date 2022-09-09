const {ipcRenderer} = require ('electron');
// All of the Node.js APIs are available in the preload process.
// It has the same sandbox as a Chrome extension.
window.addEventListener ('DOMContentLoaded', () => {
  let saveButton = document.getElementById ('saveButton');

  saveButton.addEventListener ('click', () => {
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
      ipcRenderer.send('runCode', '../User/userCode.txt');
  });
});
