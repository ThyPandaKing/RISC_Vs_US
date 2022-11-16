const fs = require ('fs');

let result = "";

try {
    let data = fs.readFileSync('/home/user/xilinx-projects/CPU/CPU.srcs/sim_1/new/memory_binary.mem', 'utf8');
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
