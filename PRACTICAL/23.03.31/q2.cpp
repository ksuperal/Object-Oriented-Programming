#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <fstream>
#include <tuple>
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

class Hero
{
private:
    string name;

public:
    Hero() {}

    Hero(string name)
    {
        this->name = name;
    }

    Hero(istream &iss)
    {
        read(iss);
    }

    virtual string Name() const
    {
        return name;
    }

    virtual ~Hero(){};

    virtual string greetings() const
    {
        return "I'm the hero with no name.";
    }

    virtual ostream &print(ostream &os) const
    {
        os << "[" << Name() << ": Hero]";
        return os;
    }

    virtual istream &read(istream &is)
    {
        char type;
        string name;
        is >> type >> name;
        this->name = name;
        return is;
    }

    virtual unique_ptr<Hero> clone() const
    {
        return make_unique<Hero>(*this);
    }
};

class Warrior : public Hero
{
public:
    Warrior() : Hero("Nameless Warrior"){};

    Warrior(string name) : Hero(name)
    {
        cout << "W constructor called." << endl;
    };

    Warrior(istream &iss) : Hero(iss){};

    virtual ~Warrior(){};

    virtual string greetings() const
    {
        return "I'm " + Name() + ", I will save the world.";
    }

    ostream &print(ostream &os) const
    {
        os << "[" << Name() << ": Warrior]";
        return os;
    }
};

class Fighter : public Hero
{
public:
    Fighter() : Hero("Nameless Fighter"){};

    Fighter(string name) : Hero(name){};

    Fighter(istream &iss) : Hero(iss){};

    virtual ~Fighter(){};

    virtual string greetings() const
    {
        return "I'm " + Name() + ", my fist will crush the evil.";
    }

    ostream &print(ostream &os) const
    {
        os << "[" << Name() << ": Fighter]";
        return os;
    }
};

class Mage : public Hero
{
public:
    Mage() : Hero("Nameless Mage"){};

    Mage(string name) : Hero(name){};

    Mage(istream &iss) : Hero(iss){};

    virtual ~Mage(){};

    virtual string greetings() const
    {
        return "I'm " + Name() + ", I can cook with fire magic.";
    }

    ostream &print(ostream &os) const
    {
        os << "[" << Name() << ": Mage]";
        return os;
    }
};

// istream& Hero::read(istream& is){
//     char type;
//     string name;
//     is >> type >> name;
//     switch(type){
//         case 'W':
//             *this = Warrior(name);
//             break;
//         case 'F':
//             *this = Fighter(name);
//             break;
//         case 'M':
//             *this = Mage(name);
//             break;
//         default:
//             break;
//     }
//     return is;
// }

void print_HTML_table(const vector<unique_ptr<Hero>> &vec)
{
    ofstream out("heroes.html");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    cout << "<table>" << endl;
    for (const auto &hero : vec)
    {
        cout << "<tr>" << endl;
        cout << "<td>" << hero->Name() << "</td>" << endl;
        cout << "<td>" << hero->greetings() << "</td>" << endl;
        cout << "</tr>" << endl;
    }
    cout << "</table>" << endl;
    cout.rdbuf(coutbuf);
}

void print_HTML_table_nse(const vector<unique_ptr<Hero>> &vec)
{
    using namespace nse::html;
    Stream_writer out(std::cout);

    vector<vector<Element>> t(3);
    int i;
    for (const auto &hero : vec)
    {
        t[i].push_back(Element("td", {Element::text(hero->Name())}));
        t[i].push_back(Element("td", {Element::text(hero->greetings())}));
        i++;
    }

    auto tbl = Element("table", {Element("tr", t[0]), Element("tr", t[1]), Element("tr", t[2])});

    auto title = Element("title", {Element::text("Heroes")});
    auto doc_head = Element("head", {title});
    auto doc_body = Element("body", {tbl});
    auto doc = Element("html", {doc_head, doc_body});

    ofstream out2("heroes2.html");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out2.rdbuf());

    std::cout << "<!DOCTYPE html>\n";
    out.write(doc);

    cout.rdbuf(coutbuf);
}

int main()
{
    using Hero_ptr = std::unique_ptr<Hero>;
    std::vector<Hero_ptr> vec;
    vec.push_back(std::make_unique<Warrior>("Cecil"));
    vec.push_back(std::make_unique<Fighter>());
    vec.push_back(std::make_unique<Mage>("Vivi"));
    print_HTML_table(vec);
    print_HTML_table_nse(vec);
}