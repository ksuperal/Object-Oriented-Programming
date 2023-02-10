#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::vector;
using std::list;
using std::copy;
using std::string;

template <class T>
T remove_negative(T& vec)
{   
    T vec2;
    copy(vec.begin(), vec.end(), std::back_inserter(vec2));
    vec2.erase(remove_if(vec2.begin(), vec2.end(), [](double x){return x < 0;}), vec2.end());
    return vec2;
}

template <class T>
bool all_zeroes(T begin, T end)
{
    return all_of(begin, end, [](int x){return x == 0;});
}

template <class T>
string str_join(string sep, T begin, T end)
{
    string str;
    for (auto it = begin; it != end; it++) {
        str += *it;
        if (std::next(it) != end) {
            str += sep;
        }
    }
    return str;
}

int main(){

    cout << "======================2.1======================" << endl;

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

    cout << endl;
    cout << "======================2.2======================" << endl;

    vector<int> vec1_2{1, 0, 2, 3};
    vector<int> vec2_2(10);
    bool z1 = all_zeroes(vec1_2.begin(), vec1_2.end());
    bool z2 = all_zeroes(vec2_2.begin(), vec2_2.end());
    list<int> li1_2(vec1_2.rbegin(), vec1_2.rend());
    list<int> li2_2(10);
    bool zz1 = all_zeroes(li1_2.begin(), li1_2.end());
    bool zz2 = all_zeroes(li2_2.begin(), li2_2.end());

    cout << "z1: " << z1 << endl;
    cout << "z2: " << z2 << endl;
    cout << "zz1: " << zz1 << endl;
    cout << "zz2: " << zz2 << endl;
    
    cout << endl;
    cout << "======================2.3======================" << endl;

    auto words = vector<string>{"C", "Rust", "C++", "Python"};
    auto str1 = str_join(string(", "), words.begin(), words.end());
    auto words2 = list<string>(words.rbegin(), words.rend());
    auto str2 = str_join(string(", "), words2.begin(), words2.end());

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    return 0;
}