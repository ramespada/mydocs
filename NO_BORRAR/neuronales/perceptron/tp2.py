import numpy as np
from matplotlib import pyplot as plt
#import sys,os
#os.chdir("/home/ram/Desktop/tp2/")

def main():
    eta=1 #tasa de aprendizaje    
    W=np.random.rand(3)
    
    error=1
    while error != 0 :
        Ei=np.sign(np.random.rand(3)-np.random.rand(3))
        Ei[0]=1
        
        #sd=sd_AND(Ei[1],Ei[2])
        sd=sd_OR(Ei[1],Ei[2])  
        
        s=np.sign(np.dot(W,Ei))
        
        dW=eta*(sd-s)*Ei   
        W+=dW
      
        error=ECM(W)
        
    return(W)

#FUNCIONES AUXILIARES:
def ECM(W):
    v1=(1,-1,-1,-1)
    v2=(np.sign( np.dot(W,(1,1,1))), np.sign(np.dot(W,(1,-1,1))) ,np.sign( np.dot(W,(1,1,-1))) , np.sign(np.dot(W,(1,-1,-1))) )
    v2=floor(v2)
    return(np.sum((v1-v2)*(v1-v2)))

def sd_AND(a,b):
    if (a==1):
        if (b==1):
            return(1)
        else:
            return(-1)
    else:
        return(-1)

def sd_OR(a,b):
    if(a!=1):
        if(b!=1):
            return(-1)
        else:
            return(1)
    else:
        return(1)
        
def check_AND(ww):
    print(np.sign(np.dot(ww,(1,1,1))) == 1)
    print(np.sign(np.dot(ww,(1,-1,1)))==-1)
    print(np.sign(np.dot(ww,(1,1,-1)))==-1)
    print(np.sign(np.dot(ww,(1,-1,-1)))==-1)
    
def check_OR(ww):
    print(np.sign(np.dot(ww,(1,1,1))) ==1)
    print(np.sign(np.dot(ww,(1,-1,1)))==1)
    print(np.sign(np.dot(ww,(1,1,-1)))==1)
    print(np.sign(np.dot(ww,(1,-1,-1)))==-1)

def plotPlano(ww):
    x=np.linspace(-10,10,5)
    y=(-ww[1]*x-ww[0])/float(ww[2])
    plt.plot(x,y);plt.xlim(-2,2);plt.ylim(-2,2)
    plt.show()
