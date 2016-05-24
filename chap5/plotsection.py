#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt

with open('SpinOrbitResonance.txt') as f:
    data = np.array([[float(i) for i in l.split()] for l in f.readlines()])
    theta, dtheta = data.T[1:3]

    fig = plt.figure()
    plt.ylim((dtheta.min(), dtheta.max()))
    plt.xlim((theta.min(), theta.max()))
    plt.plot(theta, dtheta, '.')
    plt.savefig('poincaresection.png')

