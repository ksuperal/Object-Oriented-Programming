#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string drawstar_pattern(int n){
    string result;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            result += "*";
        }
        result += "\n";
    }
    return result;
}

string drawstar_accending_decending(int n){
    string result;

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            result += "*";
        }
        result += "\n";
    }
    for (int i = n - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            result += "*";
        }
        result += "\n";
    }
    return result;
}

string drawstar_accending_decending_left(int n){
    string result;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - (i + 1); j++){
            result += " ";
        }
        for(int k = 0; k <= i; k++){
            result += "*";
        }
        result += "\n";
    }
    for(int i = n - 1; i > 0; i--){
        for(int j = 0; j < n - i; j++){
            result += " ";
        }
        for(int k = 0; k < i; k++){
            result += "*";
        }
        result += "\n";
    }
    return result;
}

int main(){
    string size;
    cout << "Enter the size: ";
    cin >> size;
    int n = stoi(size);
    // cout << drawstar_pattern(n);
    // cout << drawstar_accending_decending(n);
    cout << drawstar_accending_decending_left(n);
    return 0;
}