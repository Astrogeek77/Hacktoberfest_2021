const quizForm = document.forms[0]
const queDiv = document.querySelectorAll(".qz")
const scoreDiv = document.querySelector(".scoreHere")
const submitQuiz = document.querySelector("#submitQuiz");

const correctAns = ["option2", "option1", "option3", "option2", "option2", "option3", "option1"]
let score =0;

quizForm.addEventListener("submit", (e)=>{
    e.preventDefault();

    const data = new FormData(quizForm);
    let i=0;

    for(let entry of data){
        if (entry[1] == correctAns[i]){
            queDiv[i].style.backgroundColor = "lightgreen";
            score = score +1
        }
        else {
            queDiv[i].style.backgroundColor = "#FCA5A5";
        }
        i = i+1
    }
    scoreDiv.innerText = score;
    submitQuiz.style.display= "none";
})