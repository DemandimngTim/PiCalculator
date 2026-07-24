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
//
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






    // Move digit argument

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



}
