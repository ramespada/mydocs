c Objetivo: PROBLEMAS DE AUTOVALORES Y VALORES SINGULARES
c	3 TIPOS:
c		1-    Simétricos (SEP)
c		2- No-Simétricos (NEP)
c		3- Singular Value Decomposition (SVD)
c
c =======================================================

c (2) Problemas de Autovalores NO Simétricos
c	Ax = k x
c
c		Luego A = Q T Q*  	(decomp. de Schur)
c				donde:
c					T=triangular superior
c					Q=ortogonal
c					
c Rutinas:
c	Usan matrices genéricas (GE)
c Two pairs of drivers are provided, one pair focusing on the Schur factorization, and the other pair on the eigenvalues and eigenvectors as shown in Table 2.5:

c  (-ES): a simple driver that computes all or part of the Schur factorization of A, with optional ordering of the eigenvalues;

c  (-ESX): an expert driver that can additionally compute condition numbers for the average of a selected subset of the eigenvalues, and for the corresponding right invariant subspace;


c  (-EV): a simple driver that computes all the eigenvalues of A, and (optionally) the right or left eigenvectors (or both);

c  (-EVX): an expert driver that can additionally balance the matrix to improve the conditioning of the eigenvalues and eigenvectors, and compute condition numbers for the eigenvalues or right eigenvectors (or both). 
