#include "mystring.h"
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

