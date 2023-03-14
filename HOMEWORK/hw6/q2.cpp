#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Picture{
    private:
        int width;
        int height;
        char** data;
    
    public:
        Picture() = delete;
        Picture(char** data){
            this->height = size(data);
            this->width = calculate_max_width(data);
            this->data = new char*[height];
            for (int i = 0; i < height; i++) {
                int width = strlen(data[i]) + 1;
                this->data[i] = new char[width];
                strcpy(this->data[i], data[i]);
            }
        }
        ~Picture() {
            for (int i = 0; i < height; i++) {
                cout << "deleting " << data[i] << endl;
                delete[] data[i];
            }
            delete[] data;
        }

        Picture(const Picture& other) : height(other.height), width(other.width) { // Copy constructor
            data = new char*[height];
            for (int i = 0; i < height; i++) {
                data[i] = new char[width + 1];
                strncpy(data[i], other.data[i], width);
                data[i][width] = '\0';
            }
        }

        Picture operator=(const Picture& other){ // Assignment operator
            if(this != &other){
                for (int i = 0; i < height; i++) {
                    delete[] data[i];
                }
                delete[] data;
                this->height = other.height;
                this->width = other.width;
                this->data = new char*[height];
                for (int i = 0; i < height; i++) {
                    int width = strlen(other.data[i]) + 1;
                    this->data[i] = new char[width];
                    strcpy(this->data[i], other.data[i]);
                }
            }
            return *this;
        }

        int get_width(){
            return width;
        }

        int get_height(){
            return height;
        }

        int calculate_max_width(char** data){
            int max_width = 0;
            for (int i = 0; data[i] != nullptr; i++) {
                int width = strlen(data[i]);
                if(width > max_width){
                    max_width = width;
                }
            }
            return max_width;
        }

        int size(char** data){
        int size = 0;
        while(data[size] != nullptr){
            size++;
        }
        return size;
    }

        void print(){
            cout << endl;
            cout << endl;
            for (int i = 0; i < height; i++) {
                cout << data[i] << endl;
            }
        }
};

int main(){
    char* data[] = {
        "````000000``````000000",
        "``0000000000``0000000000",
        "`0000000000000000````0000",
        "000000000000000000````0000",
        "0000000000000000000``00000",
        "0000000000000000000 `00000",
        "``000000000000000000000",
        "`````0000000000000000",
        "```````0000000000000",
        "`````````00000000",
        "```````````0000",
        nullptr
    };

    Picture p1 = Picture(data);
    cout << p1.get_width() << endl;
    cout << p1.get_height() << endl;
    p1.print();
}