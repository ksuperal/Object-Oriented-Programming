#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::stringstream;

class Picture{
    public:
        vector<string> data;
        int width;
        int height = data.size();

        Picture(vector<string> data){
            this->data = data;
            this->width = 0;
            for(auto& x : data){
                if(x.size() > this->width){
                    this->width = x.size();
                }
            }
            this->height = data.size();
        }

        int get_width(){
            return width;
        }

        int get_height(){
            return height;
        }

        void hflip(){
            for (auto& h: data){
                if (h.size() < width){
                    h.insert(h.end(), width - h.size(), '`');
                    
                }
                std::reverse(h.begin(), h.end());
            }
        }

        void vflip(){
            std::reverse(data.begin(), data.end());
        }

        void print(){
            cout << endl;
            cout << endl;
            for (auto& h: data){
                cout << h << endl;
            }
        }

        Picture hcat(vector<string> pic){
            vector<string> temp = this->data;
            for(int i = 0; i < pic.size(); i++){
                temp[i] += pic[i];
            }
            return Picture(temp);
        }

        Picture vcat(vector<string> pic){
            vector<string> temp = this->data;
            for(auto& x : pic){
                temp.push_back(x);
            }
            return Picture(temp);
        }

        void fill(){
            for(auto& x : data){
                if(x.size() < width){
                    x += string(width - x.size(), '`');
                }
            }
        }

        void resize(int w , int h){
            if(w > width){
                for(auto& x : data){
                    x += string(w - x.size(), '`');
                }
            }
            else{
                for(auto& x : data){
                    x = x.substr(0, w);
                }
            }
            if(h > height){
                for(int i = 0; i < h - height; i++){
                    data.push_back(string(w, '`'));
                }

            }
            else{
                data = vector<string>(data.begin(), data.begin() + h);
            }
            width = w;
            height = h;
        }

        vector<string> get_data(){
            return data;
        }
        
};

int main(){
    vector<string> data = {
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
    };

    Picture p1 = Picture(data);
    Picture p2 = Picture(data);

    cout << p1.get_width() << endl;
    cout << p1.get_height() << endl;

    p1.print();

    p1.hflip();
    p1.print();
    cout << endl;

    p1.vflip();
    p1.print();
    cout << endl;


    Picture p3 = p1.hcat(p2.get_data());
    p3.print();
    cout << endl;
    p3.fill();
    p3.print();
    cout << endl;

    Picture p4 = p1.vcat(p2.get_data());
    p4.print();
    cout << endl;
    p4.fill();
    p4.print();
    cout << endl;

    p4.resize(10, 20);
    p4.print();
    cout << endl;


}