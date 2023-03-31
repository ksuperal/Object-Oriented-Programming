#ifndef NSE_LIFETIME_HPP
#define NSE_LIFETIME_HPP

// See https://github.com/lefticus/cpp_weekly/issues/176 for background
// https://www.youtube.com/watch?v=287_oG4CNMc

#include <iostream>
#include <utility>

namespace nse {

struct Lifetime {
    void print_moved_from() const noexcept;
    friend auto compare_three_way(const Lifetime& l1, const Lifetime& l2);
    friend auto operator==(const Lifetime& l1, const Lifetime& l2);
    friend auto operator!=(const Lifetime& l1, const Lifetime& l2);
    friend auto operator<(const Lifetime& l1, const Lifetime& l2);
    friend auto operator<=(const Lifetime& l1, const Lifetime& l2);
    friend auto operator>(const Lifetime& l1, const Lifetime& l2);
    friend auto operator>=(const Lifetime& l1, const Lifetime& l2);

    Lifetime() noexcept;
    explicit Lifetime(int id_) noexcept;

    ~Lifetime() noexcept;
    Lifetime(const Lifetime& other) noexcept;
    Lifetime(Lifetime&& other) noexcept;

    Lifetime& operator=(const Lifetime& other) noexcept;
    Lifetime& operator=(Lifetime&& other) noexcept;

    static inline std::size_t objects{0};           // NOLINT
    static inline std::size_t moves{0};             // NOLINT
    static inline std::size_t copies{0};            // NOLINT
    static inline std::size_t move_assignments{0};  // NOLINT
    static inline std::size_t copy_assignments{0};  // NOLINT
    static inline std::size_t destructions{0};      // NOLINT
    static inline std::size_t self_assignments{0};  // NOLINT
    static inline std::size_t comparisons{0};       // NOLINT
private:
    int id = -1;
    bool moved_from = false;
    bool copy = false;
};

inline void dump_counters()
{
    std::cout << "\n\n******\n";
    std::cout << "* Total Objects:     " << Lifetime::objects << '\n';
    std::cout << "* Move Constructors: " << Lifetime::moves << '\n';
    std::cout << "* Copy Constructors: " << Lifetime::copies << '\n';
    std::cout << "* Move Assignments:  "
              << Lifetime::move_assignments << '\n';
    std::cout << "* Copy Assignments:  "
              << Lifetime::copy_assignments << '\n';
    std::cout << "* Destructors:       " << Lifetime::destructions << '\n';
    std::cout << "* Self Assignments:  "
              << Lifetime::self_assignments << '\n';
    std::cout << "* Comparisons:       " << Lifetime::comparisons << '\n';
};

struct Dump_Counters {
    Dump_Counters() = default;
    Dump_Counters(const Dump_Counters&) = delete;
    Dump_Counters(Dump_Counters&&) = delete;
    Dump_Counters &operator=(const Dump_Counters&) = delete;
    Dump_Counters &operator=(Dump_Counters&&) = delete;

    ~Dump_Counters() { dump_counters(); }
};

// a static global to dump all of the counts as the program shuts down
inline const Dump_Counters LTCD;  // NOLINT

inline void Lifetime::print_moved_from() const noexcept
{
    if (moved_from) {
        std::cout << "[moved from] ";
    }

    if (copy) {
        std::cout << "[copy] ";
    }
}

// https://github.com/tvaneerd/cpp20_in_TTs/blob/main/spaceship-operator.md
inline auto compare_three_way(const Lifetime& obj1, const Lifetime& obj2)
{
    ++obj1.comparisons;
    obj1.print_moved_from();
    std::cout << ">> ";
    std::cout << "compare_three_way(const Lifetime&, const Lifetime&) {"
              << obj1.id << " <=> " << obj2.id
              << "} [three-way comparison]\n";
    return obj1.id - obj2.id;
}

inline auto operator==(const Lifetime& l1, const Lifetime& l2)
{
    std::cout << "operator==(const Lifetime& l1, const Lifetime& l2)\n";
    return compare_three_way(l1, l2) == 0;
}

inline auto operator!=(const Lifetime& l1, const Lifetime& l2)
{
    std::cout << "operator!=(const Lifetime& l1, const Lifetime& l2)\n";
    return compare_three_way(l1, l2) != 0;
}

inline auto operator<(const Lifetime& l1, const Lifetime& l2)
{
    std::cout << "operator<(const Lifetime& l1, const Lifetime& l2)\n";
    return compare_three_way(l1, l2) < 0;
}

inline auto operator<=(const Lifetime& l1, const Lifetime& l2)
{
    std::cout << "operator<=(const Lifetime& l1, const Lifetime& l2)\n";
    return compare_three_way(l1, l2) <= 0;
}

inline auto operator>(const Lifetime& l1, const Lifetime& l2)
{
    std::cout << "operator>(const Lifetime& l1, const Lifetime& l2)\n";
    return compare_three_way(l1, l2) > 0;
}

inline auto operator>=(const Lifetime& l1, const Lifetime& l2)
{
    std::cout << "operator>=(const Lifetime& l1, const Lifetime& l2)\n";
    return compare_three_way(l1, l2) >= 0;
}

inline Lifetime::Lifetime(int id_) noexcept: id{id_}
{
    ++objects;
    std::cout << "Lifetime(int) {" << id << "} [int constructor]\n";
}

inline Lifetime::Lifetime() noexcept
{
    ++objects;
    std::cout << "Lifetime() {" << id << "} [default constructor]\n";
}

inline Lifetime::~Lifetime() noexcept
{
    ++destructions;
    print_moved_from();
    std::cout << "~Lifetime() {" << id << "} [destructor]\n";
}

inline Lifetime::Lifetime(const Lifetime& other) noexcept
: id{other.id}, moved_from{other.moved_from}, copy{true}
{
    ++copies;
    ++objects;
    print_moved_from();
    std::cout << "Lifetime(const Lifetime&) {" << id
              << "} [copy constructor]\n";
}

inline Lifetime::Lifetime(Lifetime&& other) noexcept
: id{other.id},
  moved_from{std::exchange(other.moved_from, true)},
  copy{other.copy}
{
    ++moves;
    ++objects;
    print_moved_from();
    std::cout << "Lifetime(Lifetime&&) {" << id
              << "} [move constructor]\n";
}

inline Lifetime& Lifetime::operator=(const Lifetime& other) noexcept
{
    print_moved_from();
    if (&other == this) {
        std::cout << "[self assignment]";
        ++self_assignments;
    }
    else {
        ++copy_assignments;
    }

    std::cout << "operator=(const Lifetime&) {" << id << " = " << other.id
              << "} [copy assignment operator]\n";
    id = other.id;
    moved_from = other.moved_from;
    copy = true;
    return *this;
}

inline Lifetime& Lifetime::operator=(Lifetime&& other) noexcept
{
    print_moved_from();
    if (&other == this) {
        std::cout << "[self assignment]";
        ++self_assignments;
    }
    else {
        ++move_assignments;
    }

    std::cout << "operator=(Lifetime&&) {" << id << " = " << other.id
              << "} [move assignment operator]\n";
    id = other.id;
    moved_from = std::exchange(other.moved_from, true);
    copy = other.copy;
    return *this;
}

} // namespace nse

#endif /* NSE_LIFETIME_HPP */
