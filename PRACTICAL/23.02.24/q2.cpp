#include "vector.hpp"
#include <array>
#include <iostream>

class Nd_vec {
public:
    // constructor
    Nd_vec(int dim) {
        this->dim = dim;
        data = new double[dim];
        for (int i = 0; i < dim; i++) {
            data[i] = 0.0;
        }
    }
    
    // copy constructor
    Nd_vec(const Nd_vec& other) {
        dim = other.dim;
        data = new double[dim];
        for (int i = 0; i < dim; i++) {
            data[i] = other.data[i];
        }
    }

    // destructor
    ~Nd_vec() {
        delete[] data;
    }

    // assignment operator
    Nd_vec& operator=(const Nd_vec& other) {
        if (this != &other) {
            delete[] data;
            dim = other.dim;
            data = new double[dim];
            for (int i = 0; i < dim; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    double& operator[](int index) {
        return data[index];
    }

    const double& operator[](int index) const {
        return data[index];
    }

    // other operations
    int dimension() const {
        return dim;
    }

    void scalar_multiply(double scalar) {
        for (int i = 0; i < dim; i++) {
            data[i] *= scalar;
        }
    }

    Nd_vec add(Nd_vec v1, Nd_vec v2){
        Nd_vec v3(v1.dimension());
        for (int i = 0; i < v1.dimension(); i++) {
            v3[i] = v1[i] + v2[i];
        }
        return v3;
    }

    Nd_vec subtract(Nd_vec v1, Nd_vec v2){
        Nd_vec v3(v1.dimension());
        for (int i = 0; i < v1.dimension(); i++) {
            v3[i] = v1[i] - v2[i];
        }
        return v3;
    }

    Nd_vec scale(Nd_vec v1, double scalar){
        Nd_vec v3(v1.dimension());
        for (int i = 0; i < v1.dimension(); i++) {
            v3[i] = v1[i] * scalar;
        }
        return v3;
    }

    int size(){
        int size = 0;
        while(data[size] != 0){
            size++;
        }
        return size;
    }

    void print(){
        std::cout << "[";
        for (int i = 0; i < dim; i++) {
            std::cout << data[i] << ", ";
        }
        std::cout << "]" << std::endl;
    }

    void clear(){
        delete[] data;
        data = nullptr;
        this->dim = 0;
    }

private:
    int dim;
    double* data;
};


int main() {
    Nd_vec v(3);

    v[0] = 1.0;
    v[1] = 2.0;
    v[2] = 3.0;

    // print out the dimension of the vector
    v.print();
    
    Nd_vec w(3);
    w = v;
    w.print();

    v.clear();
    v.print();
    

    return 0;
}