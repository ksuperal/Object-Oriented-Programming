#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void drawstar_pattern(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void drawstar_accending_decending(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void drawstar_accending_decending_left(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - (i + 1); j++){
            cout << " ";
        }
        for(int k = 0; k <= i; k++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i = n - 1; i > 0; i--){
        for(int j = 0; j < n - i; j++){
            cout << " ";
        }
        for(int k = 0; k < i; k++){
            cout << "*";
        }
        cout << endl;
    }
}

int main(){
    string size;
    cout << "Enter the size: ";
    cin >> size;
    int n = stoi(size);
    // drawstar_pattern(n);
    // drawstar_accending_decending(n);
    drawstar_accending_decending_left(n);
    return 0;
}