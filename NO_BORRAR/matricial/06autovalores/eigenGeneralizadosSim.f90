c Objetivo: PROBLEMAS DE AUTOVALORES Y VALORES SINGULARES
c	3 TIPOS:
c		1-    Simétricos Generalizados (GSEP)
c		2- No-Simétricos Generalizados (GNEP)
c		3- Singular Value Decomposition Generalizados (GSVD)
c
c =======================================================

c (1) Generalized Symmetric Definite Eigenproblems (GSEP)

c Drivers are provided to compute all the eigenvalues and (optionally) the eigenvectors of the following types of problems:

c	a. A z = k B z

c	b. A B z = k z

c	c. B A z = k z

	donde  A, B son hermitianas, y B difinida positiva. 
	Para estos problemas k es real.
	 The matrices Z of computed eigenvectors satisfy $Z^T A Z = \Lambda$ (problem types 1 and 3) or Z-1 A Z-T = I (problem type 2), where $\Lambda$ is a diagonal matrix with the eigenvalues on the diagonal. Z also satisfies ZT B Z = I (problem types 1 and 2) or ZT B-1 Z = I (problem type 3).

There are three types of driver routines for generalized symmetric and Hermitian eigenproblems. Originally LAPACK had just the simple and expert drivers described below, and the other one was added after an improved algorithm was discovered.

    a simple driver (name ending -GV) computes all the eigenvalues and (optionally) eigenvectors.

    an expert driver (name ending -GVX) computes all or a selected subset of the eigenvalues and (optionally) eigenvectors. If few enough eigenvalues or eigenvectors are desired, the expert driver is faster than the simple driver.

    a divide-and-conquer driver (name ending -GVD) solves the same problem as the simple driver. It is much faster than the simple driver for large matrices, but uses more workspace. The name divide-and-conquer refers to the underlying algorithm (see sections 2.4.4 and 3.4.3). 
