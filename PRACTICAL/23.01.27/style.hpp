#ifndef STYLE_HPP
#define STYLE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class STYLE{
    public:
        static string unstylize(string m){

            // remove the "*" in the string
            if (m.front() == '*' && m.back() == '*' && m.size() > 1){
                m.erase(0, 1);
                m.erase(m.size() - 1, 1);
            }
            // return the string

            return m;
        }

        static string stylize(string m){

            // remove the "*" in the string
            if (m.front() == '*' && m.back() == '*' && m.size() > 1){
                m.erase(0, 1);
                m.erase(m.size() - 1, 1);
                return "<strong>" + m + "</strong>";
            }
            // return the string

            return m;
        }
};
#endif // STYLE_HPP