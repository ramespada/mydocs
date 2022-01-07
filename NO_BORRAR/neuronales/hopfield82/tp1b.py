# -*- coding: utf-8 -*-
"""TP n1: Hopfield '82 - Ramiro A. Espada"""
#
import os#,shutil
os.chdir("/home/ram/Desktop/tp1/")
import numpy as np
from matplotlib import pyplot as plt
import random#, time
from scipy import misc

'''  -- Modelo de Ising 1D & 2D -- '''
# Modelo Ising 1D.
def ejercicio5a(T=2, n=100, max_iter=1000):

    #Estado inicial
    index=np.arange(n); np.random.shuffle(index) #randomIndex
    n_negativos=random.randint(n*0.25,n*0.75)
    s0=np.ones(n); s0[index[0:n_negativos]]=-1 #inicializo los estados s.

    s=np.copy(s0)    
    H=np.zeros(max_iter) #Energía Total

    for t in range(max_iter):  
        h1=calcular_h(s)        
        
        i=random.randint(0,n-1)        
        s[i]=s[i]*-1
        h2=calcular_h(s)

        dH=-0.5*(np.sum(h2-h1))
        if dH<=0:
            H[t]=-0.5*np.sum(h2)
        else:
            p=np.exp(-dH/T)
            if p>=random.uniform(0,1):
                H[t]=-0.5*np.sum(h2)
            else:
                s[i]=s[i]*-1
                H[t]=-0.5*np.sum(h1) #H total.    
    
    plt.plot(np.arange(max_iter),H)
    plt.show()

def calcular_h(s):
    n=s.size
    h=np.zeros(n)
    for i in range(n):
        if i==0:
            h[i]=s[i]*(s[i+1])
        elif i==(n-1):
            h[i]=s[i]*(s[i-1])
        else:
            h[i]=s[i]*(s[i-1]+s[i+1])
    return(h)


# Modelo Ising 2D.
def ejercicio5b(T=2,wd=10,hg=10,max_iter=100):
   
    #Estado inicial:
    S0=np.ones([wd,hg]);
    i_index=np.arange(wd); np.random.shuffle(i_index) #randomIndex
    j_index=np.arange(hg); np.random.shuffle(j_index)
   
    n_negativos=random.randint(int(wd*hg*0.2),int(wd*hg*0.8))
    S0[i_index[0: n_negativos],j_index[0: n_negativos]]=-1 
    
    S=np.copy(S0)

    H=np.zeros(max_iter)
    for t in range(max_iter):
        i=random.randint(0,wd-1);j=random.randint(0,hg-1)    
        h1=calcular_h2D(S)        
        S[i,j]=S[i,j]*-1
        h2=calcular_h2D(S)
        dH=-0.5*(np.sum(h2-h1))
        if dH<=0:
            H[t]=-0.5*np.sum(h2)
        else:
            p=np.exp(-dH/T)
            if p>=random.uniform(0,1):
                H[t]=-0.5*np.sum(h2)
            else:
                S[i,j]=S[i,j]*-1
                H[t]=-0.5*np.sum(h1) #H total.  
        
        misc.imsave(str('5b_out/St'+str(t)+'.png'), misc.imresize(S,[200,200],'nearest'))
    
    plt.plot(np.arange(max_iter),S)
    plt.show()

def calcular_h2D(S):
    wd,hg=S.shape
    H=np.zeros([wd,hg])
    for i in range(wd):
        for j in range(hg):
            if i==0:
                Sizq=0; Sder=S[i+1,j]
            elif i==(wd-1):
                Sizq=S[i-1,j]; Sder=0
            else:
               Sizq=S[i-1,j]; Sder=S[i+1,j]
            
            if j==0:
                Sab=0; Sarr=S[i,j+1]
            elif j==(hg-1):
                Sab=S[i,j-1]; Sarr=0
            else:
               Sab=S[i,j-1]; Sarr=S[i,j+1]
            
            H[i,j]=S[i,j]*(Sizq+Sder+Sab+Sarr)
    
    return(H)