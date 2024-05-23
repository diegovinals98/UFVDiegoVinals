$(function () {
  $('img').addClass("display : none");
  $(".mostrarImagen").on('click', function (){
    if($("#parrafo").text() == "Haz clic para mostrar la imagen"){
      $("#parrafo").text("Haz clic para ocultar la imagen");
      $('img').fadeIn();
    } else {
      $("#parrafo").text("Haz clic para mostrar la imagen");
      $('img').fadeOut();
    }

  });
});
