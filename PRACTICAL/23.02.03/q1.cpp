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

void lshift(vector<double>& vec, int n){
    vec.erase(vec.begin(), vec.begin() + n);
}

void rshift(vector<double>& vec, int n){
    vec.insert(vec.begin(), n, 0);
}

void remove_negative(vector<double>& vec){
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](double x){return x < 0;}), vec.end());
}

auto scale(const vector<double>& vec, double scale){
    vector<double> vec_scaled;
    for (const auto& h: vec){
        vec_scaled.push_back(h * scale);
    }
    return vec_scaled;
}

auto add(const vector<double>& vec1, const vector<double>& vec2){
    vector<double> vec_add;
    int min_size = std::min(vec1.size(), vec2.size());
    for (int i = 0; i < min_size; i++){
        vec_add.push_back(vec1[i] + vec2[i]);
    }

    if(vec1.size() > vec2.size()){
        vec_add.insert(vec_add.end(), vec1.begin() + min_size, vec1.end());
    } else if (vec1.size() < vec2.size()){
        vec_add.insert(vec_add.end(), vec2.begin() + min_size, vec2.end());
    }
    return vec_add;
}

auto remove_negative_list(std::list<double>& list){
    list.remove_if([](double x){return x < 0;});
}

int main(){
    vector<double> vec{2, 1, 4, 3, 7};
    lshift(vec, 3);
    cout << "1.1a ";
    for (const auto& h: vec){
        cout << h << " ";
    }
    cout << endl;

    cout << "1.1b ";
    rshift(vec, 2);
    for (const auto& h: vec){
        cout << h << " ";
    }
    cout << endl;

    cout << "1.2  ";
    vector<double> vec_neg{
        0.8, -5.1, 1.6, -6.5, 10.5
    };
    remove_negative(vec_neg);
    for (const auto& h: vec_neg){
        cout << h << " ";
    }
    cout << endl;

    cout << "========1.3=======" << endl;
    const vector<double> vec1{2, 1, 4, 3, 7};
    const vector<double> vec2{1, 3, 2, 5};
    const auto vec3 = scale(vec1, 1.5);
    auto vec4 = add(vec2, vec3);
    auto vec5 = add(vec3, scale(vec2, -2.2));
    cout << "vec3: ";
    for (const auto& h: vec3){
        cout << h << " ";
    }
    cout << endl;

    cout << "vec4: ";
    for (const auto& h: vec4){
        cout << h << " ";
    }
    cout << endl;

    cout << "vec5: ";
    for (const auto& h: vec5){
        cout << h << " ";
    }
    cout << endl;

    cout << "========1.4=======" << endl;
    std::list<double> list1{2, 1, 4, 3, 7};
    remove_negative_list(list1);
    cout << "list1: ";
    for (const auto& h: list1){
        cout << h << " ";
    }
    return 0;   
}