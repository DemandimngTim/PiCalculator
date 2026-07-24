#include <iostream>
#include "help.h"

using namespace std;

void help_benchmarking_page1()
{
    cout << R"(3. Benchmarking

Benchmarking

Description:
Benchmarking tests different tree depths to find
the best depth for your device.

Usage:
./pi --benchmark <digits>

Details:
Benchmark tests these tree depths:
0, 1, 2, 3, and 4.

Notes:

• Benchmarking tests the same depth 3 times
  to get more accurate results.

• Large calculations can take a long time
  to finish.

Page 1/3
)" << "\n";
}
