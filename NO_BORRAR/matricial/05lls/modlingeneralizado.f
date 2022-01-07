c Objetivo:
c	Resolver dos problemas de Cuadrados mínimos generalizados:

c 	  -  Mínimos cuadrados sujeto a igualdad lineal: (-LSE)
c		Resolver  min | c - Ax |    sujeto a  B x = d
c					donde A es una matrix m x n
c					      B es una matriz p x n
c					      c es un vector de m 
c					      d es un vector de p
c					y se cumple p<= n <= m + p
c
c			Se resuelve utilizando facotrización RQ (generalizada).
c			Obs: Debe cumplirse que (A B)t debe ser una matriz de rango n. Sólo esto garantiza solución única.
c
c	  -  Modelo lineal generalizado (Gauss-Markov)  (-GLM)
c		Resolver min |y|   dado que   d = Ax + By
c		  	Cuando B = I  --> cuadrados mínimos
c		  	Cuando B cuadrada, no singular  -->Minimos cuadrados ponderados
c								min_x |B^{-1}(d-Ax) | 
c			
c					Se resuelve usando factorizacion QR (generalizada). 
c					Obs: Asume que A tiene rango m, y la matriz (A,B) rango n. Sólo así el problema es consistente y la solución única.

