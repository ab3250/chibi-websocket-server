document.addEventListener('DOMContentLoaded', loadWindow, false)

ws = new WebSocket("ws://localhost:8080/")
console.log("initialized websocket")

 ws.onmessage = function(evt) {   
     displayDeck(JSON.parse(evt.data))
 }

 ws.onopen = function() {
     console.log("connected")
 }

 ws.onclose = function() {
     console.log("closed websocket")
 }


function displayDeck(arry){  
    arry.forEach((value, index) => {
        document.getElementById('c' + index.toString()).src='./assets/images/' + value + '.gif'
    })
}

function loadWindow (){
//   Array.from(document.getElementsByTagName('button')).forEach(function (value, i, col) {
//     col[i].onclick = function (e) { mode(e.target.id) }
//   })
  let interval = setInterval(()=>{ws.send("1")},3000)
  //clearInterval(interval)
}
