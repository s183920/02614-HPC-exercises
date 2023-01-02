import numpy as np
from time import time

print_matrices = True

def experiment(m, n):
    t0 = time()    

    A = np.zeros((m,n))
    b = np.zeros((n))

    # create matrices

    for l in range(n):
        b[l] = 3*l
        for k in range(m):
            A[k,l] = 1*k+l
            

    # print matrices
    if print_matrices:
        print("A = ")
        print(A)

        print("b = ")
        print(b)

    # C = A+B
    c = A@b

    # print C
    if print_matrices:
        print("c = ")
        print(c)

    t1 = time()

    return t1-t0

if __name__ == "__main__":
    if print_matrices:
        m,n = 10, 10
        experiment(m, n)
    else:
        m,n = 1000, 1000
        num_runs = 10
        times = 0
        for i in range(num_runs):
            times += experiment(m, n) / num_runs
        print(f"m = {m} \t n = {n} \t CPU time = {times*1e3:.20f} ms")