var editor = ace.edit ('editor');
editor.setTheme ('ace/theme/cobalt');
editor.session.setMode ('ace/mode/c_cpp');

function save_file () {
  const myCode = editor.getValue ();
  console.log (myCode);
  const textToBLOB = new Blob ([myCode], {type: 'text/plain'});

  // TODO:Will put file extension name
  const sFileName = 'userCode.txt'; 

  let newLink = document.createElement ('a');
  newLink.download = sFileName;

  if (window.webkitURL != null) {
    newLink.href = window.webkitURL.createObjectURL (textToBLOB);
  } else {
    newLink.href = window.URL.createObjectURL (textToBLOB);
    newLink.style.display = 'none';
    document.body.appendChild (newLink);
  }

  newLink.click ();
}

function clear_file () {
  const myCode = `int main(){
  /*Write your code here*/
  return -1;
}`;

  editor.setValue (myCode);
}
