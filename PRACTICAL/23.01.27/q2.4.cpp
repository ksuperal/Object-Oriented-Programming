#include "style.hpp"
#include <fstream>

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

    std::ofstream out("test.html");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());

    cout << "<table>" << endl;
    cout << "<tr>" << endl;
    cout << "<th></th>" << endl;
    cout << "<th>Unstylized</th>" << endl;
    cout << "<th>Stylized</th>" << endl;
    cout << "</tr>" << endl;

    for (const auto& w: words) {
        // std::cout << unstylize(w) << std::endl;
        cout << "<tr>" << endl;
        cout << "<td>" << w << "</td>" << endl;
        cout << "<td>" << STYLE::unstylize(w) << "</td>" << endl;
        cout << "<td>" << STYLE::stylize(w) << "</td>" << endl;
        cout << "</tr>" << endl;
    }

    cout << "</table>" << endl;
    

}