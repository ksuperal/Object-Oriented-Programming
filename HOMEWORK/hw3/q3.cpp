#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::istream;

istream& read_color(istream& in, std::vector<string>& vec){
    if (in){
        vec.clear();

        string x;
        while (in >> x){
            vec.push_back(x);
        }

        in.clear();
    }
    return in;
}

int main(){

    vector<string> colors;
    cout << "Enter colors: " << endl;
    read_color(cin, colors);

    vector<string> color_stars;
    vector<string> plain_color;

    for(auto c: colors){
        if (c.front() == '*' && c.back() == '*'){
            color_stars.push_back(c);
        } else {
            plain_color.push_back(c);
        }
    }

    // catesian product
    for (auto c: color_stars){
        for (auto p: plain_color){
            cout << "(" << c << ", " << p << "),";
        }
        cout << endl;
    }

    return 0;
}