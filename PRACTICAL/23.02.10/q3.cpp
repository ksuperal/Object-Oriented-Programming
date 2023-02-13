#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::vector;
using std::list;
using std::copy;
using std::string;
using std::istream;
using std::map;

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

map<string, double> name_amount(vector<string> name, vector<double> amount){
    map<string, double> name_amount;
    for (int i = 0; i < name.size(); i++){
        if (name_amount.find(name[i]) != name_amount.end()){
            name_amount[name[i]] += amount[i];
        } else {
            name_amount[name[i]] = amount[i];
        }
    }
    return name_amount;
}

map<string, string> name_amountcomma(vector<string> name, vector<int> amount){
    map<string, string> name_amountcomma;
    for (int i = 0; i < name.size(); i++){
        if (name_amountcomma.find(name[i]) != name_amountcomma.end()){
            name_amountcomma[name[i]] += ", " + std::to_string(amount[i]);
        } else {
            name_amountcomma[name[i]] = std::to_string(amount[i]);
        }
    }
    return name_amountcomma;
}

int main(){

    cout << "======================3.1======================" << endl;
    cout << "Enter the list of word and number: ";
    vector<string> input;
    read_input(cin, input);

    vector<string> name;
    vector<double> amount;
    for (const auto& h: input){
        try {
            double x = std::stod(h);
            amount.push_back(x);
        } catch (std::invalid_argument& e){
            name.push_back(h);
        }
    }

    map<string, double> out = name_amount(name, amount);
    for (const auto& h: out){
        cout << h.first << " " << h.second << endl;
    }

    // cout << endl;
    // cout << "======================3.2======================" << endl;
    // cout << "Enter the list of word and number: ";
    // vector<string> input;
    // read_input(cin, input);

    // vector<string> name;
    // vector<int> amount;
    // for (const auto& h: input){
    //     try {
    //         int x = std::stoi(h);
    //         amount.push_back(x);
    //     } catch (std::invalid_argument& e){
    //         name.push_back(h);
    //     }
    // }
    // map<string, string> out = name_amountcomma(name, amount);
    // for (const auto& h: out){
    //     cout << h.first << " " << h.second << endl;
    // }

    return 0;
}