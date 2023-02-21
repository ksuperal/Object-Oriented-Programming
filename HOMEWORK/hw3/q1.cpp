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

auto split(const string& s, const string& delim) {
    vector<string> result;
    size_t start = 0;
    size_t end = s.find(delim);
    while (end !=  string::npos) {
        result.push_back(s.substr(start, end - start));
        start = end + delim.length();
        end = s.find(delim, start);
    }
    result.push_back(s.substr(start, end));
    return result;
}

auto combine_iterleaving(const vector<vector<string>> vec){
    vector<string> combined;
    int min = std::min(vec[0].size(), vec[1].size());
    for(int i = 0; i < min; i++){
        combined.push_back(vec[0][i]);
        combined.push_back(vec[1][i]);
    }

    if (vec[0].size() > vec[1].size()){
        for(int i = min; i < vec[0].size(); i++){
            combined.push_back(vec[0][i]);
        }
    } else {
        for(int i = min; i < vec[1].size(); i++){
            combined.push_back(vec[1][i]);
        }
    }
    return combined;
}

int main(){

    // Open the file
    ifstream in("data1.txt");
    if (!in) {
        cout << "Cannot open input file." << endl;
        return 1;
    }

    // Read the file
    string line;
    vector<string> lines;
    while (getline(in, line)) {
        lines.push_back(line);
    }

    // Close the file
    in.close();

    vector<string> nums_nonsplit;
    nums_nonsplit = split(lines[0], "; ");

    vector<vector<string>> nums;

    for(int i = 0; i < nums_nonsplit.size(); i++){
        nums.push_back(split(nums_nonsplit[i], " "));
    }

    int min = std::min(nums[0].size(), nums[1].size());

    // combine two vectors iterleaving the data
    vector<string> combined = combine_iterleaving(nums);
    cout << "================1.1================" << endl;
    for(auto i : combined){
        cout << i << " ";
    }
    cout << endl;

    cout << endl << "================1.2================" << endl;

    // for every two numbers multiply them and add
    int sum = 0;
    for(int i = 0; i < min; i++){
        cout << nums[0][i] << " * " << nums[1][i] << " = " << std::stoi(nums[0][i]) * std::stoi(nums[1][i]) << endl;
        sum += std::stoi(nums[0][i]) * std::stoi(nums[1][i]);
    }
    cout << sum << endl;

    cout << endl << "================1.3================" << endl;

    // cartesian product
    for(int i = 0; i < nums[0].size(); i++){
        for(int j = 0; j < nums[1].size(); j++){
            cout << "(" << nums[0][i] << ", " << nums[1][j] << "), ";
        }
        cout << endl;
    }

    return 0;
}