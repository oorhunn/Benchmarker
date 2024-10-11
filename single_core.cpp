// main.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int main() {
    const size_t N = 10000000;
    std::vector<int> data(N);

    // Fill with random data
    std::generate(data.begin(), data.end(), rand);

    // Measure sorting time
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(data.begin(), data.end());
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Sorting duration: " << duration.count() << " seconds\n";
    return 0;
}
