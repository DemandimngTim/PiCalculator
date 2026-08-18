#include "editor.h"
#include "editor_functions.h"

#include "../profile_writer.h"

#include <iostream>
#include <string>

using namespace std;


void clear_editor_screen()
{
    cout << "\033[2J\033[H";
}


int editor_choice()
{
    string input;

    cout << "Choice: ";
    getline(cin, input);

    try
    {
        return stoi(input);
    }
    catch(...)
    {
        return -1;
    }
}


void edit_profile(
    Profile &profile,
    const string &path
)
{
    bool editing = true;


    while(editing)
    {
        clear_editor_screen();


        cout << "==============================\n";
        cout << "     PiCalculator Profile\n";
        cout << "==============================\n\n";


        cout << " Profile: "
             << profile.name
             << "\n\n";


        cout << "[1] Performance\n";
        cout << "[2] Output\n";
        cout << "[3] Calculation\n";
        cout << "[4] Verification\n";
        cout << "[5] Interface\n\n";

        cout << "[6] Save changes\n";
        cout << "[7] Exit\n\n";


        int choice = editor_choice();


        switch(choice)
        {
            case 1:
                edit_performance(profile);
                break;

            case 2:
                edit_output(profile);
                break;

            case 3:
                edit_calculation(profile);
                break;

            case 4:
                edit_verification(profile);
                break;

            case 5:
                edit_interface(profile);
                break;


            case 6:
            {
                if(save_profile(profile, path))
                {
                    cout << "\nSaved ✅\n";
                }
                else
                {
                    cout << "\nSave failed ❌\n";
                }

                break;
            }


            case 7:
                editing = false;
                break;


            default:
                cout << "\nInvalid choice ❌\n";
                break;
        }


        if(editing)
        {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }


    cout << "\nReturning to profile manager...\n";
}
