#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::vector;
using std::list;
using std::copy;

template <class T>
T remove_negative(T& vec)
{   
    T vec2;
    copy(vec.begin(), vec.end(), std::back_inserter(vec2));
    vec2.erase(remove_if(vec2.begin(), vec2.end(), [](double x){return x < 0;}), vec2.end());
    return vec2;
}

int main(){

    vector<double> vec1 {0.8, -5.1, 1.6, -6.5, 10.5};
    auto vec2 = remove_negative(vec1);
    list<double> li1(vec1.rbegin(), vec1.rend());
    auto li2 = remove_negative(li1);

    cout << "vec1: ";
    for (auto x : vec1) cout << x << " ";
    cout << endl;

    cout << "vec2: ";
    for (auto x : vec2) cout << x << " ";
    cout << endl;

    cout << "li1: ";
    for (auto x : li1) cout << x << " ";
    cout << endl;

    cout << "li2: ";
    for (auto x : li2) cout << x << " ";
    cout << endl;

    return 0;
}