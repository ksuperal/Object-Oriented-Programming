#include "random.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

template<typename T_>
inline constexpr
    T_ pi_v{3.141592653589793238462643383279502884L};

inline constexpr double pi = pi_v<double>;

int main()
{
    constexpr double rnd_min = -1.0, rnd_max = 1.0;
    Rand_double rnd{rnd_min, rnd_max};

    std::random_device rd;
    rnd.seed(rd());
    std::cout << std::fixed << std::setprecision(5);

    // double x2 = rnd();
    // double y2 = rnd();
    // std::cout << "Point #2: (" << x2 << ", " << y2 << ")";
    // std::cout << std::endl;

    int N = 1000000;
    int N1 = 0;

    for(int i = 0; i < N; i++){
        double x1 = rnd();
        double y1 = rnd();
        // std::cout << "Point #1: (" << x1 << ", " << y1 << ")\n";
        double distance = std::sqrt(std::pow(x1, 2) + std::pow(y1, 2));
        // std::cout << "Distance: " << distance << std::endl;
        if(distance >= -1 && distance <= 1){
            N1++;
        }
    }

    std::cout << std::fixed << std::setprecision(7);
    
    double pi_est = 4.0 * N1 / N;
    double relative_err = std::abs(pi - pi_est) / pi;
    double percentage_err = relative_err * 100;

    std::cout << "Pi Estimate: " << pi_est << std::endl;
    std::cout << "Relative Error: " << relative_err << std::endl;
    std::cout << "Percentage Error: " << percentage_err << std::endl;


    return 0;
}