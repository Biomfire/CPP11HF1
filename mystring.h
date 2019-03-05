#ifndef MYSTRING_H
#define MYSTRING_H
#include <cstring>
#include <iostream>
class StringValue{
//Member Values
private:
    int _refCounter = 0;
    char* _stringarr;
//Member Functions
private:
    ~StringValue()
    {
        std::cout << "destroyed: " << _stringarr << std::endl;
        delete _stringarr;
    }
public:

    StringValue(const char* cstring);
    void addCnt (){ ++_refCounter;};
    void removeCnt();
    // DEBUG FUNCTION
    int showCnt(){return _refCounter;};
    inline char* operator*(){
        return _stringarr;
    };
};

class MyString{
    StringValue* _value;
public:
// Üres Ctor
    MyString();
// Const Char* Ctor
    MyString(const char* cstring);
    MyString(const MyString& otherMyString);
//Dtor
    ~MyString();
    MyString& operator= (const char* carr);
    MyString& operator= (MyString& otherMyString);
    MyString operator+ (const MyString& otherMyString);
    MyString& operator+=(MyString& otherMyString);
    MyString& operator+(char c);
    MyString& operator+=(char c);
    char operator[](int i);
    const int lenght() const;
// Kiirás
//DEBUG FUNCTION EDIT BEFORE
    friend std::ostream& operator<< (std::ostream& os, const MyString& mystring);
//Beolvasás
    friend std::istream& operator>> (std::istream& is, MyString& mystring);
};
#endif // MYSTRING
