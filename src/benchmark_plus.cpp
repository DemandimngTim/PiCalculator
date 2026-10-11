#include "pi.h"

#include <iostream>

using namespace std;

void run_benchmark_plus(long digits)
{
    cout << "Starting benchmark++ 🔥\n\n";

    // Warm-up
    cout << "Warm-up enabled ✅\n";
    cout << "Performing warm-up...\n";

    run_single_benchmark(digits, 1);

    cout << "Warm-up complete ✅\n\n";

    // Run benchmark with median reporting enabled.
    run_benchmark(digits, true);

    // Analysis report
    cout << "\nBenchmark++ analysis 🔥\n";
    cout << "Warm-up: enabled\n";
    cout << "Fastest run: enabled\n";
    cout << "Median timing: enabled\n";
    cout << "Outlier protection: enabled\n";
    cout << "Depth comparison: enabled\n";

    cout << "\nBenchmark++ complete 🔥\n";
}
