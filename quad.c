#include<stdio.h>
#include<string.h>

struct tac{
	char op1[10];
	char op2[10];
	char op;
	char result[10];
}ex[10];


int findIndex(char *temp,struct tac ex[],int n){
	for(int i=0 ; i<n ; i++){
		if(strcmp(ex[i].result, temp)==0)
			return i;
	}
	return -1;
}

int main(){
	int n;
	printf("Enter no. of expressions:");
	scanf("%d",&n);
	printf("Enter expressions:\n");
	for(int i=0 ; i<n ; i++){
		scanf("%s = %s %c %s", ex[i].result, ex[i].op1, &ex[i].op, ex[i].op2);
	}
	
	printf("\nQUADRUPLES\n");
	printf("----------\n");
	printf("\n%-12s %-12s %-12s %-12s\n","OPERATOR","OPERAND 1","OPERAND 2","RESULT");
	
	for(int i=0 ; i<n ; i++){
		printf("%-12c %-12s %-12s %-12s\n",ex[i].op, ex[i].op1, ex[i].op2, ex[i].result);
	}
	
	
	printf("\nTRIPLES\n");
	printf("-------\n");
	printf("\n%-12s %-12s %-12s %-12s\n","INDEX","OPERATOR","OPERAND 1","OPERAND 2");
	
	for(int i=0 ; i<n ; i++){
		char arg1[10],arg2[10];
		int idx1,idx2;
		
		idx1=findIndex(ex[i].op1,ex,n);
		idx2=findIndex(ex[i].op2,ex,n);
		
		if(idx1!=-1)
			sprintf(arg1,"(%d)",idx1);
		else
			strcpy(arg1,ex[i].op1);
		if(idx2!=-1)
			sprintf(arg2,"(%d)",idx2);
		else
			strcpy(arg2,ex[i].op2);
		
		printf("%-12d %-12c %-12s %-12s\n",i,ex[i].op,arg1,arg2);
	}
	
	
	return 0;
}