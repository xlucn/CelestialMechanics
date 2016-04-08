#!/usr/bin/python
# -*- encoding=utf-8 -*-
'''
Plot the phase diagram of Sitnikov problems in circular and ellipse orbits
'''
import numpy as np
import matplotlib.pyplot as plt

datafile = ['CircularSitnikov.txt', 'EllipticSitnikov.txt']


for orbit in [0, 1]:
    data = [[float(i) for i in l.split()] for l in open(datafile[orbit]).readlines()]
    data = np.array(data).T
    index = data[0]
    indexes = [np.where(index==i)[0] for i in range(int(index[-1])+1)]

    z, vz = data[2], data[3]

    fig = plt.figure()
    for i in range(len(indexes)):
        lo = int(indexes[i][0])
        hi = int(indexes[i][-1])+1
        if orbit == 0:
            plt.plot(z[lo:hi], vz[lo:hi],label='$C_J=%f$' % data[-1][lo])
        else:
            plt.plot(z[lo:hi], vz[lo:hi])
    plt.title('phase diagram of Sitkinov problem')
    plt.xlabel('$z$',size=17)
    plt.ylabel('$dz/dt$',size=17)
    # plt.xlim(-5,5)
    if orbit == 0:
        plt.legend()
    plt.savefig(datafile[orbit][:-3]+'png')
    plt.close()
