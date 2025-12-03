#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

// Iterative
long long fib_iterative(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    long long a = 1;
    long long b = 2;

    for (int index = 3; index <= n; index++) {
        long long next = a + b;
        a = b;
        b = next;
    }

    return b;
}

// Recursive
long long fib_recursive(int n) {
    if (n <= 2) {
        if (n == 1)
            return 1;
        else
            return 2;
    }

    return fib_recursive(n - 1) + fib_recursive(n - 2);
}


int main() {
    cout << "Fibonacci Performance Comparison\n";
    cout << "=================================\n\n";
    
    int tests[] = {10, 20, 30, 35, 40, 45, 50, 55};
    
    cout << setw(4) << "F(n)" << setw(17) << "Iterative" << setw(15) << "Recursive" << endl;
    cout << string(36, '-') << endl;
    
    for (int n : tests) {
        // Iterative time
        auto start = high_resolution_clock::now();
        long long result = fib_iterative(n);
        auto stop = high_resolution_clock::now();
        long long iter_time = duration_cast<microseconds>(stop - start).count();
        
        // Recursive Time
        long long rec_time = 0;
        if (n <= 55) {
            start = high_resolution_clock::now();
            fib_recursive(n);
            stop = high_resolution_clock::now();
            rec_time = duration_cast<microseconds>(stop - start).count();
        }
        
        // Print results
        cout << "F(" << setw(2) << n << ")" << setw(12) << iter_time << " μs";
        if (n <= 55)
            cout << setw(12) << rec_time << " μs\n";
    }  
    return 0;
}