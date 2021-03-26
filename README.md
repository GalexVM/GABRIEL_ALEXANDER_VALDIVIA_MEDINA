# GABRIEL_ALEXANDER_VALDIVIA_MEDINA
Algoritmo de cifrado y descifrado.
En este algoritmo las claves se componen de ints de 2 cifras.
La primera cifra representa el rango de números que se agrupan para luego cifrar en orden. (como si fueran las columnas en la versión con matriz). Por defecto se encuentra en 2, para poder cifrar palabras pequeñas de hasta 3 letras.
La segunda cifra representa el número de veces en las que se cifrará el código usando la misma técnica (un añadido extra para reforzar el cifrado). Por defecto está en 1 porque es algo que no se pidió, pero puede incrementarse hasta 9. 
Nota: Si la segunda cifra es el doble o el cuádruple de la primera, el algoritmo devolverá al mensaje a su estado original. Por esta razón lo dejé por defecto en 1, pero si la primera cifra es cambiada a 5 o más (para cifrar mensajes largos), se podrá usar la segunda cifra sin ninguna restricción.

Se utilizó una clase para crear al emisor y receptor, la clave se mantiene privada y las funciones se encargan de cifrar y descifrar el mensaje enviado. Para los cifrados múltiples implementé recursividad en estas funciones. Por defecto la segunda cifra de la clave es 1 por lo que no se apreciará esta recursividad hasta cambiarla.

COMPATIBILIDAD: Cometí un error al no usar filas y columnas en la clave como se indicó, pero pensé que omitir las filas haría que al algoritmo sea más flexible con mensajes largos. De todos modos, este algoritmo puede leer codigos cifrados del algoritmo con filas y columnas, solo se tiene que cambiar la primera cifra de la clave (no importa si es mayor a 9) por el número de filas de la clave del mensaje que viene. En el caso inverso, El algoritmo sabe implícitamente el número de columnas de cada caso. (dividir la variable car de la función cifrar entre la variable nfi).
