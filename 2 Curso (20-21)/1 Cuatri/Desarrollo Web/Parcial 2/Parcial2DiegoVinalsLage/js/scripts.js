// estan hechas los dos ejercicios en el mismo archivo
// solo lo he subido a un ejercicio


function botonExamen(){

  var miLi = document.getElementById("miLi");
  var miA = document.createElement("a");
  var texto = document.createTextNode("Nuevo");
  miA.appendChild(texto);
  miLi.appendChild(miA);
  miA.className = "nav-link py-3 px-0 px-lg-3 rounded js-scroll-trigger";
  miLi.className = "nav-item mx-0 mx-lg-1";
}

function cambiarColor1(){
  var elemento = document.getElementById("portfolio");
  elemento.style.backgroundColor = "black";
}

function cambiarColor2(){
  var elemento = document.getElementById("portfolio");
  elemento.style.backgroundColor = "red";
}

function cambiarColor3(){
  var elemento = document.getElementById("portfolio");
  elemento.style.backgroundColor = "yellow";
}

function cambiarColor4(){
  var elemento = document.getElementById("portfolio");
  elemento.style.backgroundColor = "grey";
}

function cambiarColor5(){
  var elemento = document.getElementById("portfolio");
  elemento.style.backgroundColor = "green";
}
function cambiarColor6(){
  var elemento = document.getElementById("portfolio");
  elemento.style.backgroundColor = "pink";
}
