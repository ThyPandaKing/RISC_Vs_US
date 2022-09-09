var editor = ace.edit ('editor');
editor.setTheme ('ace/theme/cobalt');
editor.session.setMode ('ace/mode/c_cpp');

function clear_file () {
  const myCode = `int main(){
  /*Write your code here*/
  return -1;
}`;

  editor.setValue (myCode);
}
