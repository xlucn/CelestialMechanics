import matplotlib.pyplot as plt
import numpy as np

def readpara(parafile):
    '''
    read the corresponding parameters in the file parafile.
    '''
    data = np.loadtxt(parafile).T
    return data[0], data[1], data[2], data[5]

def plotpara(para, t, paraname):
    '''
    plot the parameter para as a function of time t and
    save the picture as filename
    '''
    fig = plt.figure(1)
    plt.plot(para, t)
    plt.xlabel('time/period')
    plt.ylabel(paraname)
    plt.savefig('Perturbation_' + paraname + '.png')
    plt.close(1)

def main():
    t, a, e, omega = readpara('Perturbation.txt')
    plotpara(t, a, 'a')
    plotpara(t, e, 'e')
    plotpara(t, omega, 'omega')
    pass

if __name__ == '__main__':
    main()
