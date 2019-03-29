#include "mystring.h"
/* ###########################
StringValue
############################*/
StringValue::StringValue(const char* cstring){
        _stringarr = new char[strlen(cstring)];
        strcpy(_stringarr, cstring);
};
void StringValue::removeCnt(){
    --_refCounter;
    if(_refCounter == 0){
        delete this;
    }
};

/*##############################
MyString
###############################*/
//######### Constructor/Deconstructor ###############################
MyString::MyString(){
    _value = new StringValue("");
    _value->addCnt();
}
MyString::MyString(const char* cstring){
    _value = new StringValue (cstring);
    _value->addCnt();
}
MyString::MyString(const MyString& otherMyString){
    this->_value = otherMyString._value;
    _value->addCnt();
}
MyString::MyString(MyString && otherMyString) noexcept{
    _value = otherMyString._value;
    otherMyString._value = nullptr;
}
MyString::~MyString(){
    _value->removeCnt();
}
//######### Operators ###############################################
MyString& MyString::operator= (const char* carr){
    _value = new StringValue(carr);
    _value->addCnt();
    return *this;
}
MyString& MyString::operator= (MyString& otherMyString){
    _value = otherMyString._value;
    _value->addCnt();
    return *this;
}
MyString& MyString::operator= (MyString && otherMyString) noexcept{
    if(this != &otherMyString){
        _value = otherMyString._value;
        otherMyString._value = nullptr;
    }
    return *this;
}
MyString MyString::operator+ (const MyString& otherMyString) const{
    MyString returnstring(new char[lenght()+otherMyString.lenght()]());
    strcat(**returnstring._value, **(this->_value));
    strcat(**returnstring._value, **otherMyString._value);
    return returnstring;
}
MyString& MyString::operator+=(MyString& otherMyString){
    MyString tmp (*this+otherMyString);
    _value->removeCnt();
   _value = tmp._value;
   return *this;
}
MyString MyString::operator+(char c) const {
    MyString returnstring(new char[lenght()+1]());
    strcpy(**returnstring._value, **(this->_value));
    returnstring._value->getStringArr()[returnstring.lenght()] = c;
    returnstring._value->getStringArr()[returnstring.lenght()+1] = '\0';
    return returnstring;
}
MyString& MyString::operator+=(char c){
    MyString tmp (*this+c);
    _value->removeCnt();
    _value = tmp._value;
    _value->addCnt();
    return *this;
}
char& MyString::operator[](int i){
    return this->_value->getStringArr()[i];

}
//#########Functions ###############################################
const int MyString::lenght ()const{
    return strlen(**_value);
}
//######### Friend Functions / Write Out, Read In ##################
std::ostream& operator<< (std::ostream& os, const MyString& mystring){
    os << **mystring._value << " "<<mystring._value->showCnt();
    return os;
}
std::istream& operator>> (std::istream& is, MyString& mystring){
    is >> **mystring._value;
    return is;
}
