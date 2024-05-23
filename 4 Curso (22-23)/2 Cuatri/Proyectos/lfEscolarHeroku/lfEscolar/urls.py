"""lfEscolar URL Configuration

"""
from django.contrib import admin
from django.urls import path, include
from mateuSquad import views
from django.conf import settings
from django.conf.urls.static import static


urlpatterns = [
    path('registro', views.registro, name='registro'),
    path('clasificacion', views.clasificacion, name='clasificacion'),
    path('', views.iniciosesion, name='inicioSesion'),
    path('partidos', views.partidos , name = "partidos"),
    path('estadisticas', views.estadisticas , name = "estadisticas"),
    path('sobre_nosotros', views.sobre_nosotros , name = "sobre_nosotros"),
    path('partido_suelto/<int:partido_id>', views.partido_suelto , name = "partido_suelto"),
    path('anadir_partido/<int:partido_id>', views.anadir_partido, name="anadir_partido"),
    path('reclamar/<int:partido_id>', views.reclamar, name="reclamar")

    
]

if settings.DEBUG:
    urlpatterns += static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)

