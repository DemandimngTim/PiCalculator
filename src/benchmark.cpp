// ======================================================
// benchmark.cpp
// --benchmark system
// ======================================================


#include "pi.h"

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



// ======================================================
// Run one benchmark
// ======================================================


double run_single_benchmark(
    long digits,
    int depth
)
{

    DIGITS =
        digits;


    MAX_TREE_DEPTH =
        depth;



    BS result;

    bs_init(
        result
    );



    long terms =
        DIGITS / 14 + 2;



    auto start =
        chrono::high_resolution_clock::now();



    calculate_chudnovsky(
        terms,
        result
    );



    auto end =
        chrono::high_resolution_clock::now();



    double time =
        elapsed(
            start,
            end
        );



    bs_clear(
        result
    );



    return time;

}







// ======================================================
// Median helper
// ======================================================


double median(
    vector<double> values
)
{

    sort(
        values.begin(),
        values.end()
    );


    return values[
        values.size() / 2
    ];

}







// ======================================================
// Main benchmark command
// ======================================================


void run_benchmark(
    long digits
)
{

    vector<int> depths =
    {
        0,
        1,
        2,
        3,
        4
    };



    double best_time =
        999999;


    int best_depth =
        0;




    cout
    << "Starting benchmark 🔥\n\n";





    for(int depth : depths)
    {

        cout
        << "Testing depth "
        << depth
        << "...\n\n";



        vector<double> results;





        for(int run = 1; run <= 3; run++)
        {

            double time =
                run_single_benchmark(
                    digits,
                    depth
                );



            results.push_back(
                time
            );



            cout
            << "Run "
            << run
            << ": "
            << time
            << "s\n";

        }





        double med =
            median(
                results
            );



        cout
        << "Median: "
        << med
        << "s\n\n";






        if(med < best_time)
        {

            best_time =
                med;


            best_depth =
                depth;

        }

    }







    cout
    << "====================\n";


    cout
    << "Best depth: "
    << best_depth
    << " 🔥\n";


    cout
    << "Median time: "
    << best_time
    << "s\n";


    cout
    << "====================\n";

}
