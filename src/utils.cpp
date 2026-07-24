// ======================================================
// utils.cpp
// Shared utilities + global settings
// ======================================================


#include "pi.h"

#include <exception>
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sched.h>
#include <algorithm>
#include <cctype>

long long parse_digits(
    const std::string &text
)
{

    if(text.empty())
{
    std::cerr
    << "Invalid digit count ❌\n";

    std::exit(EXIT_FAILURE);
}


    std::string value =
        text;


    // -----------------------------------------
    // Remove commas and underscores
    // -----------------------------------------

    value.erase(
        remove(
            value.begin(),
            value.end(),
            ','
        ),
        value.end()
    );

    value.erase(
        remove(
            value.begin(),
            value.end(),
            '_'
        ),
        value.end()
    );


    char suffix =
        std::tolower(
            value.back()
        );


    double multiplier = 1.0;


    if(
        suffix == 'k' ||
        suffix == 'm' ||
        suffix == 'b' ||
        suffix == 't'
    )
    {

        value.pop_back();

        switch(suffix)
        {

            case 'k':
                multiplier = 1e3;
                break;

            case 'm':
                multiplier = 1e6;
                break;

            case 'b':
                multiplier = 1e9;
                break;

            case 't':
                multiplier = 1e12;
                break;

        }

    }


    try
{
    double number =
        stod(value);

    if(number <= 0)
        throw std::invalid_argument("Invalid");

    return
        static_cast<long long>(
            number * multiplier
        );
}
catch(...)
{
    std::cerr
    << "Invalid digit count ❌\n";

    std::exit(EXIT_FAILURE);
}

}

using namespace std;

// ======================================================
// Global settings
// ======================================================


long DIGITS = 1000000;


int MAX_TREE_DEPTH = 2;


bool NO_SAVE = false;



// ======================================================
// Progress system data
// ======================================================


atomic<long> terms_done(0);




// ======================================================
// CPU core pinning
// ======================================================


void set_core(
    int core
)
{

    cpu_set_t set;


    CPU_ZERO(
        &set
    );


    CPU_SET(
        core,
        &set
    );


    sched_setaffinity(
        0,
        sizeof(set),
        &set
    );

}





// ======================================================
// Timing helper
// ======================================================


double elapsed(
    chrono::high_resolution_clock::time_point start,
    chrono::high_resolution_clock::time_point end
)
{

    return chrono::duration<double>(
        end - start
    ).count();

}

