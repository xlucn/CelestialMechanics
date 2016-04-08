#! /usr/bin/python
# -*- encoding=utf-8 -*-
'''
Plot the Poincare map(section) of a circular RTB(restricted three body problem)
'''
import numpy as np
import matplotlib.pyplot as plt

data = [l.split() for l in open('circularRTBtot.txt').readlines()]
data = np.array(data).T.astype(float)
y = data[2]

sec = [[],[],[],[],[],[]]
for i in range(len(y) - 1):
	if y[i] < 0 and y[i + 1] > 0:
		for j in range(6):
			sec[j].append((y[i+1]*data[j+1][i]-y[i]*data[j+1][i+1])/(y[i + 1]-y[i]))
sec1 = np.array(sec[0])
sec2 = np.array(sec[3])


fig = plt.figure()
plt.plot(sec1, sec2, '.')
plt.xlim(0,1)
plt.savefig('CRTBsection.png')
plt.close()
