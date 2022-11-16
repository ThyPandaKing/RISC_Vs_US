var returnPixelMap = function(str) {
    var pixelMap = "";
    console.log("inside pixel map function")

    const NUM_OF_ROW_PIXELS = 358;
    const NUM_OF_COL_PIXELS = 128;

    var row = new Array (NUM_OF_COL_PIXELS);
    for (let i = 0; i < row.length; i++) {
      row[i] = new Array (NUM_OF_ROW_PIXELS);
    }

    for (let i = 0; i < row.length; i++) {
      for (let j = 0; j < row[i].length; j++) {
        row[i][j] = 0;
        if(i==200)
            row[i][j] = 1;
      }
    }
  
    var pixel = '<div>';
    for (let i = 0; i < row.length; i++) {
      pixel = pixel + '<div style="display:flex;">';
      for (let j = 0; j < row[i].length; j++) {
        if (row[i][j] == 1)
          pixel =
            pixel +
            '<div style="width:0.139vw;height:0.23vh;background:white;"></div>';
        else
          pixel =
            pixel +
            '<div style="width:0.139vw;height:0.23vh;background:black;"></div>';
      }
      pixel = pixel + '</div>';
    }
    pixel = pixel + '</div>';


    return pixelMap;
 }

 export default returnPixelMap;