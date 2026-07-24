#include <iostream>
#include "help.h"

using namespace std;

void help_verification_page2()
{
    cout << R"(2. Verification++

Description:
Verification++ provides additional ways to
check if generated π digits are correct.

Usage:

Middle:
./pi --verify++ <digits>-middle <amount>

Checks the selected amount of middle digits.

Example:
./pi --verify++ 10m-middle 1000


End:
./pi --verify++ <digits>-end <amount>

Checks the selected amount of ending digits.

Example:
./pi --verify++ 10m-end 1000


Random:
./pi --verify++ <digits>-random <chunks> <chunk size>

Checks randomly selected chunks of digits.

Example:
./pi --verify++ 10m-random 128 256


Notes:

• If --no-save was active during generation,
  verification functions will not work because
  the π file was not saved.

• If the reference file is missing, you will be
  asked to download one.

• --verify++ only works after π has been
  generated.

Page 2/2
)" << "\n";
}
