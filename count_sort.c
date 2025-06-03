#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int A[],int n){   
    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int findMax(int A[], int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(A[i] > max){
            max = A[i];
        }
    }

    return max;
    
}

void countSort(int A[],int n){
    int i,j;
    int max = findMax(A,n);
    int * count = (int *)malloc((max+1)*sizeof(int));
    for (i = 0; i < max+1; i++)
    {
        count[i]=0;
    }

    for (i = 0; i < n; i++)
    {
        /* code */
        count[A[i]] = count[A[i]]+1;
    }
    i=j=0;

    while(i<=max){
        if(count[i] > 0){
            A[j] = i;
            count[i] = count[i] -1;
            j++;
        }
        else{
            i++;
        }
    }
    
}

int main(){
    int A[] = {9,2,56,1,5,6,2,1};
    int n = 8;

    printArray(A, n);
    countSort(A, n);
    printArray(A, n);

    return 0;
}