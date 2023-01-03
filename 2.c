#include <stdio.h>

int main()
{
	
	int a ;
	printf("Enter the integer: ");
	scanf("%d",&a);

int count = 0;
    
	while (a > 0) {

		
		if (a & 1) {
			count++;
		}


		a = a >> 1;
	}

	
	printf("Count of 1s in N is %d\n", count);
	
	return 0;
}
