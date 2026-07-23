// ======================================================
// verify.cpp
// Chunk 6.5
// Verify++ main system
// ======================================================

#include "verify.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>


bool reference_exists(
    long digits
);

bool prepare_reference(
    long digits
);

void verify_full(
    long digits
);

void verify_random(
    long digits
);

void verify_middle(
    long digits
);

void verify_end(
    long digits
);



using namespace std;



void run_verify_plus(
    int argc,
    char **argv
)
{

    if(argc < 3)
    {
        cout
        << "Usage:\n"
        << "./pi --verify++ digits[-random|-middle|-end]\n";

        return;
    }



    string arg =
        argv[2];



    string mode =
        "full";



    if(arg.find("-random") != string::npos)
    {
        mode = "random";
        arg =
            arg.substr(
                0,
                arg.find("-random")
            );
    }

    else if(arg.find("-middle") != string::npos)
    {
        mode = "middle";
        arg =
            arg.substr(
                0,
                arg.find("-middle")
            );
    }

    else if(arg.find("-end") != string::npos)
    {
        mode = "end";
        arg =
            arg.substr(
                0,
                arg.find("-end")
            );
    }



    long digits =
        atol(
            arg.c_str()
        );



    cout
    << "Verify++ 🔥\n\n";



    if(!prepare_reference(digits))
    {
        cout
        << "Cannot continue ❌\n";

        return;
    }



    if(mode == "random")
        verify_random(digits);

    else if(mode == "middle")
        verify_middle(digits);

    else if(mode == "end")
        verify_end(digits);

    else
        verify_full(digits);



    cout
    << "\nVerify++ complete 🔥\n";

}
