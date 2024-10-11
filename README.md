# Benchmarker


time g++ -O3 single_core.cpp -o benchmark
workstation:
    real	0m0,432s
    user	0m0,383s
    sys	0m0,054s


time ./benchmark

Sorting duration: 0.689638 seconds
workstation:
    real	0m0,857s
    user	0m0,828s
    sys	0m0,034s


time g++ -O3 -std=c++11 matrix_multiplication.cpp -o matrix_mult -pthread

workstation:
    real    0m0,408s
    user    0m0,355s
    sys     0m0,045s


time ./matrix_mult
Matrix multiplication duration: 0.263056 seconds

workstation:
    real	0m0,281s
    user	0m4,450s
    sys	0m0,019s