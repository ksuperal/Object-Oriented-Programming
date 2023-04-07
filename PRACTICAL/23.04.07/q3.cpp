#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
    stringstream ss("[1, 2, 3; 4, 5; 6, 7, 8, 9]");
    vector<vector<int>> v;
    string line;
    string line2;
    while (getline(ss, line, ';')) {
        stringstream ss2(line);
        vector<int> v2;
        while (getline(ss2, line2, ',')) {
            if(line2.find('[') != string::npos)
                line2.erase(line2.find('['), 1);
            if(line2.find(']') != string::npos)
                line2.erase(line2.find(']'), 1);
            if(line2.find(' ') != string::npos)
                line2.erase(line2.find(' '), 1);
            v2.push_back(stoi(line2));
        }
        v.push_back(v2);
    }
    cout << "[";
    for (auto i : v) {
        cout << "[";
        for (auto j : i) {
            cout << j << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}