#include "mystring.h"
#include <iostream>
int main(){
    MyString x = "hello";
    MyString y = " World";
 //   y[0] = 'c';
    //std::cout <<( x )<< std::endl; /* hello */   /* cello */
    std::cout << (x+y)<<std::endl;
    return 0;
}
