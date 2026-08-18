#include "../profile.h"

#include <iostream>
#include <string>

using namespace std;


void clear_performance_screen()
{
    cout << "\033[2J\033[H";
}


int performance_choice()
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



void edit_performance(Profile &profile)
{
    bool editing = true;


    while(editing)
    {
        clear_performance_screen();


        cout << "==============================\n";
        cout << "     Performance Settings 🔥\n";
        cout << "==============================\n\n";


        cout << "1. Tree depth: "
             << profile.tree_depth
             << "\n";


        cout << "2. Thread mode: "
             << profile.thread_mode
             << "\n";


        cout << "3. Parallel calculation: "
             << (profile.parallel ? "ON" : "OFF")
             << "\n";


        cout << "4. Back\n\n";


        int choice = performance_choice();


        if(choice == -1)
        {
            cout << "\nInvalid input ❌\n";
            cin.ignore(1000, '\n');
            continue;
        }



        switch(choice)
        {

        case 1:
        {
            clear_performance_screen();

            cout << "Tree depth (0-8): ";

            string input;
            getline(cin, input);


            try
            {
                int depth = stoi(input);


                if(depth < 0)
                    depth = 0;

                if(depth > 8)
                    depth = 8;


                profile.tree_depth = depth;
            }
            catch(...)
            {
                cout << "Invalid number ❌\n";
            }

            break;
        }



        case 2:
        {
            clear_performance_screen();


            cout << "Thread mode\n\n";

            cout << "1. Auto\n";
            cout << "2. Single\n";
            cout << "3. Big cores only\n";
            cout << "4. All cores\n\n";


            int mode = performance_choice();


            switch(mode)
            {
                case 2:
                    profile.thread_mode = "Single";
                    break;

                case 3:
                    profile.thread_mode = "Big cores only";
                    break;

                case 4:
                    profile.thread_mode = "All cores";
                    break;

                default:
                    profile.thread_mode = "Auto";
                    break;
            }

            break;
        }



        case 3:
            profile.parallel = !profile.parallel;
            break;



        case 4:
            editing = false;
            break;



        default:
            cout << "Invalid choice ❌\n";
            break;
        }



        if(editing)
        {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }
}
