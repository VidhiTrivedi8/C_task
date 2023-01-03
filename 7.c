#include <stdio.h>

int getL(char str[], int len)
{
    
    if(str[0] == '\0')
        return len;
    
    return getL(str + 1, len + 1);
}

int main()
{
     
     char str[100];
     printf("Enter any string : ");
     scanf("%s",&str);
    int i, length = 0;
    
    printf("Length: %d",getL(str, 0));
    return 0;
}
