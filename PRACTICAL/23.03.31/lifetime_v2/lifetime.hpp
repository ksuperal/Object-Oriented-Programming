#ifndef NSE_LIFETIME_HPP
#define NSE_LIFETIME_HPP

// See https://github.com/lefticus/cpp_weekly/issues/176 for background
// https://www.youtube.com/watch?v=287_oG4CNMc

#include <fmt/format.h>
#include <utility>

namespace nse {

struct Lifetime {
    void print_moved_from() const noexcept;
    auto operator<=>(const Lifetime& other);

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
    fmt::print("\n\n******\n");
    fmt::print("* Total Objects:     {}\n", Lifetime::objects);
    fmt::print("* Move Constructors: {}\n", Lifetime::moves);
    fmt::print("* Copy Constructors: {}\n", Lifetime::copies);
    fmt::print("* Move Assignments:  {}\n", Lifetime::move_assignments);
    fmt::print("* Copy Assignments:  {}\n", Lifetime::copy_assignments);
    fmt::print("* Destructors:       {}\n", Lifetime::destructions);
    fmt::print("* Self Assignments:  {}\n", Lifetime::self_assignments);
    fmt::print("* Comparisons:       {}\n", Lifetime::comparisons);
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
        fmt::print("[moved from] ");
    }

    if (copy) {
        fmt::print("[copy] ");
    }
}

// https://github.com/tvaneerd/cpp20_in_TTs/blob/main/spaceship-operator.md
inline auto Lifetime::operator<=>(const Lifetime& other)
{
    ++comparisons;
    print_moved_from();
    fmt::print(
        "operator<=>(const Lifetime&) {{{} <=> {}}}"
        " [three-way comparison]\n",
        id, other.id);
    return id - other.id;
}

inline Lifetime::Lifetime(int id_) noexcept: id{id_}
{
    ++objects;
    fmt::print("Lifetime(int) {{{}}} [int constructor]\n", id);
}

inline Lifetime::Lifetime() noexcept
{
    ++objects;
    fmt::print("Lifetime() {{{}}} [default constructor]\n", id);
}

inline Lifetime::~Lifetime() noexcept
{
    ++destructions;
    print_moved_from();
    fmt::print("~Lifetime() {{{}}} [destructor]\n", id);
}

inline Lifetime::Lifetime(const Lifetime& other) noexcept
: id{other.id}, moved_from{other.moved_from}, copy{true}
{
    ++copies;
    ++objects;
    print_moved_from();
    fmt::print(
        "Lifetime(const Lifetime&) {{{}}} [copy constructor]\n", id);
}

inline Lifetime::Lifetime(Lifetime&& other) noexcept
: id{other.id},
  moved_from{std::exchange(other.moved_from, true)},
  copy{other.copy}
{
    ++moves;
    ++objects;
    print_moved_from();
    fmt::print("Lifetime(Lifetime&&) {{{}}} [move constructor]\n", id);
}

inline Lifetime& Lifetime::operator=(const Lifetime& other) noexcept
{
    print_moved_from();
    if (&other == this) {
        fmt::print("[self assignment]");
        ++self_assignments;
    }
    else {
        ++copy_assignments;
    }

    fmt::print(
        "operator=(const Lifetime&) {{{} = {}}}"
        " [copy assignment operator]\n",
        id, other.id);
    id = other.id;
    moved_from = other.moved_from;
    copy = true;
    return *this;
}

inline Lifetime& Lifetime::operator=(Lifetime&& other) noexcept
{
    print_moved_from();
    if (&other == this) {
        fmt::print("[self assignment]");
        ++self_assignments;
    }
    else {
        ++move_assignments;
    }

    fmt::print(
        "operator=(Lifetime&&) {{{} = {}}}"
        " [move assignment operator]\n",
        id, other.id);
    id = other.id;
    moved_from = std::exchange(other.moved_from, true);
    copy = other.copy;
    return *this;
}

} // namespace nse

#endif /* NSE_LIFETIME_HPP */
