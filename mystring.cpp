#include "mystring.h"
/* ###########################
StringValue
############################*/
StringValue::StringValue(const char* cstring){
        _stringarr = new char[strlen(cstring)+1];
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
    std::cout<<"ctor ";
    _value = new StringValue("");
    _value->addCnt();
}
MyString::MyString(const char* cstring){
    std::cout<<"strctor ";
    _value = new StringValue (cstring);
    _value->addCnt();
}
MyString::MyString(const MyString& otherMyString){
    std::cout<<"copy ctor ";
    this->_value = otherMyString._value;
    _value->addCnt();
}
MyString::MyString(MyString && otherMyString) noexcept{
    std::cout<<"move ctor ";
    _value = otherMyString._value;
    otherMyString._value = nullptr;
}
MyString::~MyString(){
    std::cout<<"dtor ";
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
    char tmp [lenght()+otherMyString.lenght()+1];
    strcpy(tmp, **(this->_value));
    strcat(tmp, **otherMyString._value);
    return MyString(tmp);
}
MyString& MyString::operator+=(MyString& otherMyString){
    MyString tmp ((*this)+otherMyString);
    _value->removeCnt();
   _value = tmp._value;
   _value->addCnt();
    std::cout << tmp;
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
    os << **mystring._value << " "<<mystring._value->showCnt() << " " ;
    return os;
}
std::istream& operator>> (std::istream& is, MyString& mystring){
    is >> **mystring._value;
    return is;
}
