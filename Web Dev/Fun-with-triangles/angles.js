const inputAngles = document.querySelectorAll('.inputAngle')
const outputDiv = document.querySelector('#isTriangle')

let angles = [];

document.addEventListener('submit', formTriangleHandler);

function formTriangleHandler(e){
    e.preventDefault();

    for (i=0; i<inputAngles.length; i++)
    {
        angles[i] = Number(inputAngles[i].value);
    }
    let sum =0;
    angles.map((angle) =>{
        sum=sum+angle;
    })

    if (sum === 180){
        outputDiv.innerText = "These angles can make a Triangle";
    }
    else {
        outputDiv.innerText = "These angles cannot make a Triangle";
    }
}

