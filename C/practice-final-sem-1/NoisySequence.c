#include <stdio.h>

int main (){

	int input[100000] = {0},i,n,a,b,start,end,foundS = 0,curr,sum = 0;

	scanf("%d %d %d",&n,&a,&b);

	for(i = 0; i < n; i++){
		scanf("%d",&input[i]);
		if(input[i] == a && foundS == 0) {
			start = i;
			foundS = 1;
		}
		else if(input[i] == b){
			end = i;
			break;
		}
	}

	curr = a;

	for(i = 0; i < end; i++){
		if(input[start+i] == curr){
			curr++;
		}
		else {
			sum += input[start+i];
		}
	}

	printf("%d\n",sum);



	return 0;
}
