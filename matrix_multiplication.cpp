// matrix_multiplication.cpp
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

// Function to multiply a portion of the matrix
void multiply_portion(const std::vector<std::vector<int>>& A, 
                      const std::vector<std::vector<int>>& B, 
                      std::vector<std::vector<int>>& C, 
                      int start_row, int end_row) {
    int N = A.size();
    for (int i = start_row; i < end_row; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    const int N = 1000; // Matrix size
    const int num_threads = std::thread::hardware_concurrency();

    // Initialize matrices with random values
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(N, 2));
    std::vector<std::vector<int>> C(N, std::vector<int>(N, 0));

    // Calculate rows per thread
    int rows_per_thread = N / num_threads;

    std::vector<std::thread> threads;
    auto start = std::chrono::high_resolution_clock::now();

    // Launch threads
    for (int i = 0; i < num_threads; ++i) {
        int start_row = i * rows_per_thread;
        int end_row = (i == num_threads - 1) ? N : (i + 1) * rows_per_thread;
        threads.emplace_back(multiply_portion, std::ref(A), std::ref(B), std::ref(C), start_row, end_row);
    }

    // Join threads
    for (auto& th : threads) {
        th.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Matrix multiplication duration: " << duration.count() << " seconds\n";

    return 0;
}
