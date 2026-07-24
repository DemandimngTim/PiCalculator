// ======================================================
// end.cpp
// Verify++ end section checker
// ======================================================

#include "pi.h"

#include <iostream>
#include <fstream>
#include <string>


using namespace std;


void verify_end(
    long digits,
    long check_digits
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



    ifstream file(generated);



    if(!file)
    {
        cout
        << "Generated file missing ❌\n";

        return;
    }



    file.seekg(
        0,
        ios::end
    );


    long size =
        file.tellg();



    long start =
        size - check_digits;



    if(start < 0)
        start = 0;



    cout
    << "End verification 🔥\n";


    cout
    << "Checking last "
    << check_digits
    << " characters\n";



    if(compare_range(
        generated,
        reference,
        start,
        check_digits
    ))
    {
        cout
        << "End verification passed ✅\n";
    }
    else
    {
        cout
        << "End verification failed ❌\n";
    }

}
