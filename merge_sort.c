#include <stdio.h>

void printArray(int A[],int n){
    for(int i=0; i< n-1; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void merge(int A[], int low, int mid, int high){
    int i,j,k; int B[100];
    i = low; j = mid+1; k = low;
    while(i<=mid && j<=high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++; k++; 
        }else{
            B[k] = A[j];
            j++; k++;
        }
    }

    while(i<=mid){
        B[k] = A[i];
        i++; k++;
    }

    while(j<=high){
        B[k] = A[j];
        j++; k++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

int main(){
    int A[] = {9,2,56,1,5,6,2,1};
    int n = 7;

    printArray(A, n+1);
    mergeSort(A, 0, n-1);
    printArray(A, n+1);

    return 0;
}