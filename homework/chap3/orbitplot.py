#! /usr/bin/python
# -*- encoding=utf-8 -*-
'''
Plot the orbit of circular restricted three-body problem
'''
import numpy as np
import matplotlib.pyplot as plt

file = 'circularRTB.txt'
data = [[float(i) for i in l.split()] for l in open(file).readlines()]
data = np.array(data).T
t, x, y=data[0], data[1], data[2]
orbits = int(t[-1]/np.pi/2+0.1)

steps = np.arange(len(x))
Cj = data[7]
plt.title('$C_J$'+' as function of time')
plt.xlabel('$time$')
plt.ylabel('$C_J$')
plt.ylim(Cj.min(),Cj.max())
plt.plot(steps,Cj)
plt.savefig('cj.png')


fig = plt.figure()
plt.title('orbit during %d periods' % orbits)
plt.xlabel('$x$')
plt.ylabel('$y$')
textx = x.max()*0.75+x.min()*0.25
texty = y.max()*0.6+y.min()*0.4
texts = '$\mu=0.001$\n$C_J=%.6f$\n$x_0=%.4f$\n$y_0=%.4f$\n$v_{x0}=%.4f$\n$v_{y0}=%.4f$' \
    % (Cj[0], x[0], y[0], data[4][0], data[5][0])
plt.text(textx,texty,texts,size=16)
plt.plot(x,y)
plt.savefig('orbit.png')

plt.close()
