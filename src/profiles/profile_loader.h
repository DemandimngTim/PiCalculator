#pragma once

#include "profile.h"
#include <string>


bool load_profile(
    Profile &profile,
    const std::string &path
);
