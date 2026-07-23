// ======================================================
// comparator.cpp
// Verify++ comparison modes
// ======================================================

#include <iostream>
#include <fstream>
#include <string>


using namespace std;



bool compare_files(
    string generated,
    string reference
)
{

    ifstream a(generated);
    ifstream b(reference);


    if(!a || !b)
        return false;


    char x;
    char y;


    long position = 0;



    while(
        a.get(x) &&
        b.get(y)
    )
    {

        if(x != y)
        {

            cout
            << "\nMismatch at digit "
            << position
            << " ❌\n";

            cout
            << "Generated: "
            << x
            << "\n";

            cout
            << "Reference: "
            << y
            << "\n";


            return false;

        }


        position++;


        if(position % 10000 == 0)
        {
            cout
            << "\rChecked "
            << position
            << " digits"
            << flush;
        }

    }


    cout << "\n";

    return true;

}





void verify_full(
    long digits
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





void verify_random(
    long digits
)
{

    cout
    << "Random digit verification 🔥\n";

    cout
    << "Coming soon (random mode)\n";

}





void verify_middle(
    long digits
)
{

    cout
    << "Middle digit verification 🔥\n";

    cout
    << "Coming soon (middle mode)\n";

}





void verify_end(
    long digits
)
{

    cout
    << "End digit verification 🔥\n";

    cout
    << "Coming soon (end mode)\n";

}
