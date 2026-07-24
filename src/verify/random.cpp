// ======================================================
// random.cpp
// Verify++ random chunk checker
// ======================================================

#include "pi.h"

#include <iostream>
#include <string>
#include <random>


using namespace std;


void verify_random(
    long digits,
    int checks,
    int chunk_size
)
{

    string generated =
        "pi_" +
        to_string(digits) +
        ".txt";


    string reference =
        "reference/pi_" +
        to_string(digits) +
        ".txt";



    cout
    << "Random chunk verification 🔥\n";


    cout
    << "Checks: "
    << checks
    << "\n";


    cout
    << "Chunk size: "
    << chunk_size
    << "\n\n";



    random_device rd;

    mt19937 generator(rd());



    uniform_int_distribution<long> distribution(
        0,
        digits - chunk_size
    );



    for(int i = 0; i < checks; i++)
    {

        long position =
            distribution(generator);



        cout
        << "Check "
        << i + 1
        << "/"
        << checks
        << " at "
        << position
        << "\n";



        if(!compare_range(
            generated,
            reference,
            position,
            chunk_size
        ))
        {
            cout
            << "Random verification failed ❌\n";

            return;
        }

    }



    cout
    << "\nRandom verification passed ✅\n";

}
