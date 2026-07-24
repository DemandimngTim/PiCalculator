#include <iostream>
#include "help.h"

using namespace std;

void help_verification_page1()
{
    cout << R"(2. Verification

Description:
Verification checks if the generated π digits
are correct by comparing them with a reference file.

Usage:
./pi --verify <digits>

Notes:

• The π file must already be generated before
  verification can be used.

• If you don't have a reference file, you will
  be asked to download one.

• Verification does not work if --no-save was
  active during generation because the π file
  was not saved.

Page 1/2
)" << "\n";
}
