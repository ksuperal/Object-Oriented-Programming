#include <iostream>

class Vec{
    public:
        int size;
        double* elem;
        Vec(){};
        Vec(int s): size(s), elem(new double[s]){}
        ~Vec(){delete[] elem;}
        double& operator[](int i){return elem[i];}
        int get_size(){return size;}

        void push_back(double d){
            double* new_elem = new double[size + 1];
            for (int i = 0; i < size; i++){
                new_elem[i] = elem[i];
            }
            new_elem[size] = d;
            delete[] elem;
            elem = new_elem;
            size++;
        }

        double* get_elem(){
            return elem;
        }

        void print(){
            for (int i = 0; i < size; i++){
                std::cout << elem[i] << std::endl;
            }
        }
};
