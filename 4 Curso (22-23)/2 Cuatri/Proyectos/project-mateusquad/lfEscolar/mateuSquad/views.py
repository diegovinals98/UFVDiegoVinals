from django.shortcuts import render, redirect, get_object_or_404
from .models import Equipo, Usuario, Pichichi, Asistencias, Zamora, PartidosJugados,PartidosNoJugados, Reclamaciones
from .forms import ResultadoForm, UsuarioForm
from django.contrib import messages
from django.db.models import F, Q
from .models import Partido
from django.db import connection
from django.http import HttpResponse
from django.db.models import Sum
from django.contrib.auth import authenticate, login
import logging
from mateuSquad.context_processors import arbitro_context






def registro(request):
    if 'registro_botom' in request.POST:
    # hacer algo si se ha pulsado el botón
        return registrarse(request)
    return render(request, 'registro.html',)


def registrarse(request):
    
    if request.method == 'POST':
        nombre = request.POST['nombre']
        apellidos = request.POST['usernapellidosame']
        usuarioF = request.POST['usuario']
        tipo = request.POST['selectRegistro']
        contraseña = request.POST['password']
        confirmarContraseña = request.POST['confirm-password']
        if contraseña == confirmarContraseña:
            # Guardar usuario en la base de datos
            usuario = Usuario(nombre=nombre, contraseña=contraseña, usuario= usuarioF,apellidos=apellidos, tipo=tipo )
            usuario.save()
            return redirect('inicioSesion')
        else:
            error_message = 'Contraseñas no coinciden'
            return render(request, 'registro.html', {'error_message': error_message})
    else:
        return HttpResponse('El resultado no se ha agregado correctamente')

def clasificacion(request):
    def ordenar_equipos():
        return Equipo.objects.annotate(
            dif_gol=F('gf') - F('gc')
        ).order_by('-puntos', '-dg')

    equipos = ordenar_equipos()

    return render(request, 'clasificacion.html', {'equipos': equipos})
    

def iniciosesion(request):
    
    if request.method == 'POST':
        username = request.POST['username']
        password = request.POST['password']
        accede = 0
        arbitro = 0
        usuarios = Usuario.objects.all()
        for usuario in usuarios:
            if usuario.usuario == username:
                if usuario.contraseña == password:
                    accede = 1
                    request.session['nombre'] = usuario.nombre
                    logging.error('Nombre del Usuario: %s', request.session['nombre'])
                    request.session['apellidos'] = usuario.apellidos
                    logging.error('Apellidos del Usuario: %s', request.session['apellidos'])
                    if usuario.tipo == "Arbitro":
                        arbitro = 1
                        request.session['arbitro'] = arbitro
                    elif usuario.tipo == "Jugador":
                        arbitro = 2
                        request.session['arbitro'] = arbitro
                    elif usuario.tipo == "Seguidor":
                        arbitro = 3
                        request.session['arbitro'] = arbitro
                    elif usuario.tipo == "Entrenador":
                        arbitro = 4
                        request.session['arbitro'] = arbitro

                           
        if accede == 1:
            logging.error('Inicio de sesión corrrecto para usuario: %s', username)
            return redirect('clasificacion')

        else:
            error_message = 'Usuario o contraseña incorrectos'
            logging.error('Inicio de sesión fallido para el usuario %s', username)
            return render(request, 'inicioSesion.html', {'error_message': error_message})
    else:
        return render(request, 'inicioSesion.html')

            
    

def partidos(request):
    partidosJugados = PartidosJugados.objects.all()
    partidosNoJugados = PartidosNoJugados.objects.all()
    arbitro = int(arbitro_context(request)['arbitro'])

    logging.error('Arbitro %s', arbitro)
    return render(request, 'partidos.html', {'partidosJugados': partidosJugados, 'partidosNoJugados': partidosNoJugados, 'arbitro': arbitro})

def estadisticas(request):
    def ordenar_pichichi():
        return Pichichi.objects.annotate(
        ).order_by('-goles')

    def ordenar_asistencias():
        return Asistencias.objects.annotate(
        ).order_by('-asistencias')
    
    def ordenar_zamora():
        return Zamora.objects.annotate(
        ).order_by('golesencajados')

    pichichi = ordenar_pichichi()
    asistencias = ordenar_asistencias()
    zamora = ordenar_zamora

    return render(request, 'estadisticas.html', {'pichichi': pichichi ,'asistencias': asistencias ,'zamora': zamora})

def sobre_nosotros(request):
    return render(request, 'sobre_nosotros.html')

def partido_suelto(request, partido_id):
    partido = get_object_or_404(PartidosJugados, id=partido_id)
    return render(request, 'partido_suelto.html', {'partido': partido})

def anadir_partido(request, partido_id):
    partido = get_object_or_404(PartidosNoJugados, id=partido_id)
    if 'submit_button' in request.POST:
    # hacer algo si se ha pulsado el botón
        return agregar_resultado(request, partido_id)
    return render(request, 'anadir_partido.html', {'partido': partido})


def reclamar(request, partido_id):
    partido = get_object_or_404(PartidosJugados, id=partido_id)
    logging.error(partido.id)
    if 'submit_button' in request.POST:
        logging.error("Boton Pulsado")
        return agregar_reclamacion(request, partido_id)
    return render(request, 'reclamar.html', {'partido': partido})



def agregar_reclamacion(request, partido_id):
    if request.method == 'POST':
        partido = get_object_or_404(PartidosJugados, id=partido_id)
        partidoID = partido.id
        motivo = request.POST['motivo']
        reclamacion = request.POST['Justificacion']
        reclamacionCompleta = Reclamaciones(idpartido = partidoID, motivo = motivo, reclamacion = reclamacion )
        reclamacionCompleta.save()
        #return HttpResponse('El resultado se ha agregado correctamente')
        return redirect('partidos')



def agregar_resultado(request, partido_id):
    if request.method == 'POST':
        partido = get_object_or_404(PartidosNoJugados, id=partido_id)
        
        resultado_local = request.POST.get('resultado_local')
        resultado_visitante = request.POST.get('resultado_visitante')
        equipo_local = partido.equipolocal
        equipo_visitante = partido.equipovisitante

        fecha = partido.fecha 
        lugar = partido.lugar
        hora = partido.hora
        arbitro = partido.arbitro
        # Aquí puede agregar la lógica para insertar los resultados en la base de datos.
        # Puede usar el objeto de conexión a la base de datos de Django o usar el ORM.
        # Asumiendo que tiene una tabla llamada "Resultados" con las columnas "EquipoLocal",
        # "EquipoVisitante", "GolesLocal" y "GolesVisitante":
        with connection.cursor() as cursor:
            cursor.execute("INSERT INTO partidosjugados (equipoLocal, equipoVisitante, golesLocal, golesVisitante, lugar, fecha, hora, arbitro) VALUES (%s, %s, %s, %s,%s, %s, %s, %s)", [equipo_local, equipo_visitante, resultado_local, resultado_visitante,lugar, fecha, hora, arbitro])
        
        equipoLocal = Equipo.objects.get(nombre=equipo_local)
        equipoVisitante = Equipo.objects.get(nombre=equipo_visitante)
        id_equipo_Local = equipoLocal.id
        id_equipo_Visitante = equipoVisitante.id

        
        # Gana el equipo local
        if resultado_local > resultado_visitante:
            # Para el equipo local
            mi_objeto_Local = Equipo.objects.get(id=id_equipo_Local)
            mi_objeto_Local.gf = int(mi_objeto_Local.gf) + int(resultado_local)
            mi_objeto_Local.gc = int(mi_objeto_Local.gc) + int(resultado_visitante)
            mi_objeto_Local.dg = mi_objeto_Local.gf - mi_objeto_Local.gc 
            mi_objeto_Local.pg = mi_objeto_Local.pg + 1
            mi_objeto_Local.puntos = mi_objeto_Local.puntos + 3
            mi_objeto_Local.save()
            # para el equipo visitante
            mi_objeto_Visitante = Equipo.objects.get(id=id_equipo_Visitante)
            mi_objeto_Visitante.gf = int(mi_objeto_Visitante.gf) + int(resultado_visitante)
            mi_objeto_Visitante.gc = int(mi_objeto_Visitante.gc) + int(resultado_local)
            mi_objeto_Visitante.dg = mi_objeto_Visitante.gf - mi_objeto_Visitante.gc 
            mi_objeto_Visitante.pp = mi_objeto_Visitante.pp + 1
            mi_objeto_Visitante.save()

         # Gana el equipo Visitante
        if resultado_local < resultado_visitante:
            # Para el equipo local
            mi_objeto_Local = Equipo.objects.get(id=id_equipo_Local)
            mi_objeto_Local.gf = int(mi_objeto_Local.gf) + int(resultado_local)
            mi_objeto_Local.gc = int(mi_objeto_Local.gc) + int(resultado_visitante)
            mi_objeto_Local.dg = mi_objeto_Local.gf - mi_objeto_Local.gc 
            mi_objeto_Local.pp = mi_objeto_Local.pp + 1
           
            mi_objeto_Local.save()
            # para el equipo visitante
            mi_objeto_Visitante = Equipo.objects.get(id=id_equipo_Visitante)
            mi_objeto_Visitante.gf = int(mi_objeto_Visitante.gf) + int(resultado_visitante)
            mi_objeto_Visitante.gc = int(mi_objeto_Visitante.gc) + int(resultado_local)
            mi_objeto_Visitante.dg = mi_objeto_Visitante.gf - mi_objeto_Visitante.gc 
            mi_objeto_Visitante.pg = mi_objeto_Visitante.pg + 1
            mi_objeto_Visitante.puntos = mi_objeto_Visitante.puntos + 3
            mi_objeto_Visitante.save()

        # Empate
        if resultado_local == resultado_visitante:
            # Para el equipo local
            mi_objeto_Local = Equipo.objects.get(id=id_equipo_Local)
            mi_objeto_Local.gf = int(mi_objeto_Local.gf) + int(resultado_local)
            mi_objeto_Local.gc = int(mi_objeto_Local.gc) + int(resultado_visitante)
            mi_objeto_Local.dg = mi_objeto_Local.gf - mi_objeto_Local.gc 
            mi_objeto_Local.pe = mi_objeto_Local.pe + 1
            mi_objeto_Local.puntos = mi_objeto_Local.puntos + 1
           
            mi_objeto_Local.save()
            # para el equipo visitante
            mi_objeto_Visitante = Equipo.objects.get(id=id_equipo_Visitante)
            mi_objeto_Visitante.gf = int(mi_objeto_Visitante.gf) + int(resultado_visitante)
            mi_objeto_Visitante.gc = int(mi_objeto_Visitante.gc) + int(resultado_local)
            mi_objeto_Visitante.dg = mi_objeto_Visitante.gf - mi_objeto_Visitante.gc 
            mi_objeto_Visitante.pe = mi_objeto_Visitante.pe + 1
            mi_objeto_Visitante.puntos = mi_objeto_Visitante.puntos + 1
            mi_objeto_Visitante.save()

        PartidosNoJugados.objects.filter(id=partido_id).delete()
        return redirect('partidos')
    else:
        return HttpResponse('El resultado no se ha agregado correctamente')



