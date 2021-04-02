# GABRIEL_ALEXANDER_VALDIVIA_MEDINA
Primer escitala:
Cumplia con la transposicion de matriz sin usar matrices. Sin embargo no utiliza una clave de filas y columnas, si no de columnas de de repeticiones de transposición. Puede comunicarse con otros escitala si se descomenta la fila 19 para saber el numero de filas.

Escitala arreglado:
Cumple con tener una claver de filas y columnas y se comunica satisfactoriamente con otros escitalas (incluyendo el alterior presentado).
La lógica empleada fue la siguiente:
  1. Calcular el máximo de espacios dependiendo de la clave (filas * columnas)
  2. Comparar ese número con el largo del string ingresado.
  2.1  Si el string es más pequeño, se le añaden especios en blanco hasta completar.
  2.2. Si es más grande, se recorta lo sobrante y se emite un mensaje de alerta de error de claves.
  3. Se itera el string 2 veces. La iteración mayor se repite (nColumnas) veces.
  4. La iteración menor avanza por el string normalmente, cuando llega a un caracter que no sea un * hace 3 cosas:
  4.1. Envía el valor a un string vacío llamado msg2.
  4.2. Convierte el valor en un * .
  4.3. Salta (nColumnas) casillas.
  5. En el descifrado el proceso es igual desde el punto 3, solo que en lugar de trabajar con nColumnas trabaja con nFilas.

