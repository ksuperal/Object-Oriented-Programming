#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <fstream>
#include "nse/html.hpp"
#include "nse/ptr.hpp"
#include "nse/html.cpp"

using namespace std;

class Stream_writer : public nse::html::Writer
{
public:
    void write(std::string_view msg) const override;
    void write(const Element &e, int lv = 0) const override;

    Stream_writer(std::ostream &o) : os(o) {}

private:
    std::ostream &os;
};

void Stream_writer::write(std::string_view msg) const
{
    os << msg;
}

void Stream_writer::write(const Element &e, int lv) const
{
    e.write_to(*this, lv);
}

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

        virtual double get_x(){
            return x;
        }
        
        virtual double get_y(){
            return y;
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

        virtual double get_r(){
            return r;
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

        virtual double get_w(){
            return w;
        }

        virtual double get_h(){
            return h;
        }
};

using ShapeVariant = std::variant<Circle, Rectangle>;

int main(){
    using namespace nse::html;
    using Shapeptr = unique_ptr<Shape>;
    Stream_writer out(std::cout);

    stringstream iss("C 50 50 15 R 40 40 20 20");

    ShapeVariant shape1 = Circle(iss);
    ShapeVariant shape2 = Rectangle(iss);

    auto shape_to_element = [](auto& shape, const std::string& fill_color) {
        using ShapeType = std::decay_t<decltype(shape)>;

        if constexpr (std::is_same_v<ShapeType, Circle>) {
            return Element("circle", {{"cx", std::to_string(shape.get_x())}, {"cy", std::to_string(shape.get_y())}, {"r", std::to_string(shape.get_r())}, {"fill", fill_color}}, {Element::text("")});
        }
        else if constexpr (std::is_same_v<ShapeType, Rectangle>) {
            return Element("rect", {{"x", std::to_string(shape.get_x())}, {"y", std::to_string(shape.get_y())}, {"width", std::to_string(shape.get_w())}, {"height", std::to_string(shape.get_h())}, {"fill", fill_color}}, {Element::text("")});
        }
    };

    Element circle = std::visit([&](auto& shape) { return shape_to_element(shape, "red"); }, shape1);

    Element rect = std::visit([&](auto& shape) { return shape_to_element(shape, "blue"); }, shape2);
    
    auto svgs = Element("svg", {{"width", "100"}, {"height", "100"}}, {circle, rect});

    auto title = Element("title", {Element::text("Heroes")});
    auto doc_head = Element("head", {title});
    auto doc_body = Element("body", {svgs});
    auto doc = Element("html", {doc_head, doc_body});

    ofstream out2("svg2.html");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out2.rdbuf());

    std::cout << "<!DOCTYPE html>\n";
    out.write(doc);

    cout.rdbuf(coutbuf);
}