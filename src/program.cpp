// ======================================================
// program.cpp
// Normal π calculation pipeline
// ======================================================

#include "pi.h"

#include <iostream>
#include <chrono>


using namespace std;



int run_program(
    int argc,
    char **argv
)
{

    auto total_start =
        chrono::high_resolution_clock::now();



    if(argc < 2)
    {

        cout
        << "Usage: ./pi digits [depth]\n";

        return 1;

    }





    // ==================================================
    // Parse arguments
    // ==================================================


    DIGITS =
        atol(argv[1]);



    if(argc > 2)
    {

        MAX_TREE_DEPTH =
            atoi(argv[2]);

    }



    if(MAX_TREE_DEPTH > 8)
    {

        cout
        << "Tree depth limited to 8\n";


        MAX_TREE_DEPTH = 8;

    }






    long terms =
        DIGITS / 14 + 2;






    cout
    << "Starting GMP+MPFR Optimized Chudnovsky π 🔥\n\n";


    cout
    << "Digits: "
    << DIGITS
    << "\n";


    cout
    << "Tree depth: "
    << MAX_TREE_DEPTH
    << "\n";


    cout
    << "Terms needed: "
    << terms
    << "\n\n";






    // ==================================================
    // Binary split
    // ==================================================


    BS result;

    bs_init(
        result
    );



    cout
    << "Calculating π:\n";



    auto calc_start =
        chrono::high_resolution_clock::now();



    calculate_chudnovsky(
        terms,
        result
    );



    auto calc_end =
        chrono::high_resolution_clock::now();



    cout
    << "Calculation time: "
    << elapsed(
        calc_start,
        calc_end
    )
    << "s\n\n";







    // ==================================================
    // MPFR conversion
    // ==================================================


    cout
    << "Calculating π with MPFR...\n";



    mpfr_t pi;

    mpfr_init(
        pi
    );



    auto mpfr_start =
        chrono::high_resolution_clock::now();



    calculate_pi_mpfr(
        result,
        pi,
        DIGITS
    );



    auto mpfr_end =
        chrono::high_resolution_clock::now();



    cout
    << "MPFR time: "
    << elapsed(
        mpfr_start,
        mpfr_end
    )
    << "s\n\n";







    // ==================================================
    // Save output
    // ==================================================


    if(NO_SAVE)
    {

        cout
        << "Saving disabled ⏭️\n";

    }
    else
    {

        save_pi(
            pi,
            DIGITS
        );

    }







    // ==================================================
    // Cleanup
    // ==================================================


    mpfr_clear(
        pi
    );


    bs_clear(
        result
    );







    auto total_end =
        chrono::high_resolution_clock::now();





    cout
    << "\n====================\n";


    cout
    << "Finished 🔥\n";


    cout
    << "Total time: "
    << elapsed(
        total_start,
        total_end
    )
    << "s\n";



    return 0;

}
