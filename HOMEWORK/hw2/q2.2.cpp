#include "q2_header.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istream;

struct Scores{
    double score;
    string name;
};

istream& read_hw(istream& in, std::vector<string>& vec){
    if (in){
        vec.clear();

        string x;
        while (in >> x){
            vec.push_back(x);
        }
    }
    return in;
}

int main(){
    std::vector<string> score;

    cout << "Enter the score, End the loop by pressing Ctrl+Z then Enter: ";

    read_hw(cin, score); // read the cin input

    // printing out received input
    cout << "[";
    for (const auto& h: score){
        cout << h << ", ";
    }
    cout << "]" << endl;

    // storing data in seperate vectors name and score
    // name include only name
    // score include set of vector of scores which indexed the same as the name
    std::vector<std::vector<double>> score_d;
    std::vector<string> score_n;
    bool is_name = false;
    for (const auto& h: score){
        try{
            double d = std::stod(h);
            if (is_name){
                score_d.push_back(std::vector<double>());
                is_name = false;
            }
            score_d.back().push_back(d);
        }
        catch (std::invalid_argument& e){
            score_n.push_back(h);
            is_name = true;
        }
    }

    // printing out the name and score
    cout << "Name: [";
    for (const auto& h: score_n){
        cout << h << ", ";
    }
    cout << "]" << endl;

    cout << "Score: [";
    for (const auto& h: score_d){
        cout << "[";
        for (const auto& i: h){
            cout << i << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;

    cout << endl; cout << endl;
    cout << "=======================2.2========================" << endl;
    cout << "Min Score ranking" << endl;

    std::vector<double> min_score;
    for (const auto& h: score_d){
        min_score.push_back(SCORE::min(h));
    }

    std::vector<Scores> min_score_rank;
    for (int i = 0; i < min_score.size(); i++){
        min_score_rank.push_back(Scores{min_score[i], score_n[i]});
    }

    std::stable_sort(min_score_rank.begin(), min_score_rank.end(), [](Scores a, Scores b){
        return a.score > b.score;
    });

    for (const auto& h: min_score_rank){
        cout << h.name << ": " << h.score << endl;
    }

    cout << endl;
    cout << "Average Score ranking" << endl;

    std::vector<double> average_score;
    for (const auto& h: score_d){
        average_score.push_back(SCORE::average(h));
    }

    std::vector<Scores> average_score_rank;
    for (int i = 0; i < average_score.size(); i++){
        average_score_rank.push_back(Scores{average_score[i], score_n[i]});
    }

    std::stable_sort(average_score_rank.begin(), average_score_rank.end(), [](Scores a, Scores b){
        return a.score > b.score;
    });

    for (const auto& h: average_score_rank){
        cout << h.name << ": " << h.score << endl;
    }

    return 0;
   
}
