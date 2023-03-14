#include <iostream>

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
            this->data = data;
            this->height = size();
            this->width = calculate_max_width();
        }
        ~Picture(){
            for (int i = 0; i < height; i++) {
                if (data[i] != nullptr) {
                    delete[] data[i];
                }
            }
            if (data != nullptr) {
                delete[] data;
            }
        }

        int get_width(){
            return width;
        }

        int get_height(){
            return height;
        }

        int calculate_max_width(){
            int max_width = 0;
            for (int i = 0; i < height; i++) {
                int width = 0;
                while(data[i][width] != '\0'){
                    width++;
                }
                if(width > max_width){
                    max_width = width;
                }
            }
            return max_width;
        }

        int size(){
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