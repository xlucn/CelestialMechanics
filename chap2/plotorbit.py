#! /usr/bin/python
# -*- encoding=utf-8 -*-
'''
Plot the otbit of two-body motion
'''
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

AU=1.49597870691e11
raw = [l.split() for l in open('evaluate.txt').readlines()]
data = np.array(raw).T[1:4].astype(float)/AU

# 3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')
ax.set_xlim(-1.2, 1.2)
ax.set_ylim(-1.2, 1.2)
ax.set_zlim(-1.2, 1.2)
ax.set_xlabel('x/AU')
ax.set_ylabel('y/AU')
ax.set_zlabel('z/AU')
ax.set_title('3D plot of two-body motion during 2 orbits')
ax.plot(data[0],data[1],zs=data[2])
plt.savefig('TwobodyOrbit3d.png')
plt.close()

# 2d plot
fig = plt.figure(figsize=(8, 8))
plt.xlim(-1.2, 1.2)
plt.ylim(-1.2, 1.2)
plt.xlabel('x/AU')
plt.ylabel('y/AU')
plt.title('2D plot of two-body motion during 2 orbits')
plt.plot(data[0],data[1])
plt.savefig('TwobodyOrbit2d.png')
plt.close()
