#include <string>
class City{
public:
    std::string name() { return n; }
    double temperature() const { return temp; }
    City()
    {
        n = "Unknown";
        temp = 0.0;
    }
    City(double t)
        : temp{t}, n("Unknown") {}

private:
    std::string n;
    double temp;
};
double test1(City c)
{
    return c.temperature();
}
double test2(const City &c)
{
    return c.temperature();
}
City test3() { return City(34.5); }
#include <iostream>
int main()
{
    City c;
    std::cout << test1(c) << std::endl;
    std::cout << test2(c) << std::endl;
    std::cout << test3().temperature()
              << std::endl
              << std::endl;
    std::cout << test1(15.2) << std::endl;
    std::cout << test2(25.4) << std::endl;
}