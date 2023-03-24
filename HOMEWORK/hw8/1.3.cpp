#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    map<string, vector<double>> x_map;
    x_map["exp"] = vector<double>{1.1, 2.2, 3.3};
    vector<double> vv1 = x_map["exp"];
    vector<double> vv2 = x_map["xpr"];
    vv1 = x_map["xxpr"];
    vv2 = x_map["exp"];
}
/*
What objects/variables are created in the statement?
x_map, vv1, vv2

What are their types and values?
x_map is "std::map<std::string, std::vector<double>>"
vv1, vv2 are "std::vector<double>"
x_map["exp"] is "std::vector<double>"
x_map["xpr"] is "std::vector<double>"
x_map["xxpr"] is "std::vector<double>"

Count the number of them.
5

What operations are they created?
-Default initialization 
    = vv1, vv2, x_map
-Value initialization
    = x_map["exp"], x_map["xpr"], x_map["xxpr"]
-Copy initialization
    = vv1, vv2
-Other types of initializations 
    = -

Are there errors in the statement? Identify and correct them.
No.


At which statements does the copy assignment happen?
vv1 = x_map["xxpr"];
vv2 = x_map["exp"];

Which objects are assigned?
vv1, vv2

By what value?
vv1 = x_map["xxpr"] = {};
*/