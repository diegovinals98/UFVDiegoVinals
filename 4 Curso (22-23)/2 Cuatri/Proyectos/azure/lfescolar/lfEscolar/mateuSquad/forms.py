from django import forms

class ResultadoForm(forms.Form):
    equipo_local = forms.CharField(max_length=100)
    equipo_visitante = forms.CharField(max_length=100)
    goles_local = forms.IntegerField()
    goles_visitante = forms.IntegerField()


class UsuarioForm(forms.Form):
    nombre = forms.CharField(max_length=255)
    contraseña = forms.CharField(max_length=255, widget=forms.PasswordInput)
