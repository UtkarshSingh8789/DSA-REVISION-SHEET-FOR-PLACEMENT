// in this we will learn abot constructor,destructor,dynamic memory allocation,inheritance,encapsulation,polymorphism,abstraction using a simple project 
// library mangement system;
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// BOOK CLASS ---- ENCAPSULATION;

class Book{
    private:
    int id;
    string title;
    string author;
    bool isIssued;
    public:
    Book(int id,string title,string author){
        this->title=title;
        this->id=id;
        this->author=author;
        this->isIssued=false;
    }
    void display() {
        cout << "Book ID: " << id << ", Title: " << title << ", Author: " << author;
        cout << ", Status: " << (isIssued ? "Issued" : "Available") << endl;
    }
    bool getStatus() {
        return isIssued;
    }
    void issue() {
        isIssued=true;
    }
    void returnBook() {
        isIssued=false;
    }
    int getId() {
        return id;
    }
}; // this is encapsulation hiding data and expose it using member function or methods only;


// MEMBER CLASS ---- abstraction and polymorphism;

class Member{
    protected:
    int memberID;
    string name;
    public:
    Member(int id,string name){
        this->memberID=id;
        this->name=name;
    }
    virtual void issueBook(Book* book)=0;
    virtual void returnBook(Book* book)=0;
    virtual void display()=0;
    int getId(){
        return memberID;
    }
    virtual ~Member() {}
};// it is abstract class showing only essential behavior;
// it has pure virtual frunction =0;
// you cannot create object of member directly it forces child class to implement those function;

// STUDENT CLASS ----- inheritance and polymorphism;


class Student : public Member{
    const int limit=2;
    vector<Book*> vec;
    public:
    int id;
    string name;
    Student(int id,string name) : Member(id,name){};
    void issueBook (Book* book) override {
        if(vec.size()>=limit){
            cout<<"Student cannot issue more than "<<limit<<endl;
            return;
        }
        if(book->getStatus()){
            cout<<"Book already allocated"<<endl;
            return;
        }
        book->issue();
        vec.push_back(book);
        cout << "Book issued to student " << name << ".\n";
    }
    void returnBook(Book* book) override{
        for(auto it=vec.begin();it!=vec.end();it++){
            if(*it==book){
                book->returnBook();
                vec.erase(it);
                cout << "Book returned by student " << name << ".\n";
                return;
            }
        }
        cout << "Book not found in student's issued list.\n";
    }
    void display() override {
        cout << "Student ID: " << memberID << ", Name: " << name << ", Books issued: " << vec.size() << endl;
    }
};

// TEACHER CLASS -INHERITANCE AND POLYNORPHISM;
class Teacher: public Member{
    vector<Book*> vec;
    const int limit=3;
    public:
    Teacher(int id,string name) : Member(id,name){};
    void issueBook(Book* book) override{
        if(vec.size()>=limit){
            cout<<"Student cannot issue more than "<<limit<<endl;
            return;
        }
        if(book->getStatus()){
            cout<<"Book already allocated"<<endl;
            return;
        }
        vec.push_back(book);
        book->issue();
        cout<< "Book issued to student " << name << ".\n";
    }
    void returnBook(Book* book) override{
        for(auto it=vec.begin();it!=vec.end();it++){
            if(*it==book){
                book->returnBook();
                vec.erase(it);
                cout << "Book returned by student " << name << ".\n";
                return;
            }
        }
        cout << "Book not found in Teachers's issued list.\n";
    }
    void display() override {
        cout << "Teacger ID: " << memberID << ", Name: " << name << ", Books issued: " << vec.size() << endl;
    }
};

// LIBRARY CLASS;  and concept of destructor;


class Library {
    vector<Book*> books;
    vector<Member*> members;

public:
    void addBook(Book* book) {
        books.push_back(book);
    }

    void addMember(Member* member) {
        members.push_back(member);
    }

    Book* findBook(int id) {
        for (Book* book : books) {
            if (book->getId() == id) return book;
        }
        return NULL;
    }

    Member* findMember(int id) {
        for (Member* member : members) {
            if (member->getId() == id) return member;
        }
        return NULL;
    }

    void issueBook(int memberId, int bookId) {
        Member* member = findMember(memberId);
        Book* book = findBook(bookId);
        if (!member || !book) {
            cout << "Invalid member or book ID.\n";
            return;
        }
        member->issueBook(book);
    }

    void returnBook(int memberId, int bookId) {
        Member* member = findMember(memberId);
        Book* book = findBook(bookId);
        if (!member || !book) {
            cout << "Invalid member or book ID.\n";
            return;
        }
        member->returnBook(book);
    }

    void displayBooks() {
        cout << "\nAll Books:\n";
        for (Book* book : books) {
            book->display();
        }
    }

    void displayMembers() {
        cout << "\nAll Members:\n";
        for (Member* member : members) {
            member->display();
        }
    }

    ~Library() {  // destructor we have to manually add because we are doing heap memory allocation;
        for (Book* book : books) delete book;
        for (Member* member : members) delete member;
    }
};


int main() {
    Library lib;

    // Adding books
    lib.addBook(new Book(101, "DSA", "Utkarsh Kumar"));
    lib.addBook(new Book(102, "OOP", "Bjarne Stroustrup"));
    lib.addBook(new Book(103, "System Design", "Alex Yu"));

    // Adding members
    lib.addMember(new Student(1, "Alice"));
    lib.addMember(new Teacher(2, "Prof. Sharma"));

    lib.displayBooks();
    lib.displayMembers();

    // Issue and return operations
    lib.issueBook(1, 101); // Student issues DSA
    lib.issueBook(2, 102); // Teacher issues OOP
    lib.issueBook(1, 103); // Student issues System Design

    lib.returnBook(1, 101); // Student returns DSA

    lib.displayBooks();
    lib.displayMembers();

    return 0;
}






