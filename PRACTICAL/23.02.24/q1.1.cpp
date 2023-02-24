#include <vector>
#include <array>
#include <iostream>

void to_upper(char* s){
    while(*s){
        if (*s >= 97 && *s <= 122) *s = *s - 32; 
        ++s;
    }
}

char* rev_dup(const char* s){
    int len = 0;
    while(s[len] != '\0'){
        len++;
    }

    char* new_s = new char[len];

    for(int i = 0; i < len; ++i){
        new_s[i] = s[len - i - 1];
    }
    new_s[len] = '\0';
    return new_s;
}

char* read_text(std::istream& in){
    char* s = new char[1];
    int len = 0;
    char c;
    while(in.get(c)){
        if (c == '!') break;
        char* new_s = new char[len + 1];
        for(int i = 0; i < len; ++i){
            new_s[i] = s[i];
        }
        new_s[len] = c;
        delete[] s;
        s = new_s;
        len++;
    }
    s[len] = '\0';
    return s;
}

int main(){

    double coords[3] = {2};
    double* p1 = coords;

    sizeof(coords);
    sizeof(p1);

    std::array<double, 4> pt4d;
    auto arr_it = pt4d.begin();

    std::vector<double> vec;
    auto vec_it = vec.begin();

    char s[] = "hellO";
    to_upper(s);
    std::cout << s << std::endl;

    char* s2 = rev_dup(s);
    std::cout << s2 << std::endl;

    std::cout << read_text(std::cin) << std::endl;

    return 0;
}