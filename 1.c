#include <stdio.h>
#include <string.h>

int main()
{
    char n[20];
    
    char *ones[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    char *ens[] = {" ","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char *tens[] = {" "," ","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
    char *powers[] = {"hundred","thousand"};
while(1) {   
    printf(" \nEnter the integer : ");
    scanf("%s",n);
    
    int no;
    int l = strlen(n);
    
    while(l==1){
        no = n[0]-48;
        printf("%s -> %s",n,ones[no]);
        break;
    };
    
    while(l==2){
        /*switch(n[0]) {
            case 49:
            no = (n[0]-48) + (n[1]-48);
            printf("%s -> %s",n,ens[no]);
            
            case 48:
            no = (n[0] -48) + (n[1]-48);
            printf("%s -> %s",n,tens[no]);
            
            default:
            no = n[0] -48;
            printf("%s",tens[no]);
            no = n[1] -48;
            printf("%s",ones[no]);*/

	   if(n[0] == 48){
		no = (n[0]-48) + (n[1]-48);
                printf("%s -> %s",n,tens[no]);	
        };

	   if(n[0] == 49){
		no = (n[0]-48) + (n[1]-48);
                printf("%s -> %s",n,ens[no]);	
          };

	   if(n[0] != 48 && n[0] != 49){
		        no = n[0] -48;
                printf("%s ",tens[no]);
                no = n[1] -48;
                printf("%s ",ones[no]);	
        };	
        break;

        };
	
	while(l==3){
	
	no = n[0]-48;
    printf("%s %s ",ones[no],powers[0]);
        
        if(n[1] == 48 && n[2] != 48){
		    no = n[2]-48;
            printf("%s ",ones[no]);
			
        };

	    if(n[1] == 49){
		    no = (n[1]-48) + (n[2]-48);
            printf("%s ",ens[no]);	
          };

	    if(n[1] != 48 && n[1] != 49){
		    no = n[1] -48;
            printf("%s ",tens[no]);
            no = n[2] -48;
            printf("%s ",ones[no]);	
        };
        break;
    };
	
	while(l==4){
	
	    no = n[0]-48;
        printf("%s %s ",ones[no],powers[1]);
        if(n[1] == 48 ){
		    if(n[2] == 48 && n[3] != 48){

		        no = n[3]-48;
                printf("%s ",ones[no]);
		    };
		
		    if(n[2] == 49 && n[3] != 48){
		        no = (n[2]-48) + (n[3]-48);
                printf("%s ",ens[no]);	
            };

		    if(n[2] != 48 && n[2] != 49 && n[3] != 48){
		        no = n[2] -48;
                printf("%s ",tens[no]);
                no = n[3] -48;
                printf("%s ",ones[no]);
		    };
        };
        if(n[1] != 48 && n[3] != 48){
		        no=n[1]-48;
		        printf("%s %s ",ones[no],powers[0]);
		        if(n[2] == 49 && n[3] != 48){
		          no = (n[2]-48)+(n[3]-48);
		          printf("%s ",ens[no]);
		        };
		        if(n[2] != 49 && n[3] != 48){
		            no = n[2] -48;
                    printf("%s ",tens[no]);
                    no = n[3] -48;
                    printf("%s ",ones[no]);
		        };
		    };
        break;

	

	 
	};
      
};
    
    return 0;
}
