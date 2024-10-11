# Benchmarker


time g++ -O3 single_core.cpp -o benchmark
workstation:
    real	0m0,432s
    user	0m0,383s
    sys	0m0,054s

mac m2-pro:
    0.25s user 0.15s system 5% cpu 7.464 total


time ./benchmark

Sorting duration: 0.689638 seconds
workstation:
    real	0m0,857s
    user	0m0,828s
    sys	0m0,034s

mac m2-pro:
    Sorting duration: 0.579787 seconds
    ./benchmark  0.67s user 0.01s system 18% cpu 3.731 total

time g++ -O3 -std=c++11 matrix_multiplication.cpp -o matrix_mult -pthread

workstation:
    real    0m0,408s
    user    0m0,355s
    sys     0m0,045s

mac m2-pro:
    0.31s user 0.21s system 87% cpu 0.597 total


time ./matrix_mult
Matrix multiplication duration: 0.263056 seconds

workstation:
    real	0m0,281s
    user	0m4,450s
    sys	0m0,019s

mac m2-pro:
    Matrix multiplication duration: 0.180027 seconds
    ./matrix_mult  1.95s user 0.01s system 556% cpu 0.353 total