#include <stdio.h>
#include <string.h>
int n;
int eps[10][10],closure[10];

void findClosure(int state){
    for(int i=0;i<n;i++){
        if(eps[state][i]&&!closure[i]){
            closure[i]=1;
            findClosure(i);
        }
    }
}

void main(){
    printf("Enter under of E transitions: ");
    scanf("%d",&n);
    printf("Enter adj matrix(1 if transition from i-> j exists, else 0\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&eps[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        memset(closure,0,sizeof(closure));
        closure[i]=1;
        findClosure(i);

        printf("\nEClosure of Q%d: ",i);
        for(int j=0;j<n;j++){
            if(closure[j]) printf("q%d",j);
        }
        printf("\n");
    }
}