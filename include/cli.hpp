#pragma once
#include <string>

namespace cli{
    char read_choice(const std::string& prompt, const std::string& allowed);
    int read_int(const std::string& prompt, int min_val, int max_value);
    double read_double(const std::string& prompt);
}