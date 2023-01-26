#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void addspace(int n){
    for(int i = 0; i < n; i++){
        cout << " ";
    }
}

int main(){
    string warrior, mage, ninja, fighter;
    
    cout << "Enter warrior name: ";
    cin >> warrior;
    cout << "Enter mage name: ";
    cin >> mage;
    cout << "Enter ninja name: ";
    cin >> ninja;
    cout << "Enter fighter name: ";
    cin >> fighter;

    warrior = "Warrior: " + warrior;
    mage = "Mage: " + mage;
    ninja = "Ninja: " + ninja;
    fighter = "Fighter: " + fighter;
    
    const int padding = 1;
    const int rows = padding * 4 + 5;
    const string::size_type maxwidth = std::max(std::max(std::max(warrior.size(), mage.size()), ninja.size()), fighter.size());
    const string::size_type cols = maxwidth * 2 + padding * 4 + 2;

    cout << endl;

    for(int r = 0; r != rows; r++){

        string::size_type c = 0;

        while(c <= cols){

            if(r == 2){
                if(c == padding + 1){
                    cout << warrior;
                    c += warrior.size();
                    if (warrior.size() - maxwidth > 0){
                        addspace(warrior.size() - maxwidth);
                        c += warrior.size() - maxwidth + 2;
                    }
                }
                else if(c == padding + 3 + maxwidth + padding){
                    cout << mage;
                    c += mage.size();
                    if (mage.size() - maxwidth > 0){
                        addspace(mage.size() - maxwidth);
                        c += mage.size() - maxwidth + 3;
                    }
                }
                else if(c == 0 || c == cols - 1 || c == padding + 2 + maxwidth){
                    cout << "|";
                    c++;
                }
                else{
                    cout << " ";
                    c++;
                }
            }
            else if(r == 6){
                if(c == padding + 1){
                    cout << ninja;
                    c += ninja.size();
                    if (ninja.size() - maxwidth > 0){
                        addspace(ninja.size() - maxwidth);
                        c += ninja.size() - maxwidth + 1;
                    }
                }
                else if(c == padding + 3 + maxwidth + padding){
                    cout << fighter;
                    c += fighter.size();
                    if (fighter.size() - maxwidth > 0){
                        addspace(fighter.size() - maxwidth);
                        c += fighter.size() - maxwidth + 2;
                    }
                }
                else if(c == 0 || c == cols || c == padding + 2 + maxwidth){
                    cout << "|";
                    c++;
                }
                else{
                    cout << " ";
                    c++;
                }
            }
            else if(r == 0 || r == rows - 1 || c == 0 || c == cols || r == 4 || c == padding + 2 + maxwidth){
                if ((c == 0 && r == 0) || (c == 0 && r == 4) || (c == 0 && r == rows - 1) || (c == cols && r == 0) || (c == cols && r == 4) || (c == cols && r == rows - 1) || (c == padding + 2 + maxwidth && r == 0) || (c == padding + 2 + maxwidth && r == 4) || (c == padding + 2 + maxwidth && r == rows - 1)){
                    cout << "+";
                    c++;
                }else if(c == 0 || c == cols || c == padding + 2 + maxwidth){
                    cout << "|";
                    c++;
                }
                else if(r == 4){
                    cout << "-";
                    c++;
                }
                else{
                    cout << "=";
                    c++;
                }
            }
            else{
                cout << " ";
                c++;
            }
        }
        cout << endl;
    }

    return 0;
}