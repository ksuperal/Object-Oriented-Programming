#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void horizontal_frame(string p1, string p2){
    const int padding = 1;
    const int rows = padding * 2 + 3;

    const string::size_type cols = p1.size() + p2.size() + padding * 2 + 5;

    cout << endl;

    for (int r = 0; r != rows; r++){
        string::size_type c = 0;

        while(c != cols){
            if (r == padding + 1 && c == padding + 1){
                cout << p1;
                c += p1.size();
            }
            else{
                if (r == padding + 1 && c == padding + 3 + p1.size() + padding){
                    cout << p2;
                    c += p2.size();
                }
                else{
                    if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1 || c == padding + 2 + p1.size()){
                        cout << "*";
                        c++;
                    }
                    else{
                        if (r == padding + 1){
                            cout << " ";
                            c++;
                        }
                        else{
                            cout << " ";
                            c++;
                        }
                    }
                }
            }
        }
        cout << endl;
    }
}

void vertical_frame_star(string p1, string p2){
    const int padding = 1;
    const int rows = padding * 4 + 5;

    const string::size_type cols = std::max(p1.size(), p2.size()) + padding * 2 + 2;

    cout << endl;

    for (int r = 0; r != rows; r++){
        string::size_type c = 0;

        while(c != cols){
            if (r == padding + 1 && c == padding + 1){
                cout << p1;
                c += p1.size();
            }
            else if (r == padding + 5 && c == padding + 1){
                cout << p2;
                c += p2.size();
            }
            else{
                if (r == 0 || r == rows - 5 || r == rows - 1 || c == 0 || c == cols - 1){
                    cout << "*";
                    c++;
                }
                else{
                    if (r == padding + 1){
                        cout << " ";
                        c++;
                    }
                    else{
                        cout << " ";
                        c++;
                    }
                }
                
            }
        }
        cout << endl;
    }
}

void vertical_frame_dash(string p1, string p2){
    const int padding = 1;
    const int rows = padding * 4 + 5;

    const string::size_type cols = std::max(p1.size(), p2.size()) + padding * 2 + 2;

    cout << endl;

    for (int r = 0; r != rows; r++){
        string::size_type c = 0;

        while(c != cols){
            if (r == padding + 1 && c == padding + 1){
                cout << p1;
                c += p1.size();
            }
            else if (r == padding + 5 && c == padding + 1){
                cout << p2;
                c += p2.size();
            }
            else{
                if (r == 0 || r == rows - 5 || r == rows - 1){
                    if( (c == 0 && r == 0) || (c == cols - 1 && r == 0) || (c == 0 && r == rows - 1) || (c == cols - 1 && r == rows - 1) || (c == 0 && r == 4) || (c == cols - 1 && r == 4)){
                        cout << "+";
                    }
                    else{
                        cout << "-";
                    }
                    c++;
                }
                else{
                    if (c == 0 || c == cols - 1){
                        cout << "|";
                        c++;
                    }
                    else{
                        if (r == padding + 1){
                            cout << " ";
                            c++;
                        }
                        else{
                            cout << " ";
                            c++;
                        }
                    }
                }
                
            }
        }
        cout << endl;
    }
}

void horizontal_frame_equalontop(string p1, string p2){
    const int padding = 1;
    const int rows = padding * 4 + 5;

    const string::size_type cols = std::max(p1.size(), p2.size()) + padding * 2 + 2;

    cout << endl;

    for (int r = 0; r != rows; r++){
        string::size_type c = 0;

        while(c != cols){
            if (r == padding + 1 && c == padding + 1){
                cout << p1;
                c += p1.size();
            }
            else if (r == padding + 5 && c == padding + 1){
                cout << p2;
                c += p2.size();
            }
            else{
                if (r == 0 || r == rows - 5 || r == rows - 1){
                    if( (c == 0 && r == 0) || (c == cols - 1 && r == 0) || (c == 0 && r == rows - 1) || (c == cols - 1 && r == rows - 1) || (c == 0 && r == 4) || (c == cols - 1 && r == 4)){
                        cout << "+";
                    }
                    else if (r == 0 || r == rows - 1){
                        cout << "=";
                    }
                    else{
                        cout << "-";
                    }
                    c++;
                }
                else{
                    if (c == 0 || c == cols - 1){
                        cout << "|";
                        c++;
                    }
                    else{
                        if (r == padding + 1){
                            cout << " ";
                            c++;
                        }
                        else{
                            cout << " ";
                            c++;
                        }
                    }
                }
                
            }
        }
        cout << endl;
    }
}

int main()
{
    cout << "Please enter P1 name: ";
    string p1_name;
    cin >> p1_name;
    cout << "Please enter P2 name: ";
    string p2_name;
    cin >> p2_name;
    cout << "Player 1: " << p1_name << endl;
    cout << "Player 2: " << p2_name << endl;

    string p1 = "Player 1: " + p1_name;
    string p2 = "Player 2: " + p2_name;

    horizontal_frame(p1, p2);
    vertical_frame_star(p1, p2);
    vertical_frame_dash(p1, p2);
    horizontal_frame_equalontop(p1, p2);

    return 0;
}

