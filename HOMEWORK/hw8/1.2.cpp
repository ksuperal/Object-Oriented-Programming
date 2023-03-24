#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    double num_array[6];
    string s(3, '*');
    vector<string> vs1(5, s);
    vector<string> vs2(4);
    vector<string> vs3 = vs1;
    vector<string> vs4{};
    vs1 = vs2 = vs3;
    vector<double> vv1{3, 2.5};
    vector<double> vv2(2);
    vector<double> vv3();
    vv2 = vv1;
}
/*
What objects/variables are created in the statement?
num_array, s, vs1, vs2, vs3, vs4, vv1, vv2, vv3

What are their types and values?
num_array is "double[6]"
s is "std::string"
vs1, vs2, vs3, vs4 are "std::vector<std::string>"


Count the number of them.
9

What operations are they created?
-Default initialization 
    = num_array, vs2, vs4, vv2, vv3
-Value initialization
    = s, vs1, vs3, vv1
-Copy initialization
    = vs1, vs3, vv1
-Other types of initializations 
    = vs2, vs4, vv2, vv3

Are there errors in the statement? Identify and correct them.
Yes. There are 2 errors.
1. vector<double> vv3(); is not a function. fix it by vector<double> vv3;
2. vv2 = vv1; is not a valid statement. fix it by vv2 = vector<double>(vv1);


At which statements does the copy assignment happen?
vs1 = vs2 = vs3;
vv2 = vv1;

Which objects are assigned?
vs1, vs2, vv2

By what value?
vs1 = vs2 = vs3 = {"***", "***", "***", "***", "***"};
*/