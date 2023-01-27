#include "style.hpp"

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

    cout << std::setw(15) << std::left << " " << std::setw(15) << std::left << "unstylize" << std::setw(15) << std::left << "stylize" << endl;

    for (const auto& w: words) {
        // std::cout << unstylize(w) << std::endl;
        cout << std::setw(15) << std::left << w << std::setw(15) << std::left << STYLE::unstylize(w) << std::setw(15) << std::left << STYLE::stylize(w) << endl;
    }
    

}