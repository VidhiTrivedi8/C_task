#include <stdio.h> 

//#include "8_1.c"
int compare(char[], char[]);

int main()
{
    char str1[20]; // declaration of char array  
    char str2[20]; // declaration of char array  
    printf("Enter the first string : ");
    scanf("%s", str1);
    printf("Enter the second string : ");
    scanf("%s", str2);
    int c = compare(str1, str2); // calling compare() function  
    if (c == 0)
        printf("strings are same");
    else
        printf("strings are not same");

    return 0;
}