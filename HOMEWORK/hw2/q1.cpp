#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

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
    // C *C++* Rust* *Python* * *Java

    string m;
    cout << "Enter the string: ";
    std::getline(cin, m);
    auto words = split(m, ' ');

    // 1.1
    for (const auto& w: words) {
        std::cout << unstylize(w) << std::endl;
    }

    std::cout << std::endl;

    // 1.2
    auto words2 = words;
    std::reverse(words2.begin(), words2.end());
    for (const auto& w: words2) {
        std::cout << unstylize(w) << std::endl;
    }

    std::cout << std::endl;

    // 1.3
    auto words3 = words;
    std::vector<string> new_vec;
    
    for (const auto& w: words3) {
        new_vec.push_back(unstylize(w));
    }

    std::sort(new_vec.begin(), new_vec.end());
    for (const auto& w: new_vec) {
        std::cout << w << std::endl;
    }
}