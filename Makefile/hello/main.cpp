#include <iostream>
#include "functions.h"
//包括了头文件，函数声明包含在头文件中 
using namespace std; 
int main()
{
    printhello();
    cout << "This is main:" << endl;
    cout << "The factorial of 5 is:" << factorial(5) << endl;
    return 0; 
}