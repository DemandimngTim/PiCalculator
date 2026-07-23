// ======================================================
// main.cpp
// Program entry point
// ======================================================


#include "pi.h"
#include "commands.h"

#include <iostream>


using namespace std;



int main(
    int argc,
    char **argv
)
{

    // ==================================================
    // Check commands first
    //
    // Examples:
    // ./pi --benchmark 5000000
    // ./pi --estimate 10000000
    //
    // If handled:
    // return immediately
    // ==================================================


    if(run_command(argc, argv))
    {
        return 0;
    }





    // ==================================================
    // Normal π calculation
    //
    // Example:
    // ./pi 1000000
    //
    // Runs the normal calculator pipeline
    // ==================================================


    return run_program(
        argc,
        argv
    );

}
