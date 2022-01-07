# -*- coding: utf-8 -*-
"""TP n1: Hopfield '82 - Ramiro A. Espada"""
#
#import sys
#sys.modules[__name__].__dict__.clear()
import os,shutil
os.chdir("/home/ram/Desktop/tp1/")
from matplotlib import pyplot as plt
from scipy import misc
import numpy as np #;import pandas as pd
import random
#
def ejercicio1(figID=0,max_iter=20):
    path2figs=["picts/frida.xbm","picts/turing.xbm","picts/ricky.xbm"]

    W=aprender(path2figs)

    original=readFig(path2figs[figID])
    inp=np.copy(original); inp=imnoise(inp,0.2)
    
    out=recordar(inp,W)
    
    plt.figure(1)
    plt.subplot(121);plt.imshow(inp,cmap="Greys" );plt.title("Input")   
    plt.subplot(122);plt.imshow(out,cmap="Greys");plt.title("Output")
    plt.show()

def ejercicio2(wd=50,hg=50,Perror=0.001):   
    
    path2figs=crear_patrones(wd*hg,wd,hg,"imgs"); path2figs.sort()
    
    p=0
    W=np.zeros([wd*hg,wd*hg])
    while p < wd*hg:
        print(p)
        W=agregar_un_patron(W,path2figs[p])
        if check_si_recuerda_p_patrones(W,path2figs[0:p],Perror)==0:
            break
        else:
            p=p+1
    pmax_N=float(p)/float(wd*hg)
    return(pmax_N)
    
def ejercicio3(conex_eliminadas=0.01):
    path2figs=crear_patrones(10,10,10,"imgs_ej3"); path2figs.sort()

    WW=aprender(path2figs); #wd,hg=WW.shape  

    n=np.floor(WW.size*conex_eliminadas)
    W=np.copy(WW);
    W=eliminar_conexiones(W,n)
    Err_tot=0 
    for p in range(len(path2figs)):
        original=readFig(path2figs[p])
        inp=np.copy(original);inp=imnoise(inp,0.05)
        out=recordar(inp,W)
        Err_p= p_error(original,out)
        #print(Err_p)
        Err_tot=Err_tot+Err_p
    Err=float(Err_tot)/float(len(path2figs))
    return(Err)
    
def plot_ej3(n=10):
    conex_elim=np.linspace(0,1,n)
    error=np.zeros(n)
    for i in range(n):
        error[i]=ejercicio3(conex_elim[i])
    plt.plot(conex_elim,error)

    
def ejercicio4():   
    path2figs=["picts/frida.xbm","picts/turing.xbm","picts/ricky.xbm"]
    W=aprender(path2figs)
    
    original=readFig(path2figs[1])
    inp=np.copy(original);inp=imnoise(inp,0.2)*-1  #Negativo alterado.

    out=recordar(inp,W)
    
    plt.figure(1);
    plt.subplot(121);plt.imshow(inp,cmap="Greys" );plt.title("Input")   
    plt.subplot(122);plt.imshow(out,cmap="Greys");plt.title("Output")
    plt.show()
  
#FUNCIONES AUXILIARES:  -------------------------------------- #
def aprender(figs):
    N=len(misc.imread(figs[0]));
    W=np.zeros([N*N,N*N]);
    for fig in figs:
        pat=readFig(fig)  ;      
        pat=np.reshape(pat,[N*N,1]);
        W=W+pat.dot(pat.transpose());
    W=W/(N*N);
    W[range(N*N),range(N*N)]=0;
    return(W)
    
def agregar_un_patron(W,path):
        pat=readFig(path);pat=np.reshape(pat,[pat.size,1])
        N=pat.size
        W=W+(pat.dot(pat.transpose())/N)
        W[range(N),range(N)]=0;
        return(W)
        
def recordar(inp,W):
        out=np.copy(inp)
        out=np.reshape(out,[inp.size,1]);
        out=np.sign(np.dot(W,out));
        out=np.reshape(out,inp.shape)
        #print('Tasa de cambio: '+str(np.sum(np.abs(out-inp)*0.5)))
        if np.sum(out-inp) !=0 :
            out=recordar(out,W)        
        return(out)

def pseudorandom_pat(width,height,n):
    test=np.ones([width*height])
    index_array = np.arange(width*height)
    np.random.shuffle(index_array)
    test[index_array[0:n]]=-1
    test=np.reshape(test,[height,width])
    return(test)

def crear_patrones(n,width,height,out_dir):
    shutil.rmtree(out_dir)
    os.mkdir(out_dir)    
    for i in range(n):
        img=pseudorandom_pat(width,height,random.randint(0,width*height))
        misc.imsave(str(str(out_dir)+'/random'+str(i)+'.bmp'), img)
    return([str(out_dir)+'/{0}'.format(i) for i in os.listdir(str(out_dir))])

def readFig(path2fig):
    fig=np.round(misc.imread(path2fig,flatten=1)/255)*2-1 
    return(fig)

def imnoise(fig,percent):
     wd,hg=fig.shape
     out=fig[:]
     out=np.reshape(out,[wd*hg,1])
     index_array = np.arange(wd*hg)
     np.random.shuffle(index_array)
     out[index_array[0:round(percent*hg*wd*0.5)]]=-1
     out[index_array[round(percent*hg*wd*0.5):round(percent*hg*wd)]]=1
     out=np.reshape(out,[wd,hg])
     return(out)
     
def eliminar_conexiones(W,n):
    wdt,hgt=W.shape
    index_array = np.arange(wdt*hgt); np.random.shuffle(index_array)
    #
    W=np.reshape(W,[wdt*hgt])
    W[index_array[0:n]]=0
    W=W.reshape([wdt,hgt])
    return(W)
    
def check_si_recuerda(path2patron,W,Perror):
    original=readFig(path2patron)
    inp=np.copy(original); inp=imnoise(inp,0.01)#width,height=inp.shape
    if Perror > p_error(original, recordar(inp,W)):
        return(1)
    else:
        return(0)
    
def check_si_recuerda_p_patrones(W,paths,Perror):
    for i in range(len(paths)):
        if check_si_recuerda(paths[i],W,Perror)==0:
            return(0);break
    return(1)
    
def n_bits_dif(im1,im2): return(float( np.sum(np.abs((im1-im2)))*0.5) )

def p_error(original,out):
    ncells=original.size
    error=n_bits_dif(original,out)/float(ncells**2)
    return(error)

    
    
#--------------------------------------------------------------------#