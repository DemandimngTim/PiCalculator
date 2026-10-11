#include "profile_writer.h"

#include <fstream>
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;

static inline int b(bool value)
{
    return value ? 1 : 0;
}

bool save_profile(
    const Profile &p,
    const string &path
)
{
    fs::path file(path);

    if(!file.parent_path().empty())
    {
        fs::create_directories(file.parent_path());
    }

    ofstream out(path, ios::trunc);

    if(!out)
        return false;

    // ----------------------------
    // General
    // ----------------------------

    out << "name=" << p.name << '\n';

    // ----------------------------
    // Performance
    // ----------------------------

    out << "tree_depth="     << p.tree_depth  << '\n';
    out << "thread_mode="    << p.thread_mode << '\n';
    out << "parallel="       << b(p.parallel) << '\n';

    // ----------------------------
    // Output
    // ----------------------------

    out << "save_output="    << b(p.save_output) << '\n';
    out << "output_file="    << p.output_file    << '\n';
    out << "overwrite="      << b(p.overwrite)   << '\n';
    out << "save_format="    << p.save_format    << '\n';

    // ----------------------------
    // Calculation
    // ----------------------------

    out << "algorithm="      << p.algorithm      << '\n';
    out << "precision_mode=" << p.precision_mode << '\n';

    // ----------------------------
    // Verification
    // ----------------------------

    out << "verify_after="     << b(p.verify_after) << '\n';
    out << "verify_level="     << p.verify_level    << '\n';
    out << "reference_source=" << p.reference_source << '\n';

    // ----------------------------
    // Interface
    // ----------------------------

    out << "show_emojis=" << b(p.show_emojis) << '\n';
    out << "color_output=" << b(p.color_output) << '\n';
    out << "verbose=" << b(p.verbose) << '\n';

    out.flush();

    return out.good();
}
