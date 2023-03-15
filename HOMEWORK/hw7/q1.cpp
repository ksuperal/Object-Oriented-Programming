#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

struct Person{
    string name;
    int age;
};

void sort_by_age(vector<Person>& people, bool acending = true){
    if (acending){
        sort(people.begin(), people.end(), [](Person& a, Person& b){return a.age < b.age;});
    } else {
        sort(people.begin(), people.end(), [](Person& a, Person& b){return a.age > b.age;});
    }
}

void sort_by_name(vector<Person>& people, bool acending = true){
    if (acending){
        sort(people.begin(), people.end(), [](Person& a, Person& b){return a.name < b.name;});
    } else {
        sort(people.begin(), people.end(), [](Person& a, Person& b){return a.name > b.name;});
    }
}

auto combine_fields(vector<string> names, vector<int> ages){
    vector<Person> people;
    for (int i = 0; i < names.size(); i++) {
        Person p;
        p.name = names[i];
        p.age = ages[i];
        people.push_back(p);
    }
    return people;
}

auto extract_names(vector<Person> person_list){
    vector<string> names;
    for (int i = 0; i < person_list.size(); i++) {
        names.push_back(person_list[i].name);
    }
    return names;
}

auto extract_ages(vector<Person> person_list){
    vector<int> ages;
    for (int i = 0; i < person_list.size(); i++) {
        ages.push_back(person_list[i].age);
    }
    return ages;
}

Person* combine_fields2(char** names, int* ages, int n){
    Person* people = new Person[n];
    for (int i = 0; i < n; i++) {
        people[i].name = names[i];
        people[i].age = ages[i];
    }
    return people;
}

char** extract_names2(Person* person_list, int n){
    char** names = new char*[n + 1];
    for (int i = 0; i < n; i++) {
        names[i] = new char[person_list[i].name.size() + 1];
        for(int j = 0; j < person_list[i].name.size(); j++){
            names[i][j] = person_list[i].name[j];
        }
        names[i][person_list[i].name.size()] = '\0';
    }
    names[n] = nullptr;
    return names;
}

int* extract_ages2(Person* person_list, int n){
    int* ages = new int[n + 1];
    for (int i = 0; i < n; i++) {
        ages[i] = person_list[i].age;
    }
    ages[n] = -1;
    return ages;
}

template <class T>
int find_size(T arr){
    int i = 0;
    while(*arr){
        i++;
        arr++;
    }
    return i;
}

int main(){

    cout << "---------------Use standard library---------------" << endl;
    vector<string> name_list = {"John", "Mary", "Bob", "Alice", "Tom"};
    vector<int> age_list = {20, 30, 40, 50, 60};

    auto people = combine_fields(name_list, age_list);
    sort_by_age(people, false);
    auto names = extract_names(people);
    auto ages = extract_ages(people);

    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " " << ages[i] << endl;
    }

    cout << "---------------Use free store memory---------------" << endl;
    char* name_list2[] = {"John", "Mary", "Bob", "Alice", "Tom", nullptr};

    int* age_list2 = new int[5];
    age_list2[0] = 20;
    age_list2[1] = 30;
    age_list2[2] = 40;
    age_list2[3] = 50;
    age_list2[4] = 60;
    
    int n = find_size(name_list2);
    auto people2 = combine_fields2(name_list2, age_list2, n);
    auto names2 = extract_names2(people2, n);
    auto ages2 = extract_ages2(people2, n);

    for (int i = 0; i < n; i++) {
        cout << names2[i] << " " << ages2[i] << endl;
    }

    return 0;
}