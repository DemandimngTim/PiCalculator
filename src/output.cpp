// ======================================================
// output.cpp
// π file writer
// Optimized MPFR extraction + buffered output
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


    auto total_start =
        chrono::high_resolution_clock::now();



    FILE *file =
        fopen(
            filename.c_str(),
            "wb"
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



    // ==================================================
    // MPFR -> decimal string
    // ==================================================

    auto convert_start =
        chrono::high_resolution_clock::now();



    mpfr_exp_t exponent;


    char *digits_string =
        mpfr_get_str(
            nullptr,
            &exponent,
            10,
            digits,
            pi,
            MPFR_RNDZ
        );



    auto convert_end =
        chrono::high_resolution_clock::now();



    if(!digits_string)
    {
        cout
        << "MPFR conversion failed ❌\n";

        fclose(file);

        return;
    }



    cout
    << "Conversion time: "
    << elapsed(
        convert_start,
        convert_end
    )
    << "s\n";



    // ==================================================
    // Write file
    // ==================================================

    auto write_start =
        chrono::high_resolution_clock::now();



    if(exponent <= 0)
    {

        fwrite(
            "0.",
            1,
            2,
            file
        );


        for(long i = 0; i < -exponent; i++)
        {
            fputc(
                '0',
                file
            );
        }


        fwrite(
            digits_string,
            1,
            strlen(digits_string),
            file
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


        fwrite(
            digits_string + 1,
            1,
            strlen(
                digits_string + 1
            ),
            file
        );

    }



    auto write_end =
        chrono::high_resolution_clock::now();



    mpfr_free_str(
        digits_string
    );


    fclose(file);



    cout
    << "Write time: "
    << elapsed(
        write_start,
        write_end
    )
    << "s\n";



    auto total_end =
        chrono::high_resolution_clock::now();



    cout
    << "Save time: "
    << elapsed(
        total_start,
        total_end
    )
    << "s\n\n";

}
