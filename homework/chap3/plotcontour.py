#! /usr/bin/python
# -*- encoding=utf-8 -*-
'''
Plot the contour map of C_J circular restricted three-body problem
'''
import numpy as np
import matplotlib.pyplot as plt

axs = plt.subplot()

mu = 0.1
xs = np.linspace(-2,2,400)
X, Y = np.meshgrid(xs, xs)

def Cj(x, y):
    r1 = np.sqrt((x + mu)**2 + y**2)
    r2 = np.sqrt((x + mu - 1)**2 + y**2)
    omega = (x*x+y*y)/2+(1-mu)/r1+mu/r2
    return 2 * omega

zdata = Cj(X, Y)
levels = np.linspace(2.8, 3.7, 400)
cs = axs.contour(X, Y, zdata, levels=levels)
plt.title('$C_J\ contour\ at\ \mu=0.1$')
plt.colorbar(cs, ax=axs, format="%.2f")

plt.savefig('contour.png')
plt.close()
