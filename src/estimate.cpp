// ======================================================
// estimate.cpp
// --estimate system
// Device + π calculation estimator
// ======================================================


#include "pi.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <sys/sysinfo.h>


using namespace std;



// ======================================================
// Convert bytes into readable format
// ======================================================


string format_bytes(
    unsigned long long bytes
)
{

    const char *units[] =
    {
        "B",
        "KB",
        "MB",
        "GB",
        "TB",
        "PB"
    };



    double size =
        bytes;


    int unit = 0;



    while(
        size >= 1024 &&
        unit < 5
    )
    {

        size /= 1024;
        unit++;

    }



    stringstream ss;


    ss
    << fixed
    << setprecision(2)
    << size
    << " "
    << units[unit];


    return ss.str();

}







// ======================================================
// Detect RAM
// ======================================================


unsigned long long get_ram()
{

    struct sysinfo info;



    if(sysinfo(&info) == 0)
    {

        return
            (unsigned long long)
            info.totalram *
            info.mem_unit;

    }



    return 0;

}







// ======================================================
// Time estimation
//
// Based on benchmark data:
//
// 5M digits ≈ 4.1 seconds
//
// Future:
// Replace with benchmark database
//
// ======================================================


double estimate_time(
    long digits
)
{

    double base_digits =
        5000000.0;


    double base_time =
        4.1;



    double ratio =
        digits /
        base_digits;



    return
        base_time *
        pow(
            ratio,
            1.10
        );

}







// ======================================================
// --estimate command
// ======================================================


void run_estimate(
    int argc,
    char **argv
)
{

    if(argc < 3)
    {

        cout
        << "Usage:\n";


        cout
        << "./pi --estimate digits\n";


        return;

    }





    long digits =
        parse_digits(
            argv[2]
        );







    cout
    << "π Calculation Estimate 🔥\n\n";



    cout
    << "Target digits: "
    << digits
    << "\n\n";







    // ==================================================
    // Storage
    // ==================================================


    unsigned long long output_size =
        digits;



    cout
    << "Storage needed:\n";


    cout
    << "π text file: "
    << format_bytes(
        output_size
    )
    << "\n\n";







    // ==================================================
    // RAM
    // ==================================================


    unsigned long long ram =
        get_ram();



    cout
    << "Device RAM:\n";



    if(ram)
    {

        cout
        << format_bytes(
            ram
        )
        << "\n";

    }
    else
    {

        cout
        << "Unknown\n";

    }



    cout
    << "\n";






    unsigned long long estimated_ram =
        digits * 2;



    cout
    << "Estimated calculation RAM:\n";


    cout
    << format_bytes(
        estimated_ram
    )
    << "\n\n";







    // ==================================================
    // Time
    // ==================================================


    double seconds =
        estimate_time(
            digits
        );



    cout
    << "Estimated calculation time:\n";



    if(seconds < 60)
    {

        cout
        << seconds
        << " seconds\n";

    }
    else if(seconds < 3600)
    {

        cout
        << seconds / 60
        << " minutes\n";

    }
    else if(seconds < 86400)
    {

        cout
        << seconds / 3600
        << " hours\n";

    }
    else
    {

        cout
        << seconds / 86400
        << " days\n";

    }







    // ==================================================
    // Warnings
    // ==================================================


    cout
    << "\n";



    if(
        ram &&
        estimated_ram > ram
    )
    {

        cout
        << "⚠️ Warning: Estimated RAM exceeds device RAM\n";

    }





    if(
        output_size > 100000000000ULL
    )
    {

        cout
        << "⚠️ Warning: Output file is extremely large\n";

    }






    cout
    << "\n====================\n";


    cout
    << "Estimate complete 🔥\n";

}
