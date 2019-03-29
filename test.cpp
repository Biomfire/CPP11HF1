#include "mystring.h"
#include <iostream>
int main(){
    MyString x = "hello";
    MyString y = " World";
 //   y[0] = 'c';
    std::cout <<( x )<< std::endl; /* hello */   /* cello */
    std::cout << (x+y)<<std::endl;
    x+=y;
    std::cout<<(x);
    std::cout<< y+'c';
    y+='c';
    std::cout<< y[1];
    const MyString xy = "Hello World";
    std::cout<<xy[0];
    MyString movestring = std::move(x);
    MyString input = " ";
    std::cin >> input;
    std::cout<< input;
    x = std::move(input);
    std::cout << x;
    return 0;
}
