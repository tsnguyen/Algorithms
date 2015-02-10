#import os
#os.chdir("C:/Users/thanhson/Documents/GitHub/Algorithms/programs")

import numpy as np
import matplotlib.pyplot as plt

f = open('tmp/percolation.csv')

size = int(f.readline().strip())
data = []
for line in f:
    data.append(int(line.strip()))

histogram = np.zeros(size)
for i in data:
    histogram[i] += 1.0

histogram = histogram / len(data)
x = np.array(range(size)) * 1.0 / size

plt.plot(x, histogram.cumsum())
plt.show()