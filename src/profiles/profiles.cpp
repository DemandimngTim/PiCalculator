#include "profiles.h"

#include "profile_creator.h"
#include "profile_loader.h"
#include "profile_manager.h"
#include "active_profile.h"
#include "editor/editor.h"

#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace fs = std::filesystem;


void clear_screen()
{
    cout << "\033[2J\033[H";
}


int get_choice()
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


vector<string> get_profiles()
{
    vector<string> profiles;

    if(fs::exists("profiles"))
    {
        for(auto &file : fs::directory_iterator("profiles"))
        {
            if(file.path().extension() == ".profile")
            {
                profiles.push_back(file.path().string());
            }
        }
    }

    sort(profiles.begin(), profiles.end());

    return profiles;
}


void run_profiles()
{
    load_active_profile();

    bool running = true;


    while(running)
    {
        clear_screen();


        cout << "==============================\n";
        cout << "   PiCalculator Profiles 🔥\n";
        cout << "==============================\n\n";


        cout << "Profile Manager\n\n";

        cout << "[1] Create profile\n";
        cout << "[2] Load profile\n";
        cout << "[3] Manage profiles\n";
        cout << "[4] Profile settings\n";
        cout << "[5] Exit\n\n";


        if(!active_profile_path.empty())
        {
            cout << "Active profile: "
                 << fs::path(active_profile_path).filename()
                 << "\n\n";
        }


        int choice = get_choice();


        switch(choice)
        {
            case 1:
                create_profile();
                break;


            case 2:
            {
                vector<string> profiles = get_profiles();


                if(profiles.empty())
                {
                    cout << "\nNo profiles found 🥀\n";
                    break;
                }


                cout << "\nAvailable profiles:\n\n";


                for(int i = 0; i < profiles.size(); i++)
                {
                    cout << "["
                         << i + 1
                         << "] "
                         << fs::path(profiles[i]).filename()
                         << "\n";
                }


                cout << "\n";

                int selected = get_choice();


                if(selected < 1 ||
                   selected > profiles.size())
                {
                    cout << "\nInvalid profile ❌\n";
                    break;
                }


                Profile profile;


                if(load_profile(profile,
                                profiles[selected - 1]))
                {
                    save_active_profile(
                        profiles[selected - 1]
                    );


                    cout << "\nLoaded: "
                         << profile.name
                         << " ✅\n";
                }

                break;
            }


            case 3:
                manage_profiles();
                break;


            case 4:
            {
                if(active_profile_path.empty())
                {
                    cout << "\nNo active profile ❌\n";
                    break;
                }


                Profile profile;


                if(load_profile(profile,
                                active_profile_path))
                {
                    edit_profile(
                        profile,
                        active_profile_path
                    );
                }

                break;
            }


            case 5:
                running = false;
                break;


            default:
                cout << "\nInvalid choice ❌\n";
                break;
        }


        if(running)
        {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }
}
