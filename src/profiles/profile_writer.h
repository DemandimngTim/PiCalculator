#pragma once

#include "profile.h"
#include <string>

bool save_profile(
    const Profile &profile,
    const std::string &path
);
