#include <stdio.h>

int main()
{
    char inp[20];
    printf("Enter the string : ");
    scanf("%s", inp);
    int i, j;
    int temp1, temp2;

    //to loop through whole input string
    for (i = 0; inp[i] != '\0'; i++) {

        // to check a-g patterns and print all alphabets if pattern matches
        if (inp[i] >= 97 && inp[i] <= 122 && inp[i + 1] == 45 && inp[i + 2] >= 97 && inp[i + 2] <= 122) {
            temp1 = inp[i];
            temp2 = inp[i + 2];
            for (j = temp1; j <= temp2; j++) {
                printf("%c", j);
            }
        }

        // to check 2-7 patterns and print all numbers if pattern matches
        if (inp[i] >= 48 && inp[i] <= 57 && inp[i + 1] == 45 && inp[i] >= 48 && inp[i] <= 57) {
            temp1 = inp[i];
            temp2 = inp[i + 2];
            for (j = temp1; j <= temp2; j++) {
                printf("%c", j);
            }
        }

    }

    return 0;
}