#pragma once
#include "__preprocessor__.h"

#define time_stamp(x)                                                                                                  \
    std::cout << "\nTIME_STAMP: " << setw(50) << left << x << right << " " << CORE::get_current_local_time() << " (+ " \
              << CORE::calculate_time_difference() << ")\n";

#define time_stamp_reset() CORE::calculate_time_difference();
// #define time_stamp(x)

namespace CORE
{
    std::string get_current_local_time();
    std::string calculate_time_difference();
} // namespace CORE