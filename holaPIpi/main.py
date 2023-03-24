import enum

class States(enum.Enum):
    aguascalientes = 0
    chiapas = 1
    guanajuato = 2
    michoacan = 3
    Oaxaca = 4
    puebla = 5
    tamaulipas = 6
    yucatan  = 7

estaciones = [
    set([States.michoacan, States.Oaxaca, States.puebla]),
    set([States.chiapas, States.michoacan, States.aguascalientes]),
    set([States.guanajuato, States.Oaxaca, States.tamaulipas]),
    set([States.Oaxaca, States.puebla]),
    set([States.tamaulipas, States.yucatan])
]

def numero_diferencias(a, b):
    return len(a - b)

origen = 0
estaciones_visitadas = estaciones[origen]
