#include "profile_creator.h"

#include "profile.h"
#include "profile_writer.h"
#include "input.h"

#include <iostream>
#include <filesystem>
#include <algorithm>
#include <cctype>

using namespace std;

namespace fs = std::filesystem;

static bool valid_name(const string& name)
{
    if(name.empty())
        return false;

    for(char c : name)
    {
        if(isalnum(static_cast<unsigned char>(c)))
            continue;

        if(c == '_' || c == '-')
            continue;

        return false;
    }

    return true;
}

void create_profile()
{
    cout << "\n";
    cout << "==============================\n";
    cout << "       Create Profile 🔥\n";
    cout << "==============================\n\n";

    cout << "Profile name: ";

    string name = get_string();

    if(name.empty())
    {
        cout << "\n❌ Profile name cannot be empty.\n";
        return;
    }

    if(!valid_name(name))
    {
        cout << "\n❌ Invalid name.\n";
        cout << "Only letters, numbers, '_' and '-' are allowed.\n";
        return;
    }

    fs::create_directories("profiles");

    string path = "profiles/" + name + ".profile";

    if(fs::exists(path))
    {
        cout << "\n❌ A profile with that name already exists.\n";
        return;
    }

    Profile profile;
    profile.name = name;

    cout << "\nCreating profile with default settings...\n\n";

    cout << "Profile preview\n";
    cout << "------------------------------\n";
    cout << "Name        : " << profile.name << '\n';
    cout << "Tree depth  : " << profile.tree_depth << '\n';
    cout << "Thread mode : " << profile.thread_mode << '\n';
    cout << "Algorithm   : " << profile.algorithm << '\n';
    cout << "Backend     : " << profile.precision_mode << '\n';
    cout << "------------------------------\n\n";

    cout << "Create this profile? (y/n): ";

    if(!get_yes_no())
    {
        cout << "\n❌ Cancelled.\n";
        return;
    }

    if(save_profile(profile, path))
    {
        cout << "\n✅ Profile created successfully!\n";
        cout << "Saved to: " << path << "\n";
    }
    else
    {
        cout << "\n❌ Failed to save profile.\n";
    }
}
