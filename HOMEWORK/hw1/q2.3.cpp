#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;

double FarenhitToCelsius(double farenhit){
    return (farenhit - 32) * 5 / 9;
}

int main(){
    int fahr = 300;
    std::cout << std::fixed << std::setprecision(1);

    cout << "Fahr\tCelcius" << endl;
    while(fahr >= 0){
        cout << fahr << "\t" << FarenhitToCelsius(fahr) << endl;
        fahr -= 20;
    }
}