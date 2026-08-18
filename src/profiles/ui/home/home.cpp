#include "home.h"

#include <iostream>

using namespace std;

int show_profile_home()
{
    cout << "\n";
    cout << "==============================\n";
    cout << "   PiCalculator Profiles 🔥\n";
    cout << "==============================\n\n";

    cout << "Profile Manager\n\n";

    cout << "[1] Create profile\n";
    cout << "[2] Load profile\n";
    cout << "[3] Manage profiles\n";
    cout << "[4] Profile settings\n";
    cout << "[5] Exit\n\n";

    cout << "Choice: ";

    int choice;
    cin >> choice;

    return choice;
}
