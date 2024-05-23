
$(function () {

  leerCookie();


  // $(window).scroll(function() {
  //   if($(window).scrollTop() > 75){
  //
  //     $("nav").addClass("invertir", 500);
  //   }else {
  //     $("nav").removeClass("invertir", 500);
  //   }
  // });

  // initialize skrollr if the window width is large enough
  if ($(window).width() > 992) {
    skrollr.init({
      forceHeight: false
    });

  }

  //disable skrollr if the window is resized below 992px wide
  $(window).on('resize', function () {
    if ($(window).width() <= 992) {
      skrollr.init().destroy(); // skrollr.init() returns the singleton created above
    }
  });

  $("#home , #gruposNav , #conciertosNav , #contactoNavBar").click(function(){
    var navMain = $("#navbarMenu");
    navMain.collapse('hide');
  });


  $('#home').click(function(){
    $(window).scrollTop($("#carouselHome").offset().top);
  })
  $("#conciertosNav").click(function (){
    $(window).scrollTop($("#conciertos").offset().top - 100);
  })

  $("#gruposNav").click(function (){
    $(window).scrollTop($("#grupos").offset().top-100);
  })

  $("#contactoNavBar").click(function (){
    $(window).scrollTop($("#contacto").offset().top-100);
  })


  /* FUNCIONES COOKIES */
  function setCookie(name,value,days) {
    var expires = "";
    if (days) {
      var date = new Date();
      date.setTime(date.getTime() + (days*24*60*60*1000));
      expires = "; expires=" + date.toUTCString();
    }
    document.cookie = name + "=" + (value || "")  + expires + "; path=/";
  }
  function getCookie(name) {
    var nameEQ = name + "=";
    var ca = document.cookie.split(';');
    for(var i=0;i < ca.length;i++) {
      var c = ca[i];
      while (c.charAt(0)==' ') c = c.substring(1,c.length);
      if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length,c.length);
    }
    return null;
  }
  function eraseCookie(name) {
    document.cookie = name+'=; Max-Age=-99999999;';
  }

  function leerCookie(){
    if(getCookie('aceptar_cookie') != '1'){
      $('#exampleModal').modal('show');
      $('#cookies').on('click' , function(){
        ponerCookie();
      })
    }
    else {
      $('#exampleModal').modal('hide');
    }
  }

  function ponerCookie(){
    setCookie('aceptar_cookie','1',365);
    $('#exampleModal').modal('hide');

  }



  $( ".emailForm" ).focusout(function() {
    if($(this).val() == ""){
      $(this).css({backgroundColor:"red"});
      $("#botonForm").attr("disabled" , true);
    }else {
      $(this).css({
        backgroundColor:"transparent"
      });
      if (checkEmail($(this).val())){
        $(this).css({backgroundColor:"green"});
        $("#botonForm").removeAttr("disabled");
      }else{
        $(this).css({backgroundColor:"red"});
      }
    }
  })

  function checkEmail(txt) {
    var patt = /[a-zA-Z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,3}$/;
    if(patt.test(txt))
    return true;
    else
    return false;
  }

});
