#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <typeinfo>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istream;

istream& read_hw(istream& in, std::vector<string>& vec){

    if (in){
        vec.clear();

        string x;
        while (in >> x){
            vec.push_back(x);
        }
    }
    return in;
}

double max(const std::vector<double>& vec){
    double max = 0;
    for (const auto& h: vec){
        if (h > max){
            max = h;
        }
    }
    return max;
}

int main(){
    std::vector<string> score;

    cout << "Enter the score, End the loop by pressing Ctrl+Z then Enter: ";

    read_hw(cin, score);
    std::vector<double> score_d;
    for (const auto& h: score){
        try {
            double x = std::stod(h);
            score_d.push_back(x);
        } catch (std::invalid_argument& e){
            cout << max(score_d) << endl;
            cout << h;
        }
    }

   
}
