#pragma once
#include <chrono>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <time.h>
#include <vector>

using namespace std;

#define path_run_time_config "../run_time_config"

#define var(x) cout << #x << " = " << x << '\n';
#define varr(x) cout << #x << " = " << x << ' ';
#define line(x) cout << x << '\n';
#define linee(x) cout << x << ' ';
#define nline cout << '\n';

int my_sum(int a, int b);

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#define null nullptr
#define pow2(x) ((x) * (x))
#define pow3(x) ((x) * (x) * (x))
#define base_0(x) (x - 1)

#define c_init(x) x(_##x)
#define cc_init(x) this->x = x;
#define member_assign(a, b, member) a.member = b.member;
#define THIS_OTHER(x) this->x = other.x;

#define sizeof_imp(x)                                                                                                                                \
    {                                                                                                                                                \
        cout << ": " << std::setprecision(1) << fixed << (x) / 1000000000 << "gb " << (x) / 1000000 << "mb " << (x) / 1000 << "kb "                  \
             << std::setprecision(0) << (x) << "b \n";                                                                                               \
    }
#define show_sizeof(class)                                                                                                                           \
    {                                                                                                                                                \
        size_t size = sizeof(class);                                                                                                                 \
        cout << #class;                                                                                                                              \
        sizeof_imp((float)size);                                                                                                                     \
    }
#define show_sizeof_many(class, count)                                                                                                               \
    {                                                                                                                                                \
        size_t size = sizeof(class) * count;                                                                                                         \
        cout << #class;                                                                                                                              \
        sizeof_imp((float)size);                                                                                                                     \
    }

#define call_print(x) x.print(#x);

#define add_endl(string, how_many)                                                                                                                   \
    for (u16 i{}; i < how_many; i++)                                                                                                                 \
        string += "\n";

#define OUTPUT_TO_FILE(path, content)                                                                                                                \
    {                                                                                                                                                \
        ofstream file(path);                                                                                                                         \
        file << content;                                                                                                                             \
        file.close();                                                                                                                                \
    }

#define FATAL_ERROR(x)                                                                                                                               \
    {                                                                                                                                                \
        const string fatal = "FATAL ERROR - " + std::to_string(__LINE__) + " : " + __FILE__ + " -> " + x + "\n";                                     \
        cout << fatal;                                                                                                                               \
        exit(EXIT_FAILURE);                                                                                                                          \
    }
#define ASSERT_ER_IF_TRUE(x)                                                                                                                         \
    if (x) FATAL_ERROR(#x)
#define ASSERT_ER_IF_NULL(x)                                                                                                                         \
    if (x == null) FATAL_ERROR(#x)

#define check_nan(x)                                                                                                                                 \
    if (std::isnan(x)) { FATAL_ERROR("found it"); }

#define SAFETY_CHECK(x) x;

#define delay_input std::this_thread::sleep_for(std::chrono::milliseconds(50));
#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));

namespace CORE
{
    void clear_terminal();
    u64 convert_2d_to_1d(u64 x, u64 y, u64 WIDTH);

    namespace str
    {
        std::vector<std::string> split_string(const std::string& input, char delimiter);
        std::string to_lower_case(const std::string& input);
    }; // namespace str

    namespace vec
    {
        template <typename T>
        void print_on_by_one(const std::vector<T>& vec);

        template <typename T>
        bool contains(const T& value, const std::vector<T>& vec);

        template <typename T>
        void remove_by_value(const T& value, std::vector<T>& vec);
    }; // namespace vec
};     // namespace CORE

    // #define OPERATION_COUNTER_ACTIVE
    // #define OPERATION_COUNTER_SHOW_LOG

#include "__operations_counter__.h"

// Global_Operation_Counter::show();
// Global_Operation_Counter::reset();