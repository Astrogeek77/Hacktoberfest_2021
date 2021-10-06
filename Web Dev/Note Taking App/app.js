showNotes();
  
// If user adds a note, add it to the localStorage
let addBtn = document.getElementById("addBtn");
addBtn.addEventListener("click", function(e) {
    let addTxt = document.getElementById("addTxt");
    let notes = localStorage.getItem("notes");
    let color = document.getElementById("color");
    
    let size = document.getElementById("size");
    if(addTxt.value.length==0)
    {
        alert("Add a Note");
        return false;
    }

    if (notes == null)
    {
        notesObj = [];
    }
    else{
        notesObj = JSON.parse(notes);
        
    } 
    var obj = {
        'txt' :addTxt.value,
        'color' :color.value,
        'size' : size.value
    }
    notesObj.push(obj);

    localStorage.setItem("notes", JSON.stringify(notesObj));
    obj={};
    addTxt.value="";
    color.value="";
    size.value="";
    
  
    showNotes();
});
  
// Function to show elements from localStorage
function showNotes() {
    let notes = localStorage.getItem("notes");
    
    if (notes == null) 
    {
        notesObj = [];
        
    }
    else{
        notesObj = JSON.parse(notes);
        
    } 
    
    let html = "";
  
    notesObj.forEach(function(element, index) {
        var sz=parseInt(element.size);
        html += `<div>
                <div class="noteTake" >
                    <div style=" color: ${element.color};font-size:${sz}px">
                        Note ${index + 1} - ${element.txt}
                    </div>
                    <div>
                        <button id="${index}" onclick=
                        "editNote(this.id)"
                        type="button">
                        <img src="edit.png" height="10px" width="10px">
                        </button>
                        <button id="${index}" onclick=
                        "deleteNote(this.id)"
                        type="button">
                        x
                    </button>
                </div>

            </div>
        </div>`;
    });
  
    let notesElm = document.getElementById("notes");
  
    if (notesObj.length != 0) notesElm.innerHTML = html;
    else
        notesElm.innerHTML = `Nothing to show! 
        Use "Add a Note" section above to add notes.`;
}
  
// Function to delete a note
function deleteNote(index) {
    let notes = localStorage.getItem("notes");
  
    if (notes == null) notesObj = [];
    else notesObj = JSON.parse(notes);
  
    notesObj.splice(index, 1);
  
    localStorage.setItem("notes", 
        JSON.stringify(notesObj));
  
    showNotes();
}
function editNote(index){
    document.getElementById("addBtn").style.display="none";
    document.getElementById("updateBtn").style.display="block";
    
    let notes = localStorage.getItem("notes");
    if (notes == null) notesObj = [];
    else notesObj = JSON.parse(notes);

    document.getElementById("addTxt").value = notesObj[index].txt;
    document.getElementById("color").value = notesObj[index].color;
    document.getElementById("size").value = notesObj[index].size;

    
    updateBtn.addEventListener("click", function(e) {
        
        notesObj[index].txt=document.getElementById("addTxt").value;
        notesObj[index].color=document.getElementById("color").value;
        notesObj[index].size=  document.getElementById("size").value;
        localStorage.setItem("notes", JSON.stringify(notesObj));
        document.getElementById("addBtn").style.display="block";
        document.getElementById("updateBtn").style.display="none";
  
    showNotes();
    });
  
}