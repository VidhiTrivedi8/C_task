#include<stdio.h>

void match(const int s, int arr[s], int search) {
    int index, i, temp;
    for (i = 0; i < s; i++)
    {
        if (arr[s] == search)
        {
            temp = 1;
            index = i;
        }
    };
    if (temp == 1)
         printf("%d",index);
    else
         printf("-1");
}

int main()
{
    printf("Enter the size of the array:");
    int s;
    scanf("%d", &s);
    int arr[s];
    int i, temp = 0;
    printf("Enter the Element of the array:\n");
    for (i = 0; i < s; i++)
    {
        scanf("%d", &arr[i]);
    }

    int search;
    printf("\nEnter the search element:");
    scanf("%d", &search);

    match(s, arr[s], search);

    return 0;
}

