function pet_form() {
    let pet = {
        Name: document.getElementById('g1').value,
        Age: document.getElementById('g2').value,
        Weight: document.getElementById('g3').value,
        Type: document.getElementById('g4').value,
        Favourite: document.getElementById('g5').value
    };
    console.log(pet);
    console.log(JSON.stringify(pet));
}