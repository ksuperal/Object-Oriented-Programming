#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

class Hero{
    private:
        string name;
    
    public:
        Hero(){}

        Hero(string name){
            this->name = name;
        }

        Hero(istream& iss){
            read(iss);
        }

        virtual string Name() const{
            return name;
        }

        virtual ~Hero(){};

        virtual string greetings() const {
            return "I'm the hero with no name.";
        }

        virtual ostream& print(ostream& os) const{
            os << "[" << Name() << ": Hero]";
            return os;
        }

        virtual istream& read(istream& is){
            char type;
            string name;
            is >> type >> name;
            this->name = name;
            return is;
        }

        virtual unique_ptr<Hero> clone() const{
            return make_unique<Hero>(*this);
        }
};

class Warrior : public Hero{
    public:
        Warrior() : Hero("Nameless Warrior"){};

        Warrior(string name) : Hero(name) {
            cout << "W constructor called." << endl;
        };

        Warrior(istream& iss) : Hero(iss){};

        virtual ~Warrior(){};

        virtual string greetings() const{
            return "I'm " + Name() + ", I will save the world.";
        }

        ostream& print(ostream& os) const{
            os << "[" << Name() << ": Warrior]";
            return os;
        }
};

class Fighter : public Hero{
    public:
        Fighter() : Hero("Nameless Fighter"){};

        Fighter(string name) : Hero(name){};

        Fighter(istream& iss) : Hero(iss){};

        virtual ~Fighter(){};

        virtual string greetings() const{
            return "I'm " + Name() + ", my fist will crush the evil.";
        }

        ostream& print(ostream& os) const{
            os << "[" << Name() << ": Fighter]";
            return os;
        }
};

class Mage : public Hero{
    public:
        Mage() : Hero("Nameless Mage"){};

        Mage(string name) : Hero(name){};

        Mage(istream& iss) : Hero(iss){};

        virtual ~Mage(){};

        virtual string greetings() const{
            return "I'm " + Name() + ", I can cook with fire magic.";
        }

        ostream& print(ostream& os) const{
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

int main(){
    using HeroPtr = std::unique_ptr<Hero>;

    Warrior warrior1("Cecil");
    Fighter fighter1;
    Mage mage1("Vivi");

    const Hero& hero1 = warrior1;
    const Hero& hero2 = fighter1;
    const Hero& hero3 = mage1;
    // "Cecil"
    auto name = hero1.Name();
    // "Nameless Fighter"
    name = hero2.Name();
    // "Vivi"
    name = hero3.Name();
    // ...
    // "I'm Cecil, I will save the world."
    std::cout << hero1.greetings() << std::endl;
    // "I'm Nameless Fighter, I will crush the evil."
    std::cout << hero2.greetings() << std::endl;
    // "I'm Vivi, I can cook with fire magic."
    std::cout << hero3.greetings() << std::endl;
    const Hero hero4 = warrior1;
    // "I'm the hero with no name."
    std::cout << hero4.greetings() << std::endl;

    // auto herotest = make_unique<Hero>();
    // herotest->read(std::cin);
    // herotest->print(std::cout) << std::endl;

    stringstream iss("W Cecil F Ryu M Vivi");
    auto hero5 = make_unique<Warrior>(iss);
    auto hero6 = make_unique<Fighter>(iss);
    auto hero7 = make_unique<Mage>(iss);

    // [Cecil: Warrior]
    hero5->print(std::cout) << std::endl;
    // [Ryu: Fighter]
    hero6->print(std::cout) << std::endl;
    // [Vivi: Mage]
    hero7->print(std::cout) << std::endl;
}