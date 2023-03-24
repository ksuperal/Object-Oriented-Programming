#include <iostream>
#include <string>

using namespace std;

int ix3();

int main()
{
    int ix1 = 20;
    int ix2;
    int ix3();
    int ix4 = int{};
    ix2 = ix4;
    string ss1(4, '*');
    string ss2{3, '&'};
    string ss3{'h', 't', 'm'};
    string ss4 = "x." + ss3;
    string ss5;
    string ss6 = string("x.") + "png";
    ss1 = ss2 = ss4;
}
/*
What objects/variables are created in the statement?
ix1, ix2, ix4, ss1, ss2, ss3, ss5, ss6

What are their types and values?
ix1, ix2, ix4 are "int"
ss1, ss2, ss3, ss5, ss6 are "std::string"


Count the number of them.
8

What operations are they created?
-Default initialization 
    = ix2, ss5
-Value initialization
    = ix1, ix4, ss2, ss3
-Copy initialization
    = ix4, ss4, ss6
-Other types of initializations 
    = ss1

Are there errors in the statement? Identify and correct them.
Yes. There are 2 errors.
1. ix3() is not a function. fix it by int ix3 or declare a function that return int.
2. ss6 = "x." + "png"; is not a valid statement. fix it by ss6 = string("x.") + "png";


At which statements does the copy assignment happen?
ix2 = ix4;
ss1 = ss2 = ss4;

Which objects are assigned?
ix2, ss1, ss2

By what value?
ix2 = 0;
ss1 = ss2 = ss4 = "x.htm";
*/