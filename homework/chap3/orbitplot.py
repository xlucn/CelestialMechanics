#! /usr/bin/python
# -*- encoding=utf-8 -*-
'''
Plot the orbit of circular restricted three-body problem
'''
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

'''
Read the data file
'''
datafile = 'circularRTB.txt'
data = [[float(i) for i in l.split()] for l in open(datafile).readlines()]
data = np.array(data).T
t, x, y, z=data[0], data[1], data[2], data[3]
steps = np.arange(len(x))
Cj = data[7]

'''
Read the parameters file
'''
parafile = 'circularRTBpara.txt'
para = dict(l.split() for l in open(parafile).readlines())
time = float(para['b']) - float(para['a'])
periods = time/np.pi/2
mu = para['mu']
tol = para['TOL']

'''
Plot the CJ(Jacobi Integral) as a function of time
'''
fig1 = plt.figure()
plt.title('$C_J$'+' as function of time')
plt.xlabel('$time$')
plt.ylabel('$C_J$')
plt.ylim(Cj.min(),Cj.max())
plt.plot(steps,Cj)
plt.savefig('cj.png')
plt.close()

'''
Plot the orbit in x-y plane
'''
fig2 = plt.figure()
plt.title('orbit during %d periods' % periods)
plt.xlabel('$x$')
plt.ylabel('$y$')
textx = x.max()*0.75+x.min()*0.25
texty = y.max()*0.6+y.min()*0.4
texts = '$\mu=%s$\n$C_J=%.6f$\n$x_0=%.4f$\n$y_0=%.4f$\n$v_{x0}=%.4f$\n$v_{y0}=%.4f$' \
    % (mu, Cj[0], x[0], y[0], data[4][0], data[5][0])
plt.text(textx,texty,texts,size=16)
plt.plot(x,y)
plt.savefig('orbit.png')

plt.close()

'''
plot 3d
'''
# 3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')
ax.set_xlim(-1.2, 1.2)
ax.set_ylim(-1.2, 1.2)
ax.set_zlim(-1.2, 1.2)
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('3D plot of circular restricted three-body problem')
ax.plot(x, y, z)
# plt.show()
plt.savefig('orbit3d.png')
plt.close()
