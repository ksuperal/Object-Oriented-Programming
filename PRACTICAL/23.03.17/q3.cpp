#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

class Shape{
    protected:
        double x;
        double y;
    
    public:
        Shape(){}

        Shape(double x, double y) : x(x), y(y) {};

        virtual ~Shape(){}

        virtual double area() const = 0;

        virtual ostream& print(ostream& os) const{
            os << "[Shape: (" << x << ", " << y << ")]";
            return os;
        }
};

class Circle: public Shape{
    private:
        double r;
    
    public:
        Circle() : Shape(50, 50), r(10) {}

        Circle(double x, double y, double r) : Shape(x, y), r(r) {};

        Circle(istream& iss){
            read(iss);
        }

        istream& read(istream& is){
            char type;
            double x, y, r;
            is >> type >> x >> y >> r;
            this->x = x;
            this->y = y;
            this->r = r;
            return is;
        }

        double area() const{
            return 3.14 * r * r;
        }

        ostream& print(ostream& os) const{
            os << "[Circle: (" << x << ", " << y << ", " << r << ")]";
            return os;
        }

        virtual unique_ptr<Shape> clone() const{
            return make_unique<Circle>(*this);
        }
};

class Rectangle: public Shape{
    private:
        double w;
        double h;
    
    public:
        Rectangle() : Shape(45, 45), w(10), h(10) {}

        Rectangle(double x, double y, double w, double h) : Shape(x, y), w(w), h(h) {};

        Rectangle(istream& iss){
            read(iss);
        }

        istream& read(istream& is){
            char type;
            double x, y, w, h;
            is >> type >> x >> y >> w >> h;
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;
            return is;
        }

        double area() const{
            return w * h;
        }

        ostream& print(ostream& os) const{
            os << "[Rectangle: (" << x << ", " << y << ", " << w << ", " << h << ")]";
            return os;
        }
};

int main(){
    using Shapeptr = unique_ptr<Shape>;
    stringstream iss("C 50 50 15 R 40 40 20 20");

    auto shape1 = make_unique<Circle>(iss);
    auto shape2 = make_unique<Rectangle>(iss);
    // [Circle: (50, 50, 15)]
    shape1->print(std::cout) << std::endl;
    // [Rectangle: (40, 40, 20, 20)]
    shape2->print(std::cout) << std::endl;
}