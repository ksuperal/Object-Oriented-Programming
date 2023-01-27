#include "svgtag.hpp"

int main()
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_real_distribution<double> dist{-1, 1};

    int N;
    cout << "Enter the N value: ";
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        double x = SVG::map(dist(rng), -1, 1, 0, 500);
        
        double y = SVG::map(dist(rng), -1, 1, 0, 500);
        
        cout << SVG::circle_tag(x, y) << endl;
    }
}