#include <iostream>
#include <array>
// #include <sstream>

using std::cout;
using std::endl;

void inverse_numbers(double* v, size_t n){
    size_t i = 0;
    while(*v){
        if(i == n){
            break;
        }
        (*v) *= -1;
        v++;
        ++i;
    }
}

void replace(char* s, char c1, char c2){
    while(*s){
        if(*s == c1){
            *s = c2;
        }
        s++;
    }
}

int str_len(char* s){
    int i = 0;
    while(*s){
        i++;
        s++;
    }
    return i;
}

int strlen(const char* s) {
    int i = 0;
    while (*s) {
        i++;
        s++;
    }
    return i;
}

char* encode_hex(const char* s) {
    const char hex[] = "0123456789ABCDEF";
    const int length = strlen(s);
    char* encoded = new char[length * 2 + 1];

    for (int i = 0; i < length; i++) {
        encoded[i * 2] = hex[(s[i] >> 4) & 0xF];
        encoded[i * 2 + 1] = hex[s[i] & 0xF];
    }

    encoded[length * 2] = '\0';
    return encoded;
}


int main(){

    double arr[5] = {1.0, 2.0, 3.5, 4.0, 5.0};

    inverse_numbers(arr, 3);

    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    char str[] = "Hello World!";
    replace(str, 'l', 'x');
    cout << str << endl;

    char* encoded = encode_hex("Hello World!");
    cout << encoded << endl;
    delete[] encoded;

    return 0;
}