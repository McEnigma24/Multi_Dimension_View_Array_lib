#include "__preprocessor__.h"
#include "__operations_counter__.h"
#include "__time_stamp__.h"

// NORMAL //
namespace CORE
{
    void clear_terminal()
    {
#ifdef _WIN32
        int status = std::system("cls"); // Windows
#else
        int status = std::system("clear"); // Linux / macOS
#endif
    }

    u64 convert_2d_to_1d(u64 x, u64 y, u64 WIDTH) { return (y * WIDTH) + x; }

    namespace str
    {
        std::vector<std::string> split_string(const std::string& input, char delimiter)
        {
            std::vector<std::string> result;
            std::string segment;
            std::istringstream stream(input);

            while (std::getline(stream, segment, delimiter))
            {
                result.push_back(segment);
            }

            return result;
        }
        std::string to_lower_case(const std::string& input)
        {
            std::string result;
            result.reserve(input.size());
            for (char c : input)
            {
                result += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
            }

            return result;
        }
    }; // namespace str

    namespace vec
    {
        template <typename T>
        void print_on_by_one(const std::vector<T>& vec)
        {
            for (auto& v : vec)
            {
                cout << v << "\n";
            }
        }

        template <typename T>
        bool contains(const T& value, const std::vector<T>& vec)
        {
            return std::find(vec.begin(), vec.end(), value) != vec.end();
        }

        template <typename T>
        void remove_by_value(const T& value, std::vector<T>& vec)
        {
            auto it = std::find(vec.begin(), vec.end(), value);

            if (it != vec.end())
            {
                vec.erase(it);
            }
        }
    }; // namespace vec
};     // namespace CORE

// __time_stamp__ //
namespace CORE
{
    std::chrono::steady_clock::time_point time_stamp_last_time = std::chrono::steady_clock::now();

    std::string get_current_local_time()
    {
        auto now = std::chrono::system_clock::now();
        std::time_t czas = std::chrono::system_clock::to_time_t(now);
        std::tm* aktualnyCzas = std::localtime(&czas);

        std::ostringstream oss;
        oss << std::put_time(aktualnyCzas, "%H:%M:%S");
        return oss.str();
    }

    std::string calculate_time_difference()
    {
        auto now = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(now - time_stamp_last_time);
        time_stamp_last_time = now; // Aktualizuj czas ostatniego pomiaru

        // Konwersja na jednostki czasu
        long long nanoseconds = duration.count();
        long long hours = nanoseconds / (1000LL * 1000 * 1000 * 60 * 60);
        nanoseconds %= (1000LL * 1000 * 1000 * 60 * 60);
        long long minutes = nanoseconds / (1000LL * 1000 * 1000 * 60);
        nanoseconds %= (1000LL * 1000 * 1000 * 60);
        long long seconds = nanoseconds / (1000LL * 1000 * 1000);
        nanoseconds %= (1000LL * 1000 * 1000);
        long long milliseconds = nanoseconds / (1000LL * 1000);
        nanoseconds %= (1000LL * 1000);
        long long microseconds = nanoseconds / 1000LL;
        nanoseconds %= 1000LL;

        bool show_all_other = false;
        std::ostringstream oss;
        if (hours > 0)
        {
            show_all_other = true;
            oss << hours << "h ";
        }
        if (minutes > 0 || show_all_other)
        {
            show_all_other = true;
            oss << minutes << "m ";
        }
        if (seconds > 0 || show_all_other)
        {
            show_all_other = true;
            oss << seconds << "s ";
        }
        if (milliseconds > 0 || show_all_other)
        {
            show_all_other = true;
            oss << milliseconds << "mili ";
        }
        if (microseconds > 0 || show_all_other)
        {
            show_all_other = true;
            oss << microseconds << "micro ";
        }
        if (nanoseconds > 0 || show_all_other)
        {
            show_all_other = true;
            oss << nanoseconds << "nano ";
        }
        return oss.str();
    }

}; // namespace CORE

// __operations_counter__ //
#ifdef OPERATION_COUNTER_ACTIVE
namespace CORE
{
    Global_Operation_Counter::Counters::Counters() { memset(this, 0, sizeof(*this)); }
    void Global_Operation_Counter::Counters::show()
    {
        var(counter_add);
        var(counter_sub);
        var(counter_multi);
        var(counter_dev);
        var(counter_mod);
        var(counter_comparisons);
    }

    void Global_Operation_Counter::Counters::add() { counter_add++; }
    void Global_Operation_Counter::Counters::sub() { counter_sub++; }
    void Global_Operation_Counter::Counters::multi() { counter_multi++; }
    void Global_Operation_Counter::Counters::dev() { counter_dev++; }
    void Global_Operation_Counter::Counters::mod() { counter_mod++; }
    void Global_Operation_Counter::Counters::comparison() { counter_comparisons++; }

    CORE::Global_Operation_Counter::Counters CORE::Global_Operation_Counter::counters;

    void Global_Operation_Counter::reset() { memset(&counters, 0, sizeof(counters)); }
    void Global_Operation_Counter::show()
    {
        nline;
        line("< Operation Counters >");
        counters.show();
        nline;
    }
};     // namespace CORE
#endif // OPERATION_COUNTER_ACTIVE