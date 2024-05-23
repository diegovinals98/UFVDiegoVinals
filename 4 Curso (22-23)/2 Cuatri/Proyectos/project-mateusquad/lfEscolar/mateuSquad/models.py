from django.db import models


class Usuario(models.Model):
    nombre = models.CharField(max_length=255)
    apellidos = models.CharField(max_length=255)
    usuario = models.CharField(max_length=255) 
    contraseña = models.CharField(max_length=255)  
    tipo = models.CharField(max_length=255) 
    class Meta:
        db_table = 'usuarios'


class Reclamaciones(models.Model):
    idpartido = models.IntegerField()
    motivo = models.CharField(max_length=255) 
    reclamacion = models.CharField(max_length=700) 

    class Meta:
        db_table = 'reclamaciones'


class Equipo(models.Model):
    nombre = models.CharField(max_length=255)
    pg = models.IntegerField()
    pe = models.IntegerField()
    pp = models.IntegerField()
    gf = models.IntegerField()
    gc = models.IntegerField()
    dg = models.IntegerField()
    puntos = models.IntegerField()

    class Meta:
        db_table = 'equipos'

   
class Pichichi(models.Model):
    equipo = models.CharField(max_length=255)
    nombrejugador = models.CharField(max_length=255)
    goles = models.IntegerField()
    
    class Meta:
        db_table = 'pichichi'

class Asistencias(models.Model):
    equipo = models.CharField(max_length=255)
    nombrejugador = models.CharField(max_length=255)
    asistencias = models.IntegerField()
    
    class Meta:
        db_table = 'asistencias'

class Zamora(models.Model):
    equipo = models.CharField(max_length=255)
    nombrejugador = models.CharField(max_length=255)
    golesencajados = models.IntegerField()
    
    class Meta:
        db_table = 'zamora'

class PartidosJugados(models.Model):
    equipolocal = models.CharField(max_length=255)
    equipovisitante = models.CharField(max_length=255)
    goleslocal = models.IntegerField()
    golesvisitante = models.IntegerField()
    lugar = models.CharField(max_length=255)
    fecha = models.CharField(max_length=255)
    hora = models.CharField(max_length=255)
    arbitro = models.CharField(max_length=255)
    
    class Meta:
        db_table = 'partidosjugados'

class PartidosNoJugados(models.Model):
    equipolocal = models.CharField(max_length=255)
    equipovisitante = models.CharField(max_length=255)
    lugar = models.CharField(max_length=255)
    fecha = models.CharField(max_length=255)
    hora = models.CharField(max_length=255)
    arbitro = models.CharField(max_length=255)
    
    class Meta:
        db_table = 'partidosnojugados'


class Partido(models.Model):
    equipo_local = models.CharField(max_length=100)
    equipo_visitante = models.CharField(max_length=100)
    goles_local = models.IntegerField()
    goles_visitante = models.IntegerField()
    fecha = models.DateField()
    hora = models.TimeField()

    
    

