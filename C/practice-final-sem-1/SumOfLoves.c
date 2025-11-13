#include <stdio.h>
#include <string.h>

int main (){

	char input[255]; 
	int i,n,sum = 0,val[255] = {0};

	scanf("%[^\n]%*c",input);

	n = strlen(input);
	printf("%d\n",n);

	for(i = 0; i < n; i++){
		if(input[i] >= 65 && input[i] <= 90){
			val[i] = (int)input[i] - 64;
		}
		else {
			val[i] = 27;
		}
	}

	for(i = 0; i < n; i++){
		sum += val[i] * (i+1);
	}

	for(i = 0; i < n; i++){
		printf("%d ",val[i]);
	}
	printf("\n%d\n",sum);


	return 0;
}
