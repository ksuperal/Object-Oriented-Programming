#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string unstylize(string m){

    // remove the "*" in the string
    if (m.front() == '*' && m.back() == '*' && m.size() > 1){
        m.erase(0, 1);
        m.erase(m.size() - 1, 1);
    }
    // return the string

    return m;
}

string stylize(string m){

    // remove the "*" in the string
    if (m.front() == '*' && m.back() == '*' && m.size() > 1){
        m.erase(0, 1);
        m.erase(m.size() - 1, 1);
        return "<strong>" + m + "</strong>";
    }
    // return the string

    return m;
}

auto split(string m, char d){
    std::vector<string> result;
    string line;
    std::stringstream stream(m);

    while (std::getline(stream, line, d)){
        result.push_back(line);
    }

    return result;
}

int main(){
    // auto words = {"C", "**", "*C++*", "*Java", "*Python*", "Rust*"};
    // for (const auto& w: words) {
    //     // std::cout << unstylize(w) << std::endl;
    //     std::cout << stylize(w) << std::endl;
    // }
    // C *C++* Rust* *Python* * *Java

    string m;
    cout << "Enter the string: ";
    std::getline(cin, m);
    auto words = split(m, ' ');

    cout << std::setw(15) << std::left << " " << std::setw(15) << std::left << "unstylize" << std::setw(15) << std::left << "stylize" << endl;

    for (const auto& w: words) {
        // std::cout << unstylize(w) << std::endl;
        cout << std::setw(15) << std::left << w << std::setw(15) << std::left << unstylize(w) << std::setw(15) << std::left << stylize(w) << endl;
    }
    

}
