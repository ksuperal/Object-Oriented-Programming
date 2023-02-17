#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <typeinfo>
#include <list>
#include <random>
#include <fstream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::stringstream;
using std::map;

class Picture{
    public:
        vector<string> data;
        int width;
        int height = data.size();
        map<char, string> color;

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
        
        void color_map(char c, string color){
            this->color[c] = color;
        }

};

void svg_header(double height, double width){
    cout << "<?xml version='1.0' encoding='UTF-8' standalone='no'?>" << endl;
    cout << "<svg width='" << width << "' height='" << height << "' xmlns='http://www.w3.org/2000/svg'>" << endl;
    cout << "<style type='text/css'>" << endl;
    cout << "rect { stroke: #00FFFF; }" << endl;
    cout << "rect.c1 { fill: #000000; }" << endl;
    cout << "rect.c2 { fill: #808080; }" << endl;
    cout << "</style>" << endl;
}

void gen_svg(Picture pic){

    std::ofstream out("svg.html");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());

    svg_header(pic.get_height() * 10, pic.get_width() * 10);
    
    for (int i = 0; i < pic.get_height(); i++){
        for (int j = 0; j < pic.get_width(); j++){
            if (pic.get_data()[i][j] == '0'){
                cout << "<rect x='" << j * 10 << "' y='" << i * 10 << "' width='10' height='10' class='c1' />" << endl;
            }
            else{
                cout << "<rect x='" << j * 10 << "' y='" << i * 10 << "' width='10' height='10' class='c2' />" << endl;
            }
        }
    }

    cout << "</svg>" << endl;
    
}


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

    Picture pic(data);
    pic.print();
    pic.color_map('`', "#000000");
    pic.color_map('0', "#808080");



    gen_svg(pic);
}