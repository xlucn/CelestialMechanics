#! /usr/bin/python
# -*- encoding=utf-8 -*-
'''
Plot the Poincare map(section) of a circular RTB(restricted three body problem)
'''
import numpy as np
import matplotlib.pyplot as plt


def linearIpl(a1, a2):
	k = (y0 - a2[2]) / (a1[2] - a2[2])
	return k * a1 + (1 - k) * a2

f = open('circularRTB.txt')
newdata = np.array(f.readline().split()).astype(float)
y0 = newdata[2]
cj = newdata[-1]

sec = []
while True:
	olddata = newdata
	newdata = np.array(f.readline().split()).astype(float)
	if len(newdata) == 0:
		break
	if olddata[2] < y0 and newdata[2] > y0:
		sec.append(linearIpl(olddata, newdata))
sec = np.array(sec).T
sec1 = sec[1]
sec2 = sec[4]
f.close()

fig = plt.figure()
plt.plot(sec1, sec2, '.')
plt.title('$Poincare\ Map\ at\ C_J=%f,y=%f,\dot{y}>0,\mu=0.001$' % (cj, y0))
plt.xlim(-2, -0.75)
plt.xlabel('$x$')
plt.ylabel('$dx/dt$')
plt.savefig('CRTBsection.png')
plt.close()
