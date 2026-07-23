// ======================================================
// output.cpp
// π file writer
// ======================================================


#include "pi.h"

#include <iostream>
#include <cstdio>
#include <string>


using namespace std;



void save_pi(
    mpfr_t pi,
    long digits
)
{

    string filename =
        "pi_" +
        to_string(digits) +
        ".txt";



    cout
    << "Saving file...\n";



    auto start =
        chrono::high_resolution_clock::now();




    FILE *file =
        fopen(
            filename.c_str(),
            "w"
        );



    if(!file)
    {

        cout
        << "File open failed ❌\n";

        return;

    }




    static char buffer[
        16 * 1024 * 1024
    ];



    setvbuf(
        file,
        buffer,
        _IOFBF,
        sizeof(buffer)
    );




    // Write directly from MPFR

    mpfr_out_str(
        file,
        10,
        digits + 1,
        pi,
        MPFR_RNDN
    );



    fclose(file);




    auto end =
        chrono::high_resolution_clock::now();



    cout
    << "Save time: "
    << elapsed(
        start,
        end
    )
    << "s\n\n";

}
