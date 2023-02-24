#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::istream;
using std::sort;

istream& read(istream& is, vector<string>& v){
    if (is){
        v.clear();
        string s;
        while (is >> s){
            v.push_back(s);
        }
        is.clear();
    }
    return is;
}

enum Genre {fiction, nonfiction, periodical, biography, children};

class Book{

    public:
        string ISBN;
        string title;
        string author;
        string copyright;
        enum Genre genre;
        bool checkedOut;

        Book(string ISBN, string title, string author, string copyright, Genre genre){
            this->ISBN = ISBN;
            this->title = title;
            this->author = author;
            this->copyright = copyright;
            this->genre = genre;
            this->checkedOut = false;
        }

        string getISBN(){
            return ISBN;
        }

        string getTitle(){
            return title;
        }

        string getAuthor(){
            return author;
        }

        string getCopright(){
            return copyright;
        }

        bool isCheckedOut(){
            return checkedOut;
        }

        void checkOut(){
            checkedOut = true;
        }

        void checkIn(){
            checkedOut = false;
        }

        bool compareISBN(string isbn){
            if (this->ISBN == isbn){
                return true;
            }
            return false;
        }

        void print(){
            cout << "ISBN: " << ISBN << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Copyright: " << copyright << endl;
            cout << "Checked Out: " << checkedOut << endl;
        }

};

Book find_isbn(vector<Book> books, string isbn){
    for (Book book : books){
        if (book.compareISBN(isbn)){
            return book;
        }
    }
    return Book("","","","", fiction);
}

Book find_title(vector<Book> books, string title){
    for (Book book : books){
        if (book.getTitle() == title){
            return book;
        }
    }
    return Book("","","","", fiction);
}

Genre map_genre(string genre){
    if (genre == "fiction"){
        return fiction;
    }
    else if (genre == "nonfiction"){
        return nonfiction;
    }
    else if (genre == "periodical"){
        return periodical;
    }
    else if (genre == "biography"){
        return biography;
    }
    else if (genre == "children"){
        return children;
    }
    else{
        return fiction;
    }
}

auto getlist(vector<Book> books, Genre genre){
    vector<Book> list;
    for (Book book : books){
        if (book.genre == genre){
            list.push_back(book);
        }
    }
    return list;
}

void sort_isbn(vector<Book>& books){
    for (int i = 0; i < books.size(); i++){
        for (int j = 0; j < books.size() - 1; j++){
            if (books[j].ISBN > books[j+1].ISBN){
                Book temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}

void sort_title(vector<Book>& books){
    for (int i = 0; i < books.size(); i++){
        for (int j = 0; j < books.size() - 1; j++){
            if (books[j].title > books[j+1].title){
                Book temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}

int main(){

    vector<Book> books;
    
    while(true){

        cout << endl << "====================================" << endl;
        cout << "q to quit" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Find Book of the same ISBN" << endl;
        cout << "3. Find Book of the same Title" << endl;
        cout << "4. Get list of books of the same genre" << endl;
        cout << "5. Sort books by ISBN" << endl;
        cout << "6. Sort books by Title" << endl;
        string ans;
        getline(cin, ans);
        if(ans == "1"){
            cout << "Reading..." << endl;
            string line;
            vector<string> info_str;
            cin.clear();
            while(getline(cin, line)){
                if (line.empty()){
                    break;
                }
                info_str.push_back(line);
            }

            Book book = Book(info_str[0], info_str[1], info_str[2], info_str[3], map_genre(info_str[4]));
            books.push_back(book);
            ans.clear();
            cin.clear();
        }
        else if(ans == "2"){
            string isbn;
            cout << "Type book ISBN: ";
            getline(cin, isbn);
            Book book = find_isbn(books, isbn);
            book.print();
            ans.clear();
            cin.clear();
        }
        else if(ans == "3"){
            string title;
            cout << "Type book title: ";
            getline(cin, title);
            Book book = find_title(books, title);
            book.print();
            ans.clear();
            cin.clear();
        }
        else if(ans == "4"){
            string genre;
            cout << "Type book genre: ";
            getline(cin, genre);
            vector<Book> list = getlist(books, map_genre(genre));
            for (Book book : list){
                cout << endl;
                book.print();
            }
            ans.clear();
            cin.clear();
        }
        else if(ans == "5"){
            sort_isbn(books);
            for (Book book : books){
                cout << endl;
                book.print();
            }
            ans.clear();
            cin.clear();
        }
        else if(ans == "6"){
            sort_title(books);
            for (Book book : books){
                cout << endl;
                book.print();
            }
            ans.clear();
            cin.clear();
        }
        else if(ans == "q"){
            break;
        }
        else{
            cout << "Invalid Input" << endl;
        }
    }

    return 0;
}