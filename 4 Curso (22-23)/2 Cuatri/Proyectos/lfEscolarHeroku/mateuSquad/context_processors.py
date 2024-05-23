import logging

def arbitro_context(request):
    arbitro = 0  # Valor inicial para arbitro
    #logging.error('Request: %s', dir(request))
    arbitro = request.session.get('arbitro', 0)
    nombre = request.session.get('nombre', 0)
    apellidos = request.session.get('apellidos', 0)
    return {'arbitro': arbitro, 'nombre' : nombre, 'apellidos':apellidos}
