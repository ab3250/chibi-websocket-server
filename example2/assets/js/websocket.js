document.addEventListener('DOMContentLoaded', loadWindow, false)

function loadWindow () {
  Array.from(document.getElementsByTagName('button')).forEach(function (value, i, col) {
    col[i].onclick = function (e) { processButtons(e.target.id) }
})}

let ws
let createWs = function (){
ws = new WebSocket("ws://localhost:8080/ws")
console.log("initialized websocket")
//while (ws.readyState !== 1);
ws.onmessage = function(evt) {
     console.log(evt.data);
     document.getElementById('out').innerHTML = evt.data
}
ws.onopen = function(evt) {
console.log(evt.type)
console.log("connected");
}
ws.onclose = function() {
  console.log("closed websocket");
  ws.close()
}
}

//createWs()
//check if ws open before open & close before close
function processButtons (btnID) {    
    if(btnID === "close"){
        ws.close()         
        return   
    }
    if(btnID === "open"){
       createWs()
       return
    }
    ws.send(btnID)
}




