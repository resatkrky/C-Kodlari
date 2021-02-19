#include <stdio.h>
#include <stdlib.h>

int carp(int **A,int **B){

    int i,j,k,m,t,n,**C;
    for(i=0;i<m;i++){
        for(j=0;j<k;j++){
            for(t=0;t<n;t++){
                C[i][j]+=A[i][j]*B[t];
            }
        }
    }
    return C;
}


int main()
{

    return 0;
}
