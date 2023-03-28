import enum

class States(enum.Enum):
    """
    Lugares en los nodos
    """
    AGUASCALIENTES = 0
    CHIAPAS = 1
    GUANAJUATO = 2
    MICHOACAN = 3
    OAXACA = 4
    PUEBLA = 5
    TAMAULIPAS = 6
    YUCATAN  = 7

estaciones = [
    set([States.MICHOACAN, States.OAXACA, States.PUEBLA]),
    set([States.CHIAPAS, States.MICHOACAN, States.AGUASCALIENTES]),
    set([States.GUANAJUATO, States.OAXACA, States.TAMAULIPAS]),
    set([States.OAXACA, States.PUEBLA]),
    set([States.TAMAULIPAS, States.YUCATAN])
]

origen = 3
resultado = []
visitadas = estaciones[origen]

for g,i in enumerate(estaciones):
    if len(visitadas - i) > 0: # numero_diferencias
        visitadas = visitadas.union(i)
        resultado.append(g)

print(F"resultado desde la estacion {origen}:", str(resultado))
for index in resultado:
    print(estaciones[index])
