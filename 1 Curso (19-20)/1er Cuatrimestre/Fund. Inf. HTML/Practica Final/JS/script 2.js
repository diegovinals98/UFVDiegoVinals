function pulsarBoton(){
    var nombre = document.getElementById("nombre").value;
    var apellidos = document.getElementById("apellidos").value;
    var email = document.getElementById("email").value;
    var hobbie = document.getElementById("hobbies").value;
    var estudios = document.getElementById("estudios").value;
    var fechaNac = document.getElementById("FechaNac").value;
    var DeporteFav = document.getElementById("deportes").value;
    

    if(nombre == '' || apellidos == '' || email == '' || hobbie == '' || fechaNac == '' || DeporteFav == '' || estudios == '') {
        alert("Datos incompletos");
    } else {
        var texto = "Estos son tus datos \n\tNombre: " + nombre + "\n\tApellidos: "
        + apellidos + "\n\tEmail: " + email +
        "\n\tFecha de Nacimiento: " + fechaNac + 
        "\n\tHobbie: " + hobbie + 
        "\n\tEstudios: " + estudios +
        "\n\tDeporte Favorito: " + DeporteFav +
         "\n¿seguro que desea enviar?";
        var opcion = confirm(texto);
        if(opcion == true){
            alert('Datos enviados');
        } else{
            alert('Datos no enviados');
        }

    }
    
}

var fila = 0;
function anadirAlaTabla(){


    var grupo = document.getElementById("grupo").value;
    var estilo = document.getElementById("estilo").value;
    var anio = document.getElementById("año").value;
    var albunes = document.getElementById("Albunes").value;
    var miembros = document.getElementById("miembros").value;

    if(grupo == '' || estilo == '' || anio == '' || albunes == '' || miembros == ''){
        alert("Existen datos vacios");
    } else{
    var tabla =  document.getElementById("tablas");
    var nuevafila = tabla.insertRow(fila);
    var celdaGrupo = nuevafila.insertCell(0);
    var celdaEstilo = nuevafila.insertCell(1);
    var celdaAnio = nuevafila.insertCell(2);
    var celdaAlbum = nuevafila.insertCell(3);
    var celdaMiembros = nuevafila.insertCell(4);

    var grupotexto = document.createTextNode(grupo);
    celdaGrupo.appendChild(grupotexto);
    
    var estiloTexto = document.createTextNode(estilo);
    celdaEstilo.appendChild(estiloTexto);

    var anioTexto = document.createTextNode(anio);
    celdaAnio.appendChild(anioTexto);

    var albumtexto = document.createTextNode(albunes);
    celdaAlbum.appendChild(albumtexto);

    var miembrotexto = document.createTextNode(miembros);
    celdaMiembros.appendChild(miembrotexto);



    }

}





