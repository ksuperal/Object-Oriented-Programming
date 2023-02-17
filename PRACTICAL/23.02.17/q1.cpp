#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::stringstream;

class Book{
    public:
        string ISBN;
        string title;
        string author;
        string copyright_year;
        bool occupied = false;

        enum Genere{
            fiction,
            nonfiction,
            periodical,
            biography,
            children
        };
        
        Genere genere;

        void check_in(){
            occupied = true;
        }

        void check_out(){
            occupied = false;
        }

        bool is_occupied(){
            return occupied;
        }

        bool compare_ISBN(string isbn){
            return ISBN == isbn;
        }

        void Print(){
            cout << endl;
            cout << "ISBN: " << ISBN << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Genere: " << genere << endl;
            cout << "Copyright Year: " << copyright_year << endl;
            cout << "Occupied: " << occupied << endl;
        }
};

istream& read_info(istream& in, std::vector<string>& vec){
    if (in){
        vec.clear();

        string x;
        while (in >> x){
            vec.push_back(x);
        }

        in.clear();
    }
    return in;
}

Book find_book(vector<Book> books, string isbn){
    for (Book book : books){
        if (book.compare_ISBN(isbn)){
            return book;
        }
    }
    return Book();
}

bool check_ISBN_format(string isbn){
    if (isbn.size() != 4){
        return false;
    }
    return true;
}

auto split(string str, char delimiter){
    vector<string> internal;
    stringstream ss(str);
    string tok;

    while(getline(ss, tok, delimiter)){
        internal.push_back(tok);
    }

    return internal;
}

Book::Genere map_genere(string genere){
    if (genere == "fiction"){
        return Book::Genere::fiction;
    }
    else if (genere == "nonfiction"){
        return Book::Genere::nonfiction;
    }
    else if (genere == "periodical"){
        return Book::Genere::periodical;
    }
    else if (genere == "biography"){
        return Book::Genere::biography;
    }
    else if (genere == "children"){
        return Book::Genere::children;
    }
    else{
        return Book::Genere::fiction;
    }
}

int main()
{   
    
    vector<Book> books;
    string read_value;
    cout << endl;
    
    cout << "Reading...." << endl;
    cin >> read_value;

    vector<string> book_info;
    read_info(cin, book_info);

    vector<vector<string>> temp_book;
    for (string info : book_info){
        temp_book.push_back(split(info, ','));
    }

    for (vector<string> book : temp_book){
        for (string info : book){
            cout << info << " ";
        }
        cout << endl;
    }
    

    // 1234\nC++\nMe\n2022\nfiction
    // 1235\nPython\nYou\n2023\nnonfiction
    // 1236\nJava\nThem\n2024\nperiodical
    // 1237\nC#\nUs\n2025\nbiography
    for (vector<string> book : temp_book){
        for (string info : book){
            if (check_ISBN_format(book[0])){
                Book new_book;
                new_book.ISBN = book[0];
                new_book.title = book[1];
                new_book.author = book[2];
                new_book.copyright_year = book[3];
                new_book.genere = map_genere(book[4]);
                books.push_back(new_book);
            }
            else{
                cout << "ISBN format is not correct" << endl;
            }
        }
    }


    cout << "Enter ISBN to find: ";
    string isbn_find;
    cin >> isbn_find;
    Book book = find_book(books, isbn_find);
    book.Print();


    return 0;
}