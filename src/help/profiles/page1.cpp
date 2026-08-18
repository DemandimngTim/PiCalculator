#include "help.h"
#include <iostream>

using namespace std;

void help_profiles_page1()
{
    cout << "PiCalculator Profiles 🔥\n\n";

    cout << "Profiles are saved configurations for PiCalculator.\n";
    cout << "They allow you to quickly load your preferred settings.\n\n";

    cout << "Planned commands:\n\n";

    cout << "--profile-save\n";
    cout << "    Save current settings as a profile.\n\n";

    cout << "--profile\n";
    cout << "    Load or manage a profile.\n\n";

    cout << "--profile-list\n";
    cout << "    Display available profiles.\n\n";

    cout << "Example idea:\n";
    cout << "./pi --profile\n";
    cout << "Profile name: fast\n\n";

    cout << "Profiles can store things like:\n";
    cout << "- Tree depth\n";
    cout << "- Performance settings\n";
    cout << "- Saving preferences\n";
    cout << "- Calculation options\n\n";

    cout << "Status: Coming soon 🚧\n";
}
