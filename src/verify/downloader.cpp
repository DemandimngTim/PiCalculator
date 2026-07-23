// ======================================================
// downloader.cpp
// ======================================================

#include "downloader.h"

#include <iostream>
#include <cstdlib>


using namespace std;



bool download_reference(
    long digits,
    string output
)
{

    string url =
        "https://files.pilookup.com/pi/" +
        to_string(digits) +
        ".txt";



    cout
    << "Downloading...\n";



    string command =
        "curl -L \"" +
        url +
        "\" -o \"" +
        output +
        "\"";



    int result =
        system(
            command.c_str()
        );



    return result == 0;

}
