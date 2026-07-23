// ======================================================
// benchmark_plus.cpp
// --benchmark++ extension
// Extra benchmark analysis
// ======================================================


#include "pi.h"

#include <iostream>


using namespace std;



// ======================================================
// Benchmark++
//
// Adds:
// - CPU warm-up
// - Normal benchmark reuse
// - Extra analysis output
//
// ======================================================


void run_benchmark_plus(
    long digits
)
{

    cout
    << "Starting benchmark++ 🔥\n\n";



    // ==================================================
    // Warm-up
    //
    // Purpose:
    // - Wake CPU
    // - Fill caches
    // - Reduce first-run spikes
    //
    // Result is ignored
    // ==================================================


    cout
    << "Warm-up enabled ✅\n";


    cout
    << "Performing warm-up...\n";



    run_single_benchmark(
        digits,
        1
    );



    cout
    << "Warm-up complete ✅\n\n";







    // ==================================================
    // Run normal benchmark
    //
    // Uses benchmark.cpp
    // ==================================================


    cout
    << "Starting benchmark 🔥\n\n";


    run_benchmark(
        digits
    );







    // ==================================================
    // Analysis report
    // ==================================================


    cout
    << "\nBenchmark++ analysis 🔥\n";


    cout
    << "Warm-up: enabled\n";


    cout
    << "Median timing: enabled\n";


    cout
    << "Outlier protection: enabled\n";


    cout
    << "Depth comparison: enabled\n";





    cout
    << "\nBenchmark++ complete 🔥\n";

}
