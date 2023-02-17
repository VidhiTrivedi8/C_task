#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char* teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void convert(int num, char* words) {
    if (num < 0 || num > 999999) {
        strcpy(words, "Invalid input");
        return;
    }
    if (num == 0) {
        strcpy(words, "zero");
        return;
    }
    if (num < 10) {
        strcpy(words, ones[num]);
        return;
    }
    if (num < 20) {
        strcpy(words, teens[num - 10]);
        return;
    }
    if (num < 100) {
        sprintf(words, "%s %s", tens[num / 10], ones[num % 10]);
        return;
    }
    if (num < 1000) {
        sprintf(words, "%s hundred %s", ones[num / 100], "");
        if (num % 100)
            convert(num % 100, words + strlen(words));
        return;
    }
    if (num < 1000000) {
        convert(num / 1000, words);
        strcat(words, " thousand");
        if (num % 1000) {
            if (num % 1000 < 100)
                strcat(words, " and");
            strcat(words, " ");
            convert(num % 1000, words + strlen(words));
        }
        return;
    }
}

int main() {
    int num;
    char words[100];
    while (1) {
        printf("Enter a number between 0 and 999999 (enter a number >= 1000000 to exit): ");
        scanf("%d", &num);
        if (num >= 1000000) {
            break;
        }
        convert(num, words);
        printf("%s\n", words);
    }
    return 0;
}
