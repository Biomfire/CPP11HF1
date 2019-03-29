#include "mystring.h"
/* ###########################
StringValue
############################*/
StringValue::StringValue(const char* cstring){
        _stringarr = new char[strlen(cstring)+1];
        strcpy(_stringarr, cstring);
}
void StringValue::removeCnt(){
    --_refCounter;
    if(_refCounter == 0){
        delete this;
    }
}

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
    if(_value != nullptr)
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
        if(_value != nullptr)
            _value->removeCnt();
        _value = otherMyString._value;
        otherMyString._value = nullptr;
    }
    return *this;
}
MyString MyString::operator+ (const MyString& otherMyString) const{
    char* tmp = new char[lenght()+otherMyString.lenght()+1];
    strcpy(tmp, this->_value->getStringArr());
    strcat(tmp, otherMyString._value->getStringArr());
    MyString returnstring(tmp);
    delete[] tmp;
    return returnstring;
}
MyString& MyString::operator+=(MyString& otherMyString){
    MyString tmp ((*this)+otherMyString);
    _value->removeCnt();
   _value = tmp._value;
   _value->addCnt();
   return *this;
}
MyString MyString::operator+(char c) const {
    char* tmp = new char[lenght()+2];
    strcpy(tmp, this->_value->getStringArr());
    tmp[lenght()] = c;
    tmp[lenght()+1] = '\0';
    MyString returnstring (tmp);
    delete [] tmp;
    return returnstring;
}
MyString& MyString::operator+=(char c){
    MyString tmp (*this+c);
    _value->removeCnt();
    _value = tmp._value;
    _value->addCnt();
    return *this;
}
char MyString::operator[](int i) const{
    return this->_value->getStringArr()[i];
}
char& MyString::operator[](int i){
    MyString newmystring(*this);
    _value->removeCnt();
    _value = newmystring._value;
    _value->addCnt();
    return _value->getStringArr()[i];
}
//#########Functions ###############################################
const int MyString::lenght ()const{
    return strlen(_value->getStringArr());
}
//######### Friend Functions / Write Out, Read In ##################
std::istream& operator>>(std::istream& is, MyString& instring){
    size_t size = 10;
    char* tmp = new char[size]();
    char c;
    for(size_t i = 0;(c = getchar()) != '\n' && c != EOF; i++){
        if(i+1 == size){
            char* ntmp = new char [size*=2];
            strcpy(ntmp, tmp);
            delete[] tmp;
            tmp = ntmp;
        }
        tmp[i] = c;
        tmp[i+1] = '\0';
    }
    instring = std::move(MyString(tmp));
    delete[] tmp;
    return is;
}
std::ostream& operator<< (std::ostream& os, const MyString& mystring){
    os << mystring._value->getStringArr() << " "<<mystring._value->showCnt() << " " ;
    return os;
}
