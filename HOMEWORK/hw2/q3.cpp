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

void print_words(std::ostream& out, const vector<string>& words){
    for (const auto& w: words){
        out << w << endl;
    }
}

double map(double x, double in_min, double in_max, double out_min, double out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

string hex_random_colour(){
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

int main(){

    vector<string> head_tag{
        "<body>",
        "<svg width='500' height='500' xmlns='http://www.w3.org/2000/svg'>>",
        "<rect width='100%' height='100%' fill='#EEEEEE' />",
        "<circle cx='250' cy='250' r='250' stroke='black' stroke-width='2' fill='none' />",
        "<circle cx='250' cy='250' r='10' fill='#00FFFF' />",    
    };

    vector<string> tail_tag{
        "</svg>",
        "</body>",
    };

    int N;
    cout << "Enter the N value: ";
    cin >> N;

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_real_distribution<double> dist{-1, 1};

    std::ofstream out("svg_hw2.html");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());

    double centerx = 250;
    double centery = 250;

    print_words(cout, head_tag);
    for (int i = 0; i < N; i++){
        double distance;
        double cx;
        double cy;
        cx = map(dist(rng), -1, 1, 0, 500);
        cy = map(dist(rng), -1, 1, 0, 500);
        distance = sqrt(pow(cx - centerx, 2) + pow(cy - centery, 2));
        while (distance > 250){
            cx = map(dist(rng), -1, 1, 0, 500);
            cy = map(dist(rng), -1, 1, 0, 500);
            distance = sqrt(pow(cx - centerx, 2) + pow(cy - centery, 2));
        }
        cout << "<circle cx='" << cx << "' cy='" << cy << "' r='10' fill='" + hex_random_colour() + "' />" << endl;
    }

    print_words(cout, tail_tag);
    return 0;
}
