# GABRIEL_ALEXANDER_VALDIVIA_MEDINA
Algoritmo de cifrado y descifrado.
En este algoritmo las claves se componen de algoritmos de 2 cifras.
La primera cifra representa el rango de números que se agrupan para luego cifrar en orden. (como si fueran las filas en la versión con matriz). Por defecto se encuentra en 2, para poder cifrar palabras pequeñas de hasta 3 letras.
La segunda cifra representa el número de veces en las que se cifrará el código usando la misma técnica (un añadido extra para reforzar el cifrado). Por defecto está en 1, pero puede incrementarse hasta 9. 
Nota: Si la segunda cifra es el doble o el cuádruple de la primera, el algoritmo devolverá al mensaje a su estado original. Por esta razón lo dejé por defecto en 1, pero si la primera cifra es cambiada a 5 o más (para cifrar mensajes largos), se podrá usar la segunda cifra sin ninguna restricción.

Se utilizó una clase para crear al emisor y receptor, la clave se mantiene privada y las funciones se encargan de cifrar y descifrar el mensaje enviado. Para los cifrados múltiples implementé recursividad en estas funciones. Por defecto la segunda cifra de la clave es 1 por lo que no se apreciará esta recursividad hasta cambiarla.
