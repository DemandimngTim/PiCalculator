// ======================================================
// verify.cpp
// Verify + Verify++ command router
// ======================================================

#include "verify.h"
#include "pi.h"

#include <iostream>
#include <string>


using namespace std;


// ======================================================
// External functions
// ======================================================

bool compare_files(
    string generated,
    string reference
);


bool prepare_reference(
    long digits
);


void verify_random(
    long digits,
    int checks,
    int chunk_size
);


void verify_middle(
    long digits,
    long amount
);


void verify_end(
    long digits,
    long amount
);



// ======================================================
// Normal verify
// ./pi --verify digits
// ======================================================

void run_verify(
    int argc,
    char **argv
)
{

    if(argc < 3)
    {
        cout
        << "Usage:\n"
        << "./pi --verify digits\n";

        return;
    }



    long digits =
        parse_digits(argv[2]);



    if(digits <= 0)
    {
        cout
        << "Invalid digit count ❌\n";

        return;
    }



    string generated =
        "pi_" +
        to_string(digits) +
        ".txt";


    string reference =
        "reference/pi_" +
        to_string(digits) +
        ".txt";



    cout
    << "Verify 🔥\n\n";



    if(!prepare_reference(digits))
    {
        cout
        << "Cannot continue ❌\n";

        return;
    }



    cout
    << "Full verification 🔥\n";



    if(compare_files(
        generated,
        reference
    ))
    {
        cout
        << "All digits match ✅\n";
    }
    else
    {
        cout
        << "Verification failed ❌\n";
    }

}



// ======================================================
// Verify++
// Only:
// digits-random
// digits-middle
// digits-end
// ======================================================

void run_verify_plus(
    int argc,
    char **argv
)
{

    if(argc < 3)
    {
        cout
        << "Usage:\n"
        << "./pi --verify++ digits-random checks chunk\n"
        << "./pi --verify++ digits-middle amount\n"
        << "./pi --verify++ digits-end amount\n";

        return;
    }



    string input =
        argv[2];


    string mode = "";

    long amount = 128;

    int checks = 64;



    size_t pos;



    // ------------------------------
    // Random
    // ------------------------------

    pos =
        input.find("-random");


    if(pos != string::npos)
    {

        mode = "random";


        input =
            input.substr(
                0,
                pos
            );


        if(argc > 3)
            checks = atoi(argv[3]);


        if(argc > 4)
            amount = atoi(argv[4]);

    }



    // ------------------------------
    // Middle
    // ------------------------------

    else
    {

        pos =
            input.find("-middle");


        if(pos != string::npos)
        {

            mode = "middle";


            input =
                input.substr(
                    0,
                    pos
                );


            if(argc > 3)
                amount = atoi(argv[3]);

        }

    }



    // ------------------------------
    // End
    // ------------------------------

    if(mode.empty())
    {

        pos =
            input.find("-end");


        if(pos != string::npos)
        {

            mode = "end";


            input =
                input.substr(
                    0,
                    pos
                );


            if(argc > 3)
                amount = atoi(argv[3]);

        }

    }



    // ------------------------------
    // Invalid
    // ------------------------------

    if(mode.empty())
    {

        cout
        << "Invalid Verify++ mode ❌\n\n";

        cout
        << "Available modes:\n"
        << "-random\n"
        << "-middle\n"
        << "-end\n";

        return;

    }



    long digits =
        parse_digits(input);



    if(digits <= 0)
    {

        cout
        << "Invalid digit count ❌\n";

        return;

    }



    cout
    << "Verify++ 🔥\n\n";



    if(!prepare_reference(digits))
    {
        cout
        << "Cannot continue ❌\n";

        return;
    }



    // ------------------------------
    // Execute mode
    // ------------------------------

    if(mode == "random")
    {

        verify_random(
            digits,
            checks,
            amount
        );

    }


    else if(mode == "middle")
    {

        verify_middle(
            digits,
            amount
        );

    }


    else if(mode == "end")
    {

        verify_end(
            digits,
            amount
        );

    }



    cout
    << "\nVerify++ complete 🔥\n";

}
