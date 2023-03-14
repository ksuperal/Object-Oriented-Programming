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

char* encode_hex(const char* s){
    int len = str_len((char*)s);
    char* hex = new char[len * 2 + 1];
    char* it = hex;
    while(*s){
        sprintf(it, "%02x", *s);
        it += 2;
        s++;
    }
    *it = '\0';
    return hex;
}


int main(){

    double arr[5] = {1.0, 2.0, 3.5, 4.0, 5.0};

    inverse_numbers(arr, 3);

    auto* it = arr;
    while(*it){
        std::cout << *it << std::endl;
        it++;
    }

    char str[] = "Hello World!";
    replace(str, 'l', 'x');
    cout << str << endl;

    char* hex = encode_hex("Hello World!");
    cout << hex << endl;
    delete[] hex;

    return 0;
}