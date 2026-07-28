// ======================================================
// program.cpp
// Normal π calculation pipeline
// ======================================================

#include "pi.h"

#include "profiles/profile_runtime.h"
#include "profiles/profile_loader.h"
#include "profiles/active_profile.h"

#include <iostream>
#include <chrono>
#include <string>


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
        << "Usage:\n";
        cout
        << "./pi digits\n";
        cout
        << "./pi --profile-use name digits\n";

        return 1;
    }



    int digit_argument = 1;



    // ==================================================
    // Optional profile loading
    // ==================================================

    if(string(argv[1]) == "--profile-use")
    {

        if(argc < 4)
        {
            cout
            << "Usage: ./pi --profile-use name digits\n";

            return 1;
        }



        string profile_name =
            argv[2];



        string profile_path =
            "profiles/" +
            profile_name +
            ".profile";



        if(!load_profile(
            ACTIVE_PROFILE,
            profile_path
        ))
        {
            cout
            << "Profile not found ❌\n";

            return 1;
        }



        PROFILE_LOADED = true;



        cout
        << "Using profile: "
        << ACTIVE_PROFILE.name
        << "\n\n";



        digit_argument = 3;
    }



    // ==================================================
    // Parse digits
    // ==================================================

    DIGITS =
        parse_digits(
            argv[digit_argument]
        );



    // ==================================================
    // Apply profile settings
    // ==================================================

    if(PROFILE_LOADED)
    {

        MAX_TREE_DEPTH =
            ACTIVE_PROFILE.tree_depth;


        NO_SAVE =
            !ACTIVE_PROFILE.save_output;

    }
    else if(argc > digit_argument + 1)
    {

        MAX_TREE_DEPTH =
            atoi(
                argv[digit_argument + 1]
            );

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
