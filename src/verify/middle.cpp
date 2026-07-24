// ======================================================
// middle.cpp
// Verify++ middle section checker
// ======================================================

#include "pi.h"

#include <iostream>
#include <string>


using namespace std;


void verify_middle(
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



    long middle =
        digits / 2;



    long start =
        middle - (check_digits / 2);



    if(start < 0)
        start = 0;



    cout
    << "Middle verification 🔥\n";


    cout
    << "Center: "
    << middle
    << "\n";


    cout
    << "Range: "
    << start
    << " - "
    << start + check_digits
    << "\n";



    if(compare_range(
        generated,
        reference,
        start,
        check_digits
    ))
    {
        cout
        << "Middle verification passed ✅\n";
    }
    else
    {
        cout
        << "Middle verification failed ❌\n";
    }

}
