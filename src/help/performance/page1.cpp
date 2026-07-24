#include <iostream>
#include "help.h"

using namespace std;

void help_performance_page1()
{
    cout << R"(4. Performance

Description:
PiCalculator is optimized for high performance,
but there is still room for improvement 💀.

Performance depends on:
• CPU speed and architecture.
• Available cores.
• Compiler optimizations.
• GMP and MPFR performance.
• Selected tree depth.

Tips:

• Higher tree depths can improve performance
  on powerful devices but may hurt smaller
  calculations due to overhead.

• Use optimized builds for better results.

• Avoid running heavy background tasks during
  large calculations.

Page 1/1
)" << "\n";
}
