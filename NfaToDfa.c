// algorithm
// 1)input number of nfa states, get transitions
// nfa[i][s][j] means nfa transition from i-> j under symbol s  . Symbols ("a","b,"c) etc, which are just 0,1,2

// 2) make our D0, which is {q0}, init nfa state. dfa[0][i] are all set to 0 , other than dfa[0][0]=1. 
// 3)make a new set, dfastates, which will save all the dfa states, dfa[i] will contain set of NFA states.. dfa[1] ={0,1,1} means D0 has a transition to q1q2.
// 4)for loop from i=0 till i=dfaCount. this dfaCount can increase. 
//     if marked[i] skip this loop . Means already processed
//     marked[i]=1; so we dont keep visiting this state
//     print current DFA state , for loop from j=0; j=n , j ++, if dfaState[i][j] print(q%d,j)

//     for each symbol -> for s=0;s<symbol;s++
//         create newState, set to int newState[10]={0}

//         check if there is a dfa transition from i-> j (for j=0;j<n;j++)
//         if dfaState[i][j] 
//             for (k=0;k<n;k++)
//                 check if NFA between j-> k under symbol s
//                 if (transition[j][s][k]) add to newState
//                     newState[k]=1
//         now, check if this stateset exists or not yet.
//         index=-1
//         for x=0;x<dfaCount;x++
//             int same=1;
//             for( int y=0;y<n;y++)
//                 if dfaStates[x][y] !=newState[y] same=0; break;
//             if same idx=x break
//         if index=-1 -> new 
//             index=dfaCount
//             for (int y=0;y<n;y++)
//                 dfaStates[dfaCount][y]=newState[y]
//             dfaCount++



#include <stdio.h>

#define max 10

void main(){
    int transition[max][max][max];
    int dfaState[max][max];
    int dfaCount=0;
    int n,symbol;
    int marked[100]={0};

    printf("Enter number of nfa States and number of symbols");
    scanf("%d %d",&n,&symbol);
    
    for(int s=0;s<symbol;s++){
        printf("\nEnter Transition table. If transition from i-> j under symbol %d\n",s);
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&transition[i][s][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        dfaState[0][i] = (i==0) ? 1:0; 
    }
    dfaCount=1;

    for(int i=0;i<dfaCount;i++){
        if (marked[i]) continue;
        marked[i]=1;

        printf("\nCurrent DFA = %d ={",i);
        for(int j=0;j<n;j++){
            if (dfaState[i][j]) printf(" q%d ",j);
        }
        printf("}\n");

        for(int s=0;s<symbol;s++){
            int newState[10]={0};
            for(int j=0;j<n;j++){
                if (dfaState[i][j]){
                    for(int k=0;k<n;k++){
                        if(transition[j][s][k]){
                            newState[k]=1;
                        }
                    }
                }
            }
            int index=-1;
            for(int x=0;x<dfaCount;x++){
                int same=1;
                for(int y=0;y<n;y++){
                    if(dfaState[x][y] !=newState[y]){
                        same=0; break;
                    }
                } if (same) {index=x;break;}
            }
            if (index==-1){
                index=dfaCount;
                for(int y=0;y<n;y++){
                    dfaState[dfaCount][y]=newState[y];
                }dfaCount++;
            }
                    printf("\nDFA %d  on symbol %d -> DFA %d\n",i,s,index);

        }


    }

}
