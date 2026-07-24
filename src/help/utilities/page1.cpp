#include <iostream>
#include "help.h"

using namespace std;

void help_utilities_page1()
{
    cout << R"(6. Utilities

Description:
Utilities provide additional tools and features
that help manage, test, and use PiCalculator.

Available utilities:

Estimate:
Estimates calculation requirements before
starting a large calculation.

Usage:
./pi --estimate <digits>


No-Save:
Calculates π without saving the output file.

Usage:
./pi --no-save <digits> [<tree depth>]


Version:
Shows information about the current
PiCalculator version.

Usage:
./pi --version


Notes:

• Utility availability depends on the current
  PiCalculator version.

• Some utilities may require additional files
  or settings.

Page 1/1
)" << "\n";
}
