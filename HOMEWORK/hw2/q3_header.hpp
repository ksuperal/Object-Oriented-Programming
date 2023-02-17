#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <istream>
#include <random>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::vector;
using std::list;
using std::copy;
using std::string;
using std::istream;

class SVG{
    public:
        static void print_words(std::ostream& out, const vector<string>& words){
            for (const auto& w: words){
                out << w << endl;
            }
        }

    static double map(double x, double in_min, double in_max, double out_min, double out_max){
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }   

    static string hex_random_colour(){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 255);
        std::string hex = "#";
        for (int i = 0; i < 3; i++){
            std::stringstream ss;
            ss << std::hex << dis(gen);
            std::string result(ss.str());
            if (result.size() == 1){
                result = "0" + result;
            }
            hex += result;
        }
        return hex;
    }     
};