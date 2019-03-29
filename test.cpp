#include "mystring.h"
#include <iostream>
int main(){
    MyString x = "hello";
    MyString y = " World";
 //   y[0] = 'c';
    std::cout <<( x +='c')<< std::endl;     /* hello */   /* cello */
    return 0;
}
