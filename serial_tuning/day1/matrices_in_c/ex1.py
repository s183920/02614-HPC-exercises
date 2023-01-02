import numpy as np
from time import time


print_matrices = False


def experiment(m, n):
    t0 = time()
    A = np.zeros((m,n))
    B = np.zeros((m,n))

    # create matrices
    for k in range(m):
        for l in range(n):
            A[k,l] = 1*k+l
            B[k,l] = 2*k+l

    # print matrices
    if print_matrices:
        print("A = ")
        print(A)

        print("B = ")
        print(B)

    # C = A+B
    C = A+B

    # print C
    if print_matrices:
        print("C = ")
        print(C)

    t1 = time()
    return t1-t0

if __name__ == "__main__":
    m,n = 1000, 1000
    num_runs = 10
    if print_matrices:
        experiment(m, n)
    else:
        times = 0
        for i in range(num_runs):
            times += experiment(m, n) / num_runs
        print(f"m = {m} \t n = {n} \t CPU time = {times*1e3:.20f} ms")