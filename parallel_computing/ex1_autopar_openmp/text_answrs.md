# Automatic Parallelization/OpenMP

## Exercise 1

### Question 3

Why is clock() not useful as a timer in parallel programs?

This is not useful as it uses the number of clock cycles, which will generally be larger for parallel programs. 
The thing that is optimized is the wall time.