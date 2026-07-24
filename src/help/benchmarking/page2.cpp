#include <iostream>
#include "help.h"

using namespace std;

void help_benchmarking_page2()
{
    cout << R"(3. Benchmarking

Benchmark++

Description:
Benchmark++ improves benchmark accuracy by
adding a warmup run and showing additional
information after completion.

Usage:
./pi --benchmark++ <digits>

Details:
Benchmark++ tests these tree depths:
0, 1, 2, 3, and 4.

Before benchmarking:
• Performs a warmup run to prepare the CPU.
• Reduces interruptions from other processes.

After completion:
• Displays more advanced benchmark information.

Notes:

• Same notes as Benchmark.
• Large calculations can take a long time
  to finish.

Page 2/3
)" << "\n";
}
