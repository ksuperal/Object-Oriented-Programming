#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <typeinfo>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istream;
using std::vector;
using std::sort;

auto extract_attrs(vector<string>& words){
    vector<string> attrs;
    auto it = words.begin();
    while (it != words.end()){
        if (it->find("[[") != string::npos && it->find("]]") != string::npos){
            attrs.push_back(*it);
            it = words.erase(it);
        } else {
            it++;
        }
    }
    return attrs;
}

void print_words(const vector<string>& words, std::ostream& out){
    for (const auto& w: words){
        out << w << " ";
    }
}

void print_words_commas(const vector<string>& words, std::ostream& out){
    for (const auto& w: words){
        out << w << ", ";
    }
}

int main()
{
    const vector<string> test_words{
    "switch", "[[noreturn]]",
    "if", "[[maybe_unused",
    "for", "fallthrough"
    };

    cout << endl;
    auto non_attrs = test_words;
    auto attrs = extract_attrs(non_attrs);
    cout << "Test words: ";
    print_words(test_words, cout);
    cout << endl;
    cout << "Attributes: ";
    print_words(attrs, cout);
    cout << std::endl;
    cout << "Non attributes: ";
    print_words(non_attrs, cout);
    cout << endl;


    cout << endl;
    cout << "Test words: ";
    print_words_commas(test_words, cout);
    cout << endl;
    cout << "Attributes: ";
    print_words_commas(attrs, cout);
    cout << std::endl;
    cout << "Non attributes: ";
    print_words_commas(non_attrs, cout);
    cout << endl;
    return 0;
}