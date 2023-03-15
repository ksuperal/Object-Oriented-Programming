#include <iostream>
#include <tuple>

using std::cout;
using std::endl;

struct Point{
    double x;
    double y;
};

Point* create_point_list(double* xlist, double* ylist, int n){
    Point* points = new Point[n];
    for (int i = 0; i < n; i++) {
        points[i].x = xlist[i];
        points[i].y = ylist[i];
    }
    return points;
}

auto extract_point_fields(Point* points, int n){
    double* xlist = new double[n];
    double* ylist = new double[n];
    for (int i = 0; i < n; i++) {
        xlist[i] = points[i].x;
        ylist[i] = points[i].y;
    }
    return std::make_tuple(xlist, ylist);
}

template <class T>
int get_size(T* arr){
    int i = 0;
    while(*arr){
        i++;
        arr++;
    }
    return i;
}

int main(){
    double xlist[3] = {1.0, 2.0, 3.0};
    double ylist[3] = {4.0, 5.0, 6.0};
    Point* points = create_point_list(xlist, ylist, 3);
    auto [xlist2, ylist2] = extract_point_fields(points, 3);
    for (int i = 0; i < get_size(xlist2); i++) {
        cout << xlist2[i] << " " << ylist2[i] << endl;
    }
    return 0;
}