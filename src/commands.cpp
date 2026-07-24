// ======================================================
// commands.cpp
// Command router for all -- functions
// ======================================================

#include "pi.h"
#include "commands.h"

#include <iostream>
#include <string>


using namespace std;



// ======================================================
// Command declarations
// Implemented in other .cpp files
// ======================================================

void show_version();

void run_benchmark(
    long digits
);


void run_benchmark_plus(
    long digits
);


void run_estimate(
    int argc,
    char **argv
);


void run_no_save(
    int argc,
    char **argv
);


void run_speedtest();


void run_stress(
    int argc,
    char **argv
);


void run_memory();

void run_verify(
    int argc,
    char **argv
);

void run_verify_plus(
    int argc,
    char **argv
);


void run_profile_save(
    int argc,
    char **argv
);


void run_profile(
    int argc,
    char **argv
);


void run_profile_list();


void run_auto(
    int argc,
    char **argv
);


void run_mpmath(
    int argc,
    char **argv
);



// ======================================================
// Main command router
//
// Returns:
// 1  = command handled
// 0  = normal calculation
// ======================================================


int run_command(
    int argc,
    char **argv
)
{

    if(argc < 2)
        return 0;



    string command =
        argv[1];




    // --------------------------------------------------
    // Benchmark
    // --------------------------------------------------


    if(command == "--benchmark")
    {

        if(argc < 3)
        {

            cout
            << "Usage: ./pi --benchmark digits\n";

            return 1;

        }


        run_benchmark(
            parse_digits(argv[2])
        );


        return 1;

    }





    if(command == "--benchmark++")
    {

        if(argc < 3)
        {

            cout
            << "Usage: ./pi --benchmark++ digits\n";

            return 1;

        }


        run_benchmark_plus(
            parse_digits(argv[2])
        );


        return 1;

    }





    // --------------------------------------------------
    // Calculation options
    // --------------------------------------------------


    if(command == "--estimate")
    {

        run_estimate(
            argc,
            argv
        );


        return 1;

    }





    if(command == "--no-save")
    {

        run_no_save(
            argc,
            argv
        );


        return 1;

    }





    // --------------------------------------------------
    // System tools
    // --------------------------------------------------


    if(command == "--speedtest")
    {

        run_speedtest();

        return 1;

    }





    if(command == "--memory")
    {

        run_memory();

        return 1;

    }





    if(command == "--stress")
    {

        run_stress(
            argc,
            argv
        );


        return 1;

    }


    if(string(argv[1]) == "--version")
{
    show_version();
    return 0;
}


    // --------------------------------------------------
    // Verification
    // --------------------------------------------------

    if(command == "--verify")
{
    run_verify(
        argc,
        argv
    );

    return 1;
}
    if(command == "--verify++")
    {

        run_verify_plus(
            argc,
            argv
        );


        return 1;

    }





    // --------------------------------------------------
    // Profiles
    // --------------------------------------------------


    if(command == "--profile-save")
    {

        run_profile_save(
            argc,
            argv
        );


        return 1;

    }





    if(command == "--profile")
    {

        run_profile(
            argc,
            argv
        );


        return 1;

    }





    if(command == "--profile-list")
    {

        run_profile_list();

        return 1;

    }





    // --------------------------------------------------
    // Automation
    // --------------------------------------------------


    if(command == "--auto")
    {

        run_auto(
            argc,
            argv
        );


        return 1;

    }





    // --------------------------------------------------
    // Alternative calculators
    // --------------------------------------------------


    if(command == "--mpmath")
    {

        run_mpmath(
            argc,
            argv
        );


        return 1;

    }





    // Unknown command
    // Let normal parser handle it
    // --------------------------------------------------


    return 0;

}
