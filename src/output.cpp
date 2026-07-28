// ======================================================
// output.cpp
// π file writer
// Optimized MPFR extraction
// ======================================================

#include "pi.h"

#include <filesystem>
#include <iostream>
#include <cstdio>
#include <string>
#include <chrono>


using namespace std;


// ======================================================
// Save π
// ======================================================

void save_pi(
    mpfr_t pi,
    long digits
)
{   filesystem::create_directories("generated pi");
    string filename =
        "geberated pi/pi_" + to_string(digits) + ".txt";


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



    // --------------------------------------------------
    // MPFR -> decimal string
    // --------------------------------------------------

    auto conversion_start =
        chrono::high_resolution_clock::now();



    mpfr_exp_t exponent;


    char *str =
        mpfr_get_str(
            nullptr,
            &exponent,
            10,
            digits + 1,
            pi,
            MPFR_RNDZ
        );



    auto conversion_end =
        chrono::high_resolution_clock::now();



    if(!str)
    {
        cout
        << "Conversion failed ❌\n";

        fclose(file);

        return;
    }



    cout
    << "Conversion time: "
    << elapsed(
        conversion_start,
        conversion_end
    )
    << "s\n";



    // --------------------------------------------------
    // Write directly
    // --------------------------------------------------

    auto write_start =
        chrono::high_resolution_clock::now();



    // π always starts with 3

    fputc(
        str[0],
        file
    );


    fputc(
        '.',
        file
    );


    fwrite(
        str + 1,
        1,
        digits,
        file
    );



    auto write_end =
        chrono::high_resolution_clock::now();



    cout
    << "Write time: "
    << elapsed(
        write_start,
        write_end
    )
    << "s\n";



    mpfr_free_str(
        str
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
