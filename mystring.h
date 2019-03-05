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
    MyString(){
        _value = new StringValue("");
        _value->addCnt();
    }
// Const Char* Ctor
     explicit MyString(const char* cstring){
        _value = new StringValue (cstring);
        _value->addCnt();
    }
//Dtor
    ~MyString(){
        _value->removeCnt();
    }
// Kiirás
//DEBUG FUNCTION EDIT BEFORE
    inline friend std::ostream& operator<< (std::ostream& os, const MyString& mystring){
        os << **mystring._value << " "<<mystring._value->showCnt();
        return os;
        };
//Beolvasás
    inline friend std::istream& operator>> (std::istream& is, MyString& mystring){
        is >> **mystring._value;
        return is;
        };
};
#endif // MYSTRING
