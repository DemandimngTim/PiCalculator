#include "active_profile.h"

#include <fstream>
#include <filesystem>


using namespace std;

namespace fs = std::filesystem;


string active_profile_path = "";


const string ACTIVE_FILE =
    "profiles/active.txt";



bool load_active_profile()
{
    if(!fs::exists(ACTIVE_FILE))
    {
        return false;
    }


    ifstream file(ACTIVE_FILE);


    if(!file)
    {
        return false;
    }


    getline(file, active_profile_path);


    file.close();


    return !active_profile_path.empty();
}



bool save_active_profile(
    const string& path
)
{
    fs::create_directories("profiles");


    ofstream file(ACTIVE_FILE);


    if(!file)
    {
        return false;
    }


    file << path;


    file.close();


    active_profile_path = path;


    return true;
}



void clear_active_profile()
{
    active_profile_path = "";


    if(fs::exists(ACTIVE_FILE))
    {
        fs::remove(ACTIVE_FILE);
    }
}
