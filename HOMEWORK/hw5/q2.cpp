#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

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

        auto getdata(){
            return data;
        }

        Picture hcat(Picture& p){
            for(auto& x : data){
                if(x.size() < width){
                    x.insert(x.end(), width - x.size(), '`');
                }
            }
            vector<string> new_data;
            std::copy(data.begin(), data.end(), std::back_inserter(new_data));
            vector<string> p2_data = p.getdata(); 
            for(auto& x : p2_data){
                if(x.size() < width){
                    x.insert(x.end(), width - x.size(), '`');
                }
            }
            for (auto& h: p2_data){
                new_data.push_back(h);
            }
            return Picture(new_data);
        }

        Picture vcat(Picture& p){
            for(auto& x : data){
                if(x.size() < width){
                    x.insert(x.end(), width - x.size(), '`');
                }
            }
            vector<string> new_data;
            std::copy(data.begin(), data.end(), std::back_inserter(new_data));
            vector<string> p2_data = p.getdata(); 
            if (p2_data.size() - height > 0){
                for (int i = 0; i < p2_data.size() - height; i++){
                    new_data.push_back(string(width, '`'));
                }
            }
            else if (p2_data.size() - height < 0){
                for (int i = 0; i < height - p2_data.size(); i++){
                    p2_data.push_back(string(width, '`'));
                }
            }
            for (int i = 0; i < p2_data.size(); i++){
                new_data[i] += p2_data[i];
            }
            return Picture(new_data);
        }

        void resize(double new_height, double new_width){
            if(new_height < height){
                data.resize(new_height);
            }
            else if (new_height > height){
                for (int i = 0; i < new_height - height; i++){
                    data.push_back(string(width, '`'));
                }
            }

            if(new_width < width){
                for (auto& x : data){
                    x.resize(new_width);
                }
            }
            else if (new_width > width){
                for (auto& x : data){
                    x.insert(x.end(), new_width - x.size(), '`');
                }
            }
        }

        void print(){
            cout << endl;
            cout << endl;
            for (auto& h: data){
                cout << h << endl;
            }
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

    vector<string> data2 = {
        "_______________________________________",
        "/                                   \\",
        "|  ___________                       |",
        "| |           |\\                     |",
        "| |           ||                     |",
        "| |           ||                     |",
        "| |           ||                     |",
        "| |___________|/                     |",
        "|                                     |",
        "|  ___________                       |",
        "| |           |\\                     |",
        "| |           ||                     |",
        "| |           ||                     |",
        "| |           ||                     |",
        "| |___________|/                      |",
        "|                                     |",
        "|                                     |",
        "|                                     |",
        "|                                     |",
        "|                                     |",
        "\\_______________________________________/"
    };

    Picture p1 = Picture(data);
    Picture p2 = Picture(data2);

    Picture p3 = p2.hcat(p1);
    p3.print();

    Picture p4 = p1.vcat(p2);
    p4.print();

    p4.resize(20, 60);
    p4.print();

    p1.resize(20, 60);
    p1.print();

    return 0;
}