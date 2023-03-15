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
                // cout << "deleting " << data[i] << endl;
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

        void clear(){
            for (int i = 0; i < height; i++) {
                delete[] data[i];
            }
            delete[] data;
            this->height = 0;
            this->width = 0;
        }

        void hcat(char** pic2_data){ // horizontal concatenation
            fill_width();
            int pic2_width = calculate_max_width(pic2_data);
            int pic2_height = size(pic2_data);
            int new_width = width + pic2_width;
            int new_height = height > pic2_height ? height : pic2_height;
            char** new_data = new char*[new_height];
            for (int i = 0; i < new_height; i++) {
                new_data[i] = new char[new_width + 1];
                new_data[i][new_width] = '\0';
            }
            for (int i = 0; i < height; i++) {
                strncpy(new_data[i], data[i], width);
            }
            for (int i = 0; i < pic2_height; i++) {
                strncpy(new_data[i] + width, pic2_data[i], pic2_width);
            }
            clear();
            this->height = new_height;
            this->width = new_width;
            this->data = new_data;
            fill_width();
        }

        void vcat(char** pic2_data){ // vertical concatenation
            fill_width();
            int pic2_width = calculate_max_width(pic2_data);
            int pic2_height = size(pic2_data);
            int new_width = width > pic2_width ? width : pic2_width;
            int new_height = height + pic2_height;
            char** new_data = new char*[new_height];
            for (int i = 0; i < new_height; i++) {
                new_data[i] = new char[new_width + 1];
                new_data[i][new_width] = '\0';
            }
            for (int i = 0; i < height; i++) {
                strncpy(new_data[i], data[i], width);
            }
            for (int i = 0; i < pic2_height; i++) {
                strncpy(new_data[i + height], pic2_data[i], pic2_width);
            }
            clear();
            this->height = new_height;
            this->width = new_width;
            this->data = new_data;
            fill_width();
        }

        void fill_width(){
            // adding ` to the end of each line until it fit the width
            for (int i = 0; i < height; i++) {
                int line_width = strlen(data[i]);
                if(line_width < width){
                    char* new_line = new char[width + 1];
                    new_line[width] = '\0';
                    strncpy(new_line, data[i], line_width);
                    for (int j = line_width; j < width; j++) {
                        new_line[j] = '`';
                    }
                    delete[] data[i];
                    data[i] = new_line;
                }
            }

        }

        void resize(int new_height, int new_width){
            char** new_data = new char*[new_height];
            for (int i = 0; i < new_height; i++) {
                new_data[i] = new char[new_width + 1];
                new_data[i][new_width] = '\0';
            }
            for (int i = 0; i < new_height; i++) {
                // don't use strncpy
                if(i >= height){
                    for (int j = 0; j < new_width; j++) {
                        new_data[i][j] = '`';
                    }
                    continue;
                }
                for (int j = 0; j < new_width; j++) {
                    if(j <= width){
                        new_data[i][j] = data[i][j];
                    }
                    else{
                        new_data[i][j] = '`';
                    }
                }
            }
            clear();
            this->height = new_height;
            this->width = new_width;
            this->data = new_data;
            fill_width();
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

    char* data2[] = {
        "```XX``",
        "``XXXX`",
        "`XXXXXX",
        "XXXXXXXX",
        "`XXXXXX",
        "``XXXX`",
        "```XX``",
        nullptr
    };

    Picture p1 = Picture(data);
    cout << p1.get_width() << endl;
    cout << p1.get_height() << endl;
    p1.print();

    cout << endl << "!!---------If the width of 'Hcat' and 'Vcat' is not equal for two picture, please use cmd to run this program---------!!";
    p1.hcat(data2);
    p1.print();

    Picture p2 = Picture(data);
    p2.vcat(data2);
    p2.print();
    p2.resize(10, 10);
    p2.print();
    p2.resize(20, 20);
    p2.print();
    return 0;
}