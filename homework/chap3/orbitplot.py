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
x,y=data[1],data[2]


steps = np.arange(len(x))
Cj = data[7]
plt.title('$C_J$'+' as function of time')
plt.xlabel('$time$')
plt.ylabel('$C_J$')
plt.ylim(Cj.min(),Cj.max())
plt.plot(steps,Cj)
plt.savefig('cj.png')


fig = plt.figure()
plt.title('orbit during 20 periods')
plt.xlabel('$x$')
plt.ylabel('$y$')
plt.text(x.max()*0.75+x.min()*0.25,y.max()*0.75+y.min()*0.25,'$\mu=0.01$\n$C_J=%.4f$' % Cj[0],size=20)
plt.plot(x,y)
plt.savefig('orbit.png')

plt.close()
