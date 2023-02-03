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
    int n = words.size();
    for (int i = 0; i < n; i++){
        out << words[i];
        if (i < n - 1){
            out << ", ";
        }
    }
}

auto extract_attrs2(const vector<string>& words, vector<string>& attrs, vector<string>& non_attrs){
    for (const auto& w: words){
        if (w.find("[[") != string::npos && w.find("]]") != string::npos){
            attrs.push_back(w);
        } else {
            non_attrs.push_back(w);
        }
    }
}

std::ostream& print_words_new(std::ostream& out, const vector<string>& words){
    for (const auto& w: words){
        out << w << " ";
    }
    return out;
}

std::ostream& print_words_commas_new(std::ostream& out, const vector<string>& words){
    int n = words.size();
    for (int i = 0; i < n; i++){
        out << words[i];
        if (i < n - 1){
            out << ", ";
        }
    }
    return out;
}

int main()
{
    cout << endl;
    cout << "=====================2.3=====================" << endl;
    const vector<string> test_words{
    "switch", "[[noreturn]]",
    "if", "[[maybe_unused",
    "for", "fallthrough"
    };

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

    cout << endl;
    cout << "=====================2.4=====================" << endl;

    vector<string> attrs_new, non_attrs_new;
    extract_attrs2(
    test_words, attrs_new, non_attrs_new);
    cout << "Test words: ";
    print_words_new(cout, test_words) << endl;
    cout << "Attributes: ";
    print_words_new(cout, attrs_new) << endl;
    cout << "Non attributes: ";
    print_words_new(cout, non_attrs_new) << endl;
    cout << "Attributes: ";
    print_words_new(cout, attrs_new) << endl;

    cout << endl;
    cout << "Test words: ";
    print_words_commas_new(cout, test_words) << endl;
    cout << "Attributes: ";
    print_words_commas_new(cout, attrs_new) << endl;
    cout << "Non attributes: ";
    print_words_commas_new(cout, non_attrs_new) << endl;
    cout << "Attributes: ";
    print_words_commas_new(cout, attrs_new) << endl;
    
    return 0;
}