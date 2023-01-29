document.addEventListener('DOMContentLoaded', loadWindow, false)
let ctx

 ws = new WebSocket("ws://localhost:8080")
 console.log("initialized websocket")
 
 ws.onmessage = function(evt) {   
    const d = JSON.parse(evt.data)
    fillBox(shuffle(d))
    ws.send("go")
 }

 ws.onopen = function() {
     console.log("connected")
     ws.send("go")
 }

 ws.onclose = function() {
     console.log("closed websocket")
 }



function n(num, len = 2) {
    return `${num}`.padStart(len, '0');
}

function shuffle(array) {
var m = array.length, t, i;

// While there remain elements to shuffle…
while (m) {

    // Pick a remaining element…
    i = Math.floor(Math.random() * m--);

    // And swap it with the current element.
    t = array[m];
    array[m] = array[i];
    array[i] = t;
}
return array;
}



function fillBox(array){
  const   CanvasWidth = 800,
            CanvasHeight = 400,
            CanvasColumns = 400,
            CanvasRows = 200,
            boxWidth = CanvasWidth / CanvasColumns,
            boxHeight = CanvasHeight / CanvasRows
  let index = 0;
    for(r=0;r<CanvasRows;r++){
      for(c=0;c<CanvasColumns;c++){
        let cStart = boxWidth * c,
          cStop = cStart + boxWidth,
          rStart = boxHeight * r
          rStop = rStart + boxHeight
        ctx.fillStyle = array[index] === "0" ? 'green' : 'red'
        ctx.fillRect(cStart,rStart, cStop, rStop)
        index++
      }
    }
}

function loadWindow (){
  const c = document.getElementById("myCanvas")
  ctx = c.getContext("2d")
  
}
