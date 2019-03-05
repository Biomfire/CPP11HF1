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
MyString MyString::operator+ (const MyString& otherMyString){
    MyString returnstring(new char[lenght()+otherMyString.lenght()]());
    strcat(**returnstring._value, **(this->_value));
    strcat(**returnstring._value, **otherMyString._value);
    return returnstring;
}
MyString& MyString::operator+=(MyString& otherMyString){
}
MyString& MyString::operator+(char c){

}
MyString& MyString::operator+=(char c){

}
char MyString::operator[](int i){

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
