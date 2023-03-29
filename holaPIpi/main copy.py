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
    YUCATAN = 7


estaciones = {
    "kone": set([States.MICHOACAN, States.OAXACA, States.PUEBLA]),
    "ktwo": set([States.CHIAPAS, States.MICHOACAN, States.AGUASCALIENTES]),
    "kthree": set([States.GUANAJUATO, States.OAXACA, States.TAMAULIPAS]),
    "kfour": set([States.OAXACA, States.PUEBLA]),
    "kfive": set([States.TAMAULIPAS, States.YUCATAN])
}

origen = "kfour" # nombre de la estacion donde se quiere iniciar 


# -----------------------------------------------------

resultado = []
visitadas = estaciones[origen]

for key, values in estaciones.items():
    if origen == key:
        # saltarse el caso donde es si mismo
        continue

    if len(visitadas - values) > 0:
        # numero_diferencias
        visitadas = visitadas.union(values)
        resultado.append(key)

print(F"tomando '{origen}' se requieren '{len(resultado)}' estaciones para cubrir todos los estados: {str(resultado)}", )
