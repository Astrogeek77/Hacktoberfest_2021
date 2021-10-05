// declaring varibale once increases speed of calculator
const a = document.getElementById("ok");

function eva() {
  const b = eval(a.value);
  a.value = b;
}

function c(){
  a.value = ""
}
    