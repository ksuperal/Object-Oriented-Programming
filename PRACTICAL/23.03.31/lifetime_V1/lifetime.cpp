#include "lifetime.hpp"

#include <algorithm>

#include <utility>
#include <vector>

int main()
{
    using nse::Lifetime;

    std::cout << "Before lambda construction\n";
    auto lambda = [lft = Lifetime{1}]() mutable { lft = Lifetime{2}; };

    std::cout << "Before lambda call\n";
    lambda();
    std::cout << "After lambda call\n";

    std::vector<Lifetime> vec{};
    vec.emplace_back(6);
    vec.emplace_back(4);
    vec.emplace_back(5);
    vec.emplace_back(3);

    std::cout << "Starting sort\n";
    std::sort(vec.begin(), vec.end());
    std::cout << "Ending sort\n";

    auto vec2 = std::move(vec);
}
