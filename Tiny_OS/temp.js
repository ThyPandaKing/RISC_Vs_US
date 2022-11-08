const {exec} = require ('child_process');

exec (
  'pwd',
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
