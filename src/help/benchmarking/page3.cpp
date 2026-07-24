#include <iostream>
#include "help.h"

using namespace std;

void help_benchmarking_page3()
{
    cout << R"(3. Benchmarking

Benchmark# (Benchmark Sharp)

Description:
Benchmark# allows choosing which CPU cores
are used during benchmarking.

Usage:
./pi --benchmark# <digits> <cores>

Details:
Benchmark# tests these tree depths:
0, 1, 2, 3, and 4.

Unlike normal benchmarks:
• Uses the cores selected by the user.
• Does not use the default core selection.

Notes:

• Same notes as Benchmark and Benchmark++.
• Large calculations can take a long time
  to finish.

Page 3/3
)" << "\n";
}
