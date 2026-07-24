// ======================================================
// no_save.cpp
// --no-save command
// ======================================================

#include "pi.h"

#include <iostream>
#include <cstdlib>

using namespace std;


// ======================================================
// Disable saving output
//
// Usage:
// ./pi --no-save digits [depth]
// ======================================================

void run_no_save(
    int argc,
    char **argv
)
{
    NO_SAVE = true;


    if(argc < 3)
    {
        cout
        << "Usage: ./pi --no-save digits [depth]\n";

        return;
    }


    // Parse digit argument
    DIGITS =
        parse_digits(
            argv[2]
        );


    // Optional tree depth
    if(argc > 3)
    {
        MAX_TREE_DEPTH =
            atoi(
                argv[3]
            );
    }


    // Run normal generation pipeline
    char *new_argv[3];

    new_argv[0] = argv[0];
    new_argv[1] = argv[2];

    int new_argc = 2;


    if(argc > 3)
    {
        new_argv[2] = argv[3];
        new_argc = 3;
    }


    run_program(
        new_argc,
        new_argv
    );
}
