// ======================================================
// random.cpp
// Verify++ spaced random chunk checker
// ======================================================

#include "pi.h"

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <string>

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



    vector<long> positions;


    random_device rd;
    mt19937_64 gen(rd());


    long min_distance =
        chunk_size * 2;



    int attempts = 0;

    int max_attempts =
        checks * 1000;



    while((int)positions.size() < checks)
    {

        if(attempts++ > max_attempts)
        {

            cout
            << "Could not find enough spaced positions, lowering distance...\n";

            min_distance /= 2;

            attempts = 0;
        }



        long max_pos =
            digits - chunk_size;


        long pos =
            gen() % max_pos;



        bool valid = true;



        for(long old : positions)
        {

            if(llabs(pos - old) < min_distance)
            {

                valid = false;

                break;
            }
        }



        if(valid)
        {
            positions.push_back(pos);
        }
    }



    sort(
        positions.begin(),
        positions.end()
    );



    for(int i = 0; i < checks; i++)
    {

        cout
        << "Check "
        << i + 1
        << "/"
        << checks
        << " at "
        << positions[i]
        << "\n";



        if(!compare_range(
            generated,
            reference,
            positions[i],
            chunk_size
        ))
        {

            cout
            << "Random verification failed ❌\n";

            return;
        }
    }



    cout
    << "Random verification passed ✅\n";
}
