import numpy as np
from time import time
import matplotlib.pyplot as plt

N = np.linspace(100, 5000, 10, dtype=int)


times = np.zeros(len(N))
for i, n in enumerate(N):
    A = np.ones((n, n))
    t0 = time()
    B = np.dot(A, A)

    dt = time() - t0

    times[i] = dt


plt.plot(N, times)
plt.xlabel("Matrix size")
plt.ylabel("Time [s]")
plt.show()
    
# else:
#     print("Matrix size: %d x %d" % (n, n))
#     print("Time: %f s" % dt)

