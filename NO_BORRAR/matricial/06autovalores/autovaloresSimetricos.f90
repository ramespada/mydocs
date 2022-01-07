c Objetivo: PROBLEMAS DE AUTOVALORES Y VALORES SINGULARES
c	3 TIPOS:
c		1-    Simétricos (SEP)
c		2- No-Simétricos (NEP)
c		3- Singular Value Decomposition (SVD)
c
c =======================================================

c (1) Problemas de Autovalores Simétricos
c	Ax = k x    ^  A=A*
c
c		Luego A = U D U*  
c				donde:
c					D=diagonal con los autovalores
c					U=ortogonal/unitaria
c					
c Rutinas:
c	-  Simple (-EV) computa todos los autovalores y autovectores.
c
c	-  Expert (-EVX) computa autovalores y autovectores (o subconjunto de ellos). Si se piden pocos entonces es más rápido que -EV
c
c	- divide-and-conquer (-EVD) hace lo mísmo, pero es mucho más rápido para matrices grandes, aunque consume más recursos. 
c
c	- relatively robust representation (RRR) driver (-EVR) es el algorítmo más rápido y que utiliza menores recursos.
c

