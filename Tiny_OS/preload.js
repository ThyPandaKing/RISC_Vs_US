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

    console.log (code.value);
    const myCode = code.value == '' ? defaultCode : code.value;

    ipcRenderer.send ('saveCode', myCode);
  });

  // const replaceText = (selector, text) => {
  //   const element = document.getElementById(selector)
  //   if (element) element.innerText = text
  // }

  // for (const type of ['chrome', 'node', 'electron']) {
  //   replaceText(`${type}-version`, process.versions[type])
  // }
});
