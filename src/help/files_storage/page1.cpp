#include <iostream>
#include "help.h"

using namespace std;

void help_files_storage_page1()
{
    cout << R"(5. Files and Storage

Description:
Generated π digits are stored as plain text files.

File format:

pi_(digits).txt

Example:

pi_1000000.txt

Storage location:

generated_pi/

Notes:

• Large calculations can require a lot of storage.

• If you do not want to save the generated
  digits, use --no-save.

Usage:

./pi --no-save <digits> [<tree depth>]

When --no-save is enabled:
• The generated π digits are not written to a file.
• Only the calculation time is displayed.

Recommended for:
• Very large calculations where storing the
  output would require too much storage.

Page 1/1
)" << "\n";
}
