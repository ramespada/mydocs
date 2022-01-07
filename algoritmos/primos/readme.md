# Números primos

> "...there is no apparent reason why one number is prime and another not. To the contrary, upon looking at these numbers one has the feeling of being in the presence of one of the inexplicable secrets of creation." (D. Zagier, 1977) 


## Generación de números primos

### Criba de Eratóstenes
La criba de eratóstenes es uno de lo métodos más eficientes para listar números primos, y la idea que utiliza es muy simple.

Supongamos que queremos hayar todos los primos menores a un número **N**, primero entonces construimos una lista que contenga todos los números desde 2 hasta **N**. Luego la recorremos desde el principio, **2** es primo, por lo tanto lo dejamos en la lista, recorremos toda la lista de *"dos en dos"* tachando todos los números que encontremos en el paso (notar que eliminamos la mitad de los números de la lista!). Proseguimos con el **3**,  también es primo (pues no fue tachado), entonces lo dejamos, y recorremos la lista de *"tres en tres"* tachando todos los números. Seguimos con el **5** (el **4** ya fue tachado así que lo salteamos) y realizamos la misma operación yendo de *"cinco en cinco"*, y así vamos descartando números de la lista hasta obtener todos los primos menores a **N**. Una forma más gráfica de ver el procedimiento:

![Alt Text](http://recursospython.com/wp-content/uploads/2016/06/sieve.gif)
Increbilemente es un procedimiento que a medida que avanza se vuelve mucho más rápido.


Acá dejo una implementación en C de la criba de eratóstenes  ([`./CribaEratostenes.c`](./CribaEratostenes.c)).


## Factorización de números en primos

Cualquier número entero puede ser descompuesto como un producto de números primos, es por esto que los números primos son considerados los *bloques fundamentales* de los números enteros. 

Para encontrar los primos que forman un número, podemos hacer uso de la criba de eratostenes (para todos los números menores a este) y probar "uno por uno" si el número en cuestión es divisible por estos primos. Guardamos cada primo que sea divisor en una lista, y obtenemos la descomposición.

El problema es que cuando el número se vuelve muy grande, este procedimiento puede volverse muy ineficiente. Y en realidad todavía no se conoce ningun procedimiento adecuado para realizar esta tarea (para computadoras electrónicas).

Sin embargo, hay una serie de consideraciones que pueden reducir bastante el número de primos a evaluar.

Por ejemplo: Llamemos **n** al número a factorizar, sólo puede existir uno y solo un primo que divida a **n** que sea mayor a la raiz cuadrada de **n**. Pues si hay más de uno su producto sería mayor a **n**.  Esto descarta bastantes primos a evaluar.

Acá dejo una implementación en C de la factorizacion de primos  ([`./FactorizacionPrimos.c`](./FactorizacionPrimos.c)).

## Algoritmos para detectar numeros primos

Acá dejo una implementación en C de la detección de primalidad  ([`./DetectorPrimos.c`](./DetectorPrimos.c)).
