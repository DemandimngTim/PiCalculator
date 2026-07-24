// ======================================================
// output.cpp
// π file writer
// Fixed:
// - No scientific notation
// - Exact digit count
// - Cleaner MPFR extraction
// ======================================================

#include "pi.h"

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>


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



    // Large buffer for fast writing

    static char buffer[
        16 * 1024 * 1024
    ];


    setvbuf(
        file,
        buffer,
        _IOFBF,
        sizeof(buffer)
    );



    // --------------------------------------------------
    // Convert MPFR -> string
    // --------------------------------------------------

    mpfr_exp_t exponent;


    char *digits_string =
        mpfr_get_str(
            nullptr,
            &exponent,
            10,
            digits + 1,
            pi,
            MPFR_RNDZ
        );



    if(!digits_string)
    {
        cout
        << "MPFR conversion failed ❌\n";

        fclose(file);
        return;
    }



    // Example:
    // exponent = 1
    // digits_string = "314159..."
    //
    // Output:
    // 3.14159...


    if(exponent <= 0)
    {
        fprintf(
            file,
            "0."
        );


        for(long i = 0; i < -exponent; i++)
            fputc(
                '0',
                file
            );


        fprintf(
            file,
            "%s",
            digits_string
        );

    }
    else
    {

        fputc(
            digits_string[0],
            file
        );


        fputc(
            '.',
            file
        );


        fprintf(
            file,
            "%s",
            digits_string + 1
        );

    }



    mpfr_free_str(
        digits_string
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
