# Números "aleatorios"

> No hay tal cosa como un *numero aleatorio*, por ejemplo: que tiene de aleatorio el número 2? en lugar hablaremos de una secuencia de numeros aleatorios con una distribución de probabilidades determinada. (**Donal Knuth**)

## Aleatoreidad, determinismo y replicabilida

Considerando que las computadoras son máquinas deterministas, es natural pensar que carece completamente de proposito intentar generar números aleatorios con ellas. Y de alguna manera es cierto.  

Si queremos generar una secuencia de números aleatorios podemos extraerlos de alguna forma de observaciones de procesos naturales aleatorios, sin embargo estos tienen ciertas desventajas. La más importante es la **replicabilidad**.


## Middle square algoritm
Este algoritmo fue propuesto por *Jhon Von Neuman* y simplemente consiste en partiendo de un número inicial (semilla ó *seed*) elevarlo al cuadrado, y a ese número extraerle los 4 dígitos del medio. El próximo número de la secuencia serán los 4 digitos intermedios de  este último resultado elevado al cuadrado y así sucesivamente.

Acá dejo una implementación de este algorítmo en C [`./LCG.c`](./LCG.c)

## Linear congruence generator 

Este algorítmo, también conocido como algoritmo de *Linhem*, utiliza el cálculo modular (ó congruencia) para generar número aleatorios. Se inicia con una *semilla*, y 3 números, llamemoslos **a**,**c** y **m**.

el primer número de la secuencia será la semilla (**s**), luego el próximo número es:
<center>
a * s + c (mod m)
</center>

 así se prosigue sucesivamente como : 

<center>
n<sub>i+1</sub> = a n<sub>i</sub> + c (mod m)
</center>

Acá dejo una implementación de este algorítmo en C [`./MSA.c`](./MSA.c)
