c (3) Singular Value Decomposition (SVD)
c	A =  U S V*    con A mxn
c			donde:
c				S=diagonal con valores singulares mxn
c				U=ortogonal/unitaria
c				V=ortogonal/unitaria
c	En las columnas de U,V están los vectores singulares de A (izq y der)		
c Rutinas:
c	-  Simple (-SVD) computes all the singular values and (optionally) left and/or right singular vectors.
c	- divide-and-conquer (-SDD) hace lo mísmo, pero es mucho más rápido para matrices grandes, aunque consume más recursos. 
c

