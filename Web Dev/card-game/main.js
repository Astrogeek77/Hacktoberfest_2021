const clicks=document.querySelector(".move")
const timer=document.querySelector(".time")
const cards=document.querySelectorAll(".card")
let firstCard;
let secondCard;
let hasFlipped=false;
let lockboard=false;
let move=0;
let pair=0;
let minute=0;
let seconds=0;
let interval;
// -------------------------------------------------------------------


function flipCard(){
    move++;
    clicks.innerHTML=move;
    if(move==1){
        startCounter();
    }
    if(lockboard)return
    if(firstCard===this)return;
this.classList.add("flip")

if(!hasFlipped){
firstCard=this
hasFlipped=true;
return
}
secondCard=this
lockboard=true
isMatch()
}
function isMatch(){
    let mach=firstCard.dataset.tech===secondCard.dataset.tech;
    if(mach){
        disableCards()
    }else{
    unflipCard();
    }
}
 function disableCards(){
     pair++
     firstCard.removeEventListener("click",flipCard)
     secondCard.removeEventListener("click",flipCard)
     if(pair===6){
        endGame()
    }
     reseatBoard();
    
 }
function unflipCard(){
setTimeout(() =>{

    firstCard.classList.remove("flip")
    secondCard.classList.remove("flip")
    reseatBoard()
},500)
}
function  reseatBoard(){
firstCard=null
secondCard=null
hasFlipped=false
lockboard=false
}

(function shuffleCards(){
    cards.forEach((card)=>{
        let postion=Math.floor(Math.random()*12)
        card.style.order=postion;
    })
}())
function endGame(){
    stopTimer();
    alert(`You win with ${move} moves & in ${minute} minutes and ${seconds} secs`)
}

function startCounter(){
    interval=setInterval(() => {
       timer.innerHTML=minute + "min" + seconds +"sec";
       seconds++;
       if(seconds===60){
           minute++;
           seconds=0;
       }
   }, 1000); 
}
function stopTimer(){
    clearInterval(interval)
}


cards.forEach(card =>{
    card.addEventListener("click",flipCard);
} )