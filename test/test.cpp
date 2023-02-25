#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

int main()
{
    int a[3];
    std::cout << sizeof(a)/sizeof(a[0]) << std::endl;
    std::cout << (a != NULL) << std::endl;

    std::cout << (a != NULL) << std::endl;
    
    return 0;
}
