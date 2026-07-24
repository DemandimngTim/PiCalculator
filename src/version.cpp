#include <iostream>
#include "version.h"

using namespace std;

void show_version()
{
    cout << "PiCalculator 🔥\n";
    cout << "Codename: " << PI_CODENAME << "\n";
    cout << "Version: " << PI_VERSION << "\n";
    cout << "GMP + MPFR Optimized Chudnovsky π Calculator\n";
}
