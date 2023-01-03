#include <stdio.h>

int main(){

    int n, r = 0, rem;

    printf(" \n Enter the number to reverse: ");

    scanf("%d", &n);    

    while (n != 0){

        rem = n % 10;

        r = r * 10 + rem;

        n = n/10;

    }    

    printf("The reversed number is: %d", r);

    return 0;

}
