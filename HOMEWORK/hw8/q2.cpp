#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Text_base{
    protected:
        string ori_text;
        string start;
        string end;

    public:
        Text_base() : ori_text(""), start(""), end("") {}

        Text_base(string text) : ori_text(text), start(""), end("") {}

        Text_base(string text, string deco) : ori_text(text), start(deco), end(deco) {}

        Text_base(string text, string start, string end) : ori_text(text), start(start), end(end) {}

        virtual ~Text_base(){}

        virtual string text() const{
            return ori_text;
        }

        virtual unique_ptr<Text_base> clone() const {
            return unique_ptr<Text_base>(new Text_base(*this));
        }
};

class Quoted_text: public Text_base{

    public:
        Quoted_text() : Text_base() {}

        Quoted_text(string text) : Text_base(text) {}

        Quoted_text(string text, string deco) : Text_base(text, deco) {}

        Quoted_text(string text, string start, string end) : Text_base(text, start, end) {}

        virtual ~Quoted_text(){}

        virtual string text() const{
            return start + ori_text + end;
        }
};

class Crypted_text: public Text_base{
    public:
        Crypted_text() : Text_base() {}

        Crypted_text(string text) : Text_base(text) {}

        virtual ~Crypted_text(){}

        virtual string text() const{
            string result = "";
            for (int i = 0; i < ori_text.length(); i++){
                if (ori_text[i] >= 'a' && ori_text[i] <= 'z'){
                    result += 'z' - (ori_text[i] - 'a');
                }
                else if (ori_text[i] >= 'A' && ori_text[i] <= 'Z'){
                    result += 'Z' - (ori_text[i] - 'A');
                }
                else{
                    result += ori_text[i];
                }
            }
            return result;
        }
};

class Text {
    private:
        unique_ptr<Text_base> p;

    public:
        Text(Text_base* ptr = nullptr) : p(ptr) {}

        Text(string text) : p(new Text_base(text)) {}

        Text(string text, string deco) : p(new Quoted_text(text, deco)) {}

        Text(string text, string start, string end) : p(new Quoted_text(text, start, end)) {}

        Text(const Text& other) : p(other.p ? other.p->clone() : nullptr) {}

        Text& operator=(const Text& other) {
            p = other.p ? std::unique_ptr<Text_base>(other.p->clone()) : nullptr;
            return *this;
        }

        string text() const {
            return p->text();
        }
};

int main(){
    Text_base q0("Python", "*");
    auto text = q0.text(); // "Python"
    cout << text << endl;

    Quoted_text q("Python", "*");
    const Text_base& rq = q;
    text = q.text(); // "*Python*"
    cout << text << endl;
    text = rq.text(); // "*Python*"
    cout << text << endl;

    q = Quoted_text("Python", "<em>", "</em>");
    text = q.text(); // "<em>Python</em>"
    cout << text << endl;
    text = rq.text(); // "<em>Python</em>"
    cout << text << endl;

    Crypted_text ct("Abc101");
    const Text_base& rct = ct;
    text = ct.text(); // "Zyx101"
    cout << text << endl;
    text = rct.text(); // "Zyx101"
    cout << text << endl;

    ct = Crypted_text{"PYthoN101"};
    text = ct.text(); // "KBgslM101"
    cout << text << endl;
    text = rct.text(); // "KBgslM101"
    cout << text << endl;

    std::vector<Text> words{
        Text("C++", "<i>", "</i>"), // Quoted_text
        Text("Zidane"), // Crypted_text
        Text("Rust", "*"), // Quoted_text
        Text("Python", "[[", "]]"), // Quoted_text
        Text("Vivi") // Text_base
    };


    for (const auto& w : words) {
        cout << w.text() << endl;
    }
}