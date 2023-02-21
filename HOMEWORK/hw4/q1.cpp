#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <sstream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::vector;


auto split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main(){

    map<string, double> m;
    string cmd;
    string var;
    double number;

    while(true){
        cout << "cmd> ";
        getline(cin, cmd);
        vector<string> tokens = split(cmd, ' ');

        if(tokens[0] == "set"){
            m[tokens[1]] = std::stod(tokens[2]);
        }
        else if(tokens[0] == "get"){
            if(m.find(tokens[1]) != m.end()){
                cout << m[tokens[1]] << endl;
            }
            else{
                cout << "<N/A>" << endl;
            }
        }
        else if(tokens[0] == "add"){
            cout << tokens[1] << " + " << tokens[2] << ": ";
            if(m.find(tokens[1]) != m.end() && m.find(tokens[2]) != m.end()){
                cout << m[tokens[1]] + m[tokens[2]] << endl;
            }
            else{
                cout << "<N/A>" << endl;
            }
        }
        else if(tokens[0] == "sub"){
            cout << tokens[1] << " - " << tokens[2] << ": ";
            if(m.find(tokens[1]) != m.end() && m.find(tokens[2]) != m.end()){
                cout << m[tokens[1]] - m[tokens[2]] << endl;
            }
            else{
                cout << "<N/A>" << endl;
            }
        }
    }

    return 0;
}