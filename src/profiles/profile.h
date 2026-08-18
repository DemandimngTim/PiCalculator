#pragma once

#include <string>

struct Profile
{
    std::string name;


    // Performance
    int tree_depth = 0;
    std::string thread_mode = "Auto";
    bool parallel = false;


    // Output
    bool save_output = true;
    std::string output_file = "pi_digits.txt";
    bool overwrite = false;
    std::string save_format = "TXT";


    // Calculation
    std::string algorithm = "Chudnovsky";
    std::string precision_mode = "MPFR";


    // Verification
    bool verify_after = true;
    int verify_level = 1;
    std::string reference_source = "Local";


    // Interface
    bool show_emojis = true;
    bool color_output = true;
    bool verbose = false;
};
