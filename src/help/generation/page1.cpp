#include <iostream>
#include "help.h"

using namespace std;

void help_generation_page1()
{
    cout << R"(1. Generation

Description:
Generates the requested amount of π digits.

Usage:
./pi <digits> [<depth>]

Arguments:

<digits>
  Amount of π digits to generate.

<depth>
  Optional binary splitting tree depth.

Examples:

./pi 1000
  Generates 1,000 digits.

./pi 10m 1
  Generates 10,000,000 digits with tree depth 1.

Notes:

Generation does not scale linearly.
A larger calculation may take ×1.10 - ×4
more time depending on hardware,
memory usage, and optimizations.
)" << "\n";
}
