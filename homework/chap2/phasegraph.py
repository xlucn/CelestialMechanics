#!/usr/bin/python
# -*- encoding=utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
data = [[float(i) for i in l.split()] for l in open('Sitnikov.txt').readlines()]
data = np.array(data).T
index = data[0]
indexes = [np.where(index==i)[0] for i in range(int(index[-1]))]

z, vz, cj = data[4], data[7], data[-1]

fig = plt.figure()
for i in range(len(indexes)):
    lo = int(indexes[i][0])
    hi = int(indexes[i][-1])+1
    plt.plot(z[lo:hi], vz[lo:hi],label='$C_J=%f$' % cj[lo])
plt.title('phase graph of Sitkinov problem')
plt.xlabel('$z$',size=17)
plt.ylabel('$dz/dt$',size=17)
plt.legend()
plt.savefig('phasegraph.png')
plt.close()
