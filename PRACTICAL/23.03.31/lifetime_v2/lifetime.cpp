#include "lifetime.hpp"

#include <algorithm>

#include <utility>
#include <vector>

int main()
{
    using nse::Lifetime;

    fmt::print("Before lambda construction\n");
    auto lambda = [lft = Lifetime{1}]() mutable { lft = Lifetime{2}; };

    fmt::print("Before lambda call\n");
    lambda();
    fmt::print("After lambda call\n");

    std::vector<Lifetime> vec{};
    vec.emplace_back(6);
    vec.emplace_back(4);
    vec.emplace_back(5);
    vec.emplace_back(3);

    fmt::print("Starting sort\n");
    std::sort(vec.begin(), vec.end());
    fmt::print("Ending sort\n");

    auto vec2 = std::move(vec);
}
