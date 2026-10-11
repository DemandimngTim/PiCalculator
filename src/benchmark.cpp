#include "pi.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Run one benchmark
double run_single_benchmark(long digits, int depth)
{
    DIGITS = digits;
    MAX_TREE_DEPTH = depth;

    BS result;
    bs_init(result);

    long terms = DIGITS / 14 + 2;

    auto start = chrono::high_resolution_clock::now();
    calculate_chudnovsky(terms, result);
    auto end = chrono::high_resolution_clock::now();

    double time = elapsed(start, end);

    bs_clear(result);
    return time;
}

// Median helper
double median(vector<double> values)
{
    sort(values.begin(), values.end());

    if (values.size() % 2 != 0)
        return values[values.size() / 2];

    return (values[values.size() / 2 - 1]
          + values[values.size() / 2]) / 2.0;
}

// show_median is true for --benchmark++.
void run_benchmark(long digits, bool show_median)
{
    const vector<int> depths = {0, 1, 2, 3, 4};

    double best_fastest_time = numeric_limits<double>::infinity();
    double best_depth_median = 0.0;
    int best_depth = 0;

    cout << "Starting benchmark 🔥\n\n";
    cout << fixed << setprecision(6);

    for (int depth : depths)
    {
        cout << "Testing depth " << depth << "...\n\n";

        vector<double> results;
        results.reserve(3);

        double fastest_time = numeric_limits<double>::infinity();
        int fastest_run = 0;

        for (int run = 1; run <= 3; ++run)
        {
            double time = run_single_benchmark(digits, depth);
            results.push_back(time);

            cout << "Run " << run << ": " << time << "s\n";

            if (time < fastest_time)
            {
                fastest_time = time;
                fastest_run = run;
            }
        }

        cout << "Fastest run: Run " << fastest_run
             << " (" << fastest_time << "s)\n";

        vector<double> valid_results = results;
        int discarded_run = -1;

        // Only apply outlier protection in benchmark++.
        if (show_median)
        {
            for (size_t i = 0; i < results.size(); ++i)
            {
                bool outlier = true;

                for (size_t j = 0; j < results.size(); ++j)
                {
                    if (i == j)
                        continue;

                    if (results[i] - results[j] < 2.0)
                    {
                        outlier = false;
                        break;
                    }
                }

                if (outlier)
                {
                    discarded_run = static_cast<int>(i);
                    break;
                }
            }
        }

        if (discarded_run >= 0)
        {
            cout << "Outlier protection: discarded Run "
                 << discarded_run + 1 << " (" 
                 << results[discarded_run]
                 << "s; at least 2.000s slower than both other runs)\n";

            valid_results.erase(valid_results.begin() + discarded_run);
        }

        double med = median(valid_results);

        if (show_median)
            cout << "Median: " << med << "s\n";

        cout << '\n';

        // Select the best depth by its fastest measured run.
        if (fastest_time < best_fastest_time)
        {
            best_fastest_time = fastest_time;
            best_depth_median = med;
            best_depth = depth;
        }
    }

    cout << "====================\n";
    cout << "Best depth: " << best_depth << " 🔥\n";
    cout << "Fastest time: " << best_fastest_time << "s\n";

    if (show_median)
        cout << "Median time: " << best_depth_median << "s\n";

    cout << "====================\n";
}
