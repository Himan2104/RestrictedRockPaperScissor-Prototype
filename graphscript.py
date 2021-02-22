import numpy  as np
import matplotlib.pyplot as plt
import sys

data = np.loadtxt('graph.txt')

plt.title("RRPS - Round vs Cumulative Score for P1 and P2")

y1 = data[:, 0]
y2 = data[:, 1]

x = np.empty(len(y1))
x = np.arange(1, len(y1)+1)

plt.plot(x, y1, label = "P1", c = 'r')
plt.plot(x, y2, label = "P2", c = 'b')
plt.legend()
plt.show()