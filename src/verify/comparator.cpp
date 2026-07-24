
// ======================================================
// comparator.cpp
// Verify++ comparison engine
// ======================================================

#include "pi.h"

#include <iostream>
#include <fstream>
#include <string>


using namespace std;


// ======================================================
// Compare complete files
// ======================================================

bool compare_files(
    string generated,
    string reference
)
{
    ifstream a(generated);
    ifstream b(reference);


    if(!a || !b)
    {
        cout
        << "Could not open files ❌\n";

        return false;
    }


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
            << "\nMismatch at position "
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


        if(position % 1000000 == 0)
        {
            cout
            << "\rChecked "
            << position
            << " characters"
            << flush;
        }

    }



    // Generated has extra data

    if(a.get(x))
    {
        cout
        << "\nGenerated file longer than reference ❌\n";

        return false;
    }



    // Reference has extra data

    if(b.get(y))
    {
        cout
        << "\nReference file longer than generated ❌\n";

        return false;
    }



    cout
    << "\nChecked "
    << position
    << " characters\n";


    return true;
}




// ======================================================
// Compare a range of characters
// Used by:
// - middle verification
// - end verification
// - random verification
// ======================================================

bool compare_range(
    string generated,
    string reference,
    long start,
    long length
)
{

    ifstream a(generated);
    ifstream b(reference);



    if(!a || !b)
    {
        cout
        << "Could not open files ❌\n";

        return false;
    }



    a.seekg(start);
    b.seekg(start);



    char x;
    char y;



    for(
        long i = 0;
        i < length;
        i++
    )
    {

        if(
            !a.get(x) ||
            !b.get(y)
        )
        {
            cout
            << "\nReached file end unexpectedly ❌\n";

            return false;
        }



        if(x != y)
        {

            cout
            << "\nMismatch at position "
            << start + i
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



        if(i % 100000 == 0)
        {
            cout
            << "\rChecked "
            << i
            << "/"
            << length
            << " characters"
            << flush;
        }

    }



    cout
    << "\nChecked "
    << length
    << " characters\n";


    return true;
}
