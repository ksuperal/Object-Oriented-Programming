#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <typeinfo>

class SCORE{
    public:
        static double max(const std::vector<double>& vec){
            double max = 0;
            for (const auto& h: vec){
                if (h > max){
                    max = h;
                }
            }
            return max;
        }

        static double min(const std::vector<double>& vec){
            double min = 10000;
            for (const auto& h: vec){
                if (h < min){
                    min = h;
                }
            }
            return min;
        }

        static double average(const std::vector<double>& vec){
            double sum = 0;
            for (const auto& h: vec){
                sum += h;
            }
            return sum / vec.size();
        }
};