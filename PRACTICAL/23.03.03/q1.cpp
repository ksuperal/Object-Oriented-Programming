#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;

string substitute(string text, string word, string rep){
    string new_text = "";
    int i = 0;
    if (word == "") return text;

    while (i < text.length()){
        if (text.substr(i, word.length()) == word){
            new_text += rep;
            i += word.length();
        } else {
            new_text += text[i];
            i++;
        }
    }
    return new_text;
}

char* substitute_cstyle(char* text, char* word, char* rep){

    int len = 0;
    while(*(text+len) != '\0'){
        len++;
    }

    int word_len = 0;
    while (*(word+word_len) != '\0') {
        word_len++;
    }

    int rep_len = 0;
    while (*(rep+rep_len) != '\0') {
        rep_len++;
    }

    if (word_len == 0) return text;

    char* new_text = new char[len + 1];

    int i = 0;
    int j = 0;
    while (i < len) {
        bool match = true;
        for (int k = 0; k < word_len; k++) {
            if (*(text+i+k) != *(word+k)) {
                match = false;
                break;
            }
        }

        if (match) {
            for (int k = 0; k < rep_len; k++) {
                *(new_text+j) = *(rep+k);
                j++;
            }
            i += word_len;
        } else {
            *(new_text+j) = *(text+i);
            i++;
        }
    }

    *(new_text+j) = '\0';

    return new_text;
}

vector<pair<double, double>> create_pairs(const vector<double>& arr){
    vector<pair<double, double>> pairs;
    int size = arr.size();
    if (size % 2 != 0) size -= 1;
    for (int i = 0; i < size; i += 2){
        pairs.push_back({arr[i], arr[i+1]});
    }
    return pairs;
}

vector<pair<char*,char*>> create_pairs_cstyle(const char* arr){
    vector<pair<char*, char*>> pairs;
    int i = 0;
    while (arr[i] != '\0') {
        int j = i;
        while (arr[j] != ' ' && arr[j] != '\0') {
            j++;
        }
        int len1 = j - i;
        char* str1 = new char[len1 + 1];
        for (int k = 0; k < len1; k++) {
            str1[k] = arr[i + k];
        }
        str1[len1] = '\0';
        i = j + 1;
        j = i;
        while (arr[j] != ' ' && arr[j] != '\0') {
            j++;
        }
        int len2 = j - i;
        char* str2 = new char[len2 + 1];
        for (int k = 0; k < len2; k++) {
            str2[k] = arr[i + k];
        }
        str2[len2] = '\0';
        i = j + 1;
        if (len1 == 0 || len2 == 0) break;
        pairs.push_back({str1, str2});
    }
    return pairs;
}

int main(){

    cout << "====================1.1====================" << endl;

    std::string text1 = "abc python javapythonx";
    std::string text2 = "abcx yja helx yz01 23";
    
    cout << substitute(text1, "python", "rust") << endl;
    cout << substitute(text1, "", "rust") << endl;
    cout << substitute(text2, "python", "rust") << endl;
    cout << substitute(text2, "x y", "a b") << endl;

    cout << "====================1.2====================" << endl;

    char text3[] = "abc python javapythonx";
    char text4[] = "abcx yja helx yz01 23";

    cout << substitute_cstyle(text3, "python", "rust") << endl;
    cout << substitute_cstyle(text3, "", "rust") << endl;
    cout << substitute_cstyle(text4, "python", "rust") << endl;
    cout << substitute_cstyle(text4, "x y", "a b") << endl;

    cout << "====================1.3====================" << endl;
    vector<double> data{
        1.2, 2.3, 5, 2, 1.1, 3, 7
    };
    auto pairs = create_pairs(data);
    for (auto p : pairs){
        cout << p.first << ", " << p.second << endl;
    }

    cout << "====================1.4====================" << endl;

    char data2[] = "1.2 2.3 5 2 1.1 3 7";
    auto pairs2 = create_pairs_cstyle(data2);
    for (auto p : pairs2){
        cout << p.first << ", " << p.second << endl;
    }

    return 0;
}
