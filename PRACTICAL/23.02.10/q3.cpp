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
using std::istream;

istream& read_input(istream& in, vector<string>& vec){

    if (in){
        vec.clear();

        string x;
        while (in >> x){
            vec.push_back(x);
        }
    }
    return in;
}

int main(){

    cout << "======================3.1======================" << endl;
    cout << "Enter the list of word and number: ";
    vector<string> input;
    read_input(cin, input);

    for (const auto& h: input){
        cout << h << " ";
    }

    vector<string> word;
    vector<double> number;
    for (const auto& h: input){
        try {
            double x = std::stod(h);
            number.push_back(x);
        } catch (std::invalid_argument& e){
            word.push_back(h);
        }
    }

    cout << endl << "The list of word: " << endl;

    return 0;
}