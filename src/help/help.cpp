// ======================================================
// help.cpp
// Main help router
// ======================================================

#include <iostream>
#include <string>
#include <cstdlib>

#include "index/help.h"

#include "generation/help.h"
#include "verification/help.h"
#include "benchmarking/help.h"
#include "files_storage/help.h"
#include "performance/help.h"
#include "utilities/help.h"


using namespace std;


// ======================================================
// Main help command
//
// Usage:
// ./pi --help
// ./pi --help <category>
// ./pi --help <category> <page>
// ======================================================


void run_help(
    int argc,
    char **argv
)
{

    // ------------------------------
    // No category
    // ------------------------------

    if(argc < 3)
    {
        help_index_page1();
        return;
    }


    string category = argv[2];


    int page = 1;


    if(argc >= 4)
    {
        page = atoi(argv[3]);

        if(page <= 0)
        {
            cout
            << "Invalid help page ❌\n";

            return;
        }
    }



    // ------------------------------
    // Generation
    // ------------------------------

    if(category == "generation" || category == "1")
    {
        switch(page)
        {
            case 1:
                help_generation_page1();
                break;

            default:
                cout
                << "Generation page does not exist ❌\n";
        }

        return;
    }



    // ------------------------------
    // Verification
    // ------------------------------

    if(category == "verification" || category == "2")
    {
        switch(page)
        {
            case 1:
                help_verification_page1();
                break;

            case 2:
                help_verification_page2();
                break;

            default:
                cout
                << "Verification page does not exist ❌\n";
        }

        return;
    }



    // ------------------------------
    // Benchmarking
    // ------------------------------

    if(category == "benchmarking" || category == "3")
    {
        switch(page)
        {
            case 1:
                help_benchmarking_page1();
                break;

            case 2:
                help_benchmarking_page2();
                break;

            case 3:
                help_benchmarking_page3();
                break;

            default:
                cout
                << "Benchmarking page does not exist ❌\n";
        }

        return;
    }



    // ------------------------------
    // Files
    // ------------------------------

    if(category == "files" ||
       category == "files_storage" ||
       category == "4")
    {
        switch(page)
        {
            case 1:
                help_files_storage_page1();
                break;

            default:
                cout
                << "Files page does not exist ❌\n";
        }

        return;
    }



    // ------------------------------
    // Performance
    // ------------------------------

    if(category == "performance" || category == "5")
    {
        switch(page)
        {
            case 1:
                help_performance_page1();
                break;

            default:
                cout
                << "Performance page does not exist ❌\n";
        }

        return;
    }



    // ------------------------------
    // Utilities
    // ------------------------------

    if(category == "utilities" || category == "6")
    {
        switch(page)
        {
            case 1:
                help_utilities_page1();
                break;

            default:
                cout
                << "Utilities page does not exist ❌\n";
        }

        return;
    }



    cout
    << "Unknown help category ❌\n";

}
