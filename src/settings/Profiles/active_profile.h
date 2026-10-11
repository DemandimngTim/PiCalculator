#pragma once

#include <string>

extern std::string active_profile_path;


bool load_active_profile();

bool save_active_profile(
    const std::string& path
);

void clear_active_profile();
