#include "profile_manager.h"

#include "input.h"
#include "active_profile.h"

#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>

using namespace std;

namespace fs = std::filesystem;

static vector<string> get_profiles()
{
    vector<string> profiles;

    fs::create_directories("profiles");

    for(const auto &file : fs::directory_iterator("profiles"))
    {
        if(file.path().extension() == ".profile")
        {
            profiles.push_back(file.path().string());
        }
    }

    sort(profiles.begin(), profiles.end());

    return profiles;
}

void manage_profiles()
{
    while(true)
    {
        vector<string> profiles = get_profiles();

        cout << "\n";
        cout << "==============================\n";
        cout << "      Profile Manager 🔥\n";
        cout << "==============================\n\n";

        if(profiles.empty())
        {
            cout << "No profiles found 🥀\n";
            return;
        }

        cout << "Profiles: " << profiles.size() << "\n\n";

        for(size_t i = 0; i < profiles.size(); i++)
        {
            cout << "["
                 << i + 1
                 << "] "
                 << fs::path(profiles[i]).filename();

            if(profiles[i] == active_profile_path)
                cout << "  ⭐";

            cout << "\n";
        }

        cout << "\n[" << profiles.size() + 1 << "] Back\n\n";

        cout << "Choice: ";

        int choice = get_int();

        if(choice == (int)profiles.size() + 1)
            return;

        if(choice < 1 || choice > (int)profiles.size())
        {
            cout << "\n❌ Invalid choice.\n";
            continue;
        }

        string selected = profiles[choice - 1];

        while(true)
        {
            cout << "\n";
            cout << "Selected: "
                 << fs::path(selected).filename()
                 << "\n\n";

            cout << "[1] Delete\n";
            cout << "[2] Back\n\n";

            cout << "Choice: ";

            int action = get_int();

            if(action == 2)
                break;

            if(action != 1)
            {
                cout << "\n❌ Invalid choice.\n";
                continue;
            }

            if(selected == active_profile_path)
            {
                cout << "\n❌ Cannot delete the active profile.\n";
                break;
            }

            cout << "\nDelete this profile? (y/n): ";

            if(!get_yes_no())
                break;

            if(fs::remove(selected))
            {
                cout << "\n✅ Profile deleted.\n";
            }
            else
            {
                cout << "\n❌ Failed to delete profile.\n";
            }

            break;
        }
    }
}
