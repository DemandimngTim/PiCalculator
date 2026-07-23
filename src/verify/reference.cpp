// ======================================================
// reference.cpp
// Reference file manager
// ======================================================

#include "downloader.h"

#include <iostream>
#include <fstream>
#include <filesystem>


using namespace std;

namespace fs = filesystem;



bool reference_exists(long digits)
{
    return fs::exists(
        "reference/pi_" +
        to_string(digits) +
        ".txt"
    );
}



bool validate_reference(
    string file
)
{

    ifstream input(file);



    if(!input)
        return false;



    char a,b,c,d;



    input >> a >> b >> c >> d;



    // Should start with 3.14

    return
        a == '3' &&
        b == '.' &&
        c == '1' &&
        d == '4';

}





bool install_reference(
    long digits
)
{

    string temp =
        "temp/downloads/pi_" +
        to_string(digits) +
        ".download";


    string final =
        "reference/pi_" +
        to_string(digits) +
        ".txt";



    if(!validate_reference(temp))
    {

        cout
        << "Downloaded file invalid ❌\n";

        return false;

    }



    fs::rename(
        temp,
        final
    );



    cout
    << "Reference installed ✅\n";


    return true;

}





bool prepare_reference(
    long digits
)
{

    if(reference_exists(digits))
    {

        cout
        << "Reference found ✅\n";

        return true;

    }



    cout
    << "Reference file missing ❌\n";



    cout
    << "Required storage: "
    << digits / 1024.0
    << " KB\n\n";



    cout
    << "Download from piLookup.com? [y/n]: ";



    char answer;

    cin >> answer;



    if(answer != 'y')
        return false;




    string temp =
        "temp/downloads/pi_" +
        to_string(digits) +
        ".download";



    if(!download_reference(
        digits,
        temp
    ))
    {

        cout
        << "Download failed ❌\n";

        return false;

    }



    return install_reference(digits);

}
