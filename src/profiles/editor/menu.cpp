#include "menu.h"
#include "colors.h"

#include <iostream>

using namespace std;


int show_editor_menu(const Profile &profile)
{
    cout << "\n";

    cout << BOLD << CYAN;
    cout << "==============================\n";
    cout << "     PiCalculator Profile\n";
    cout << "==============================\n";
    cout << RESET;

    cout << YELLOW
         << " Profile: "
         << RESET
         << profile.name
         << "\n\n";


    cout << GREEN;
    cout << "[1] Performance\n";
    cout << "[2] Output\n";
    cout << "[3] Calculation\n";
    cout << "[4] Verification\n";
    cout << "[5] Interface\n";
    cout << RESET;


    cout << "\n";

    cout << BLUE;
    cout << "[6] Save changes\n";
    cout << RED;
    cout << "[7] Exit\n";
    cout << RESET;


    cout << "\nChoice: ";

    int choice;
    cin >> choice;

    return choice;
}
