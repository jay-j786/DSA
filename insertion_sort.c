#include <stdio.h>

void printArray(int * a, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insertionSort(int * arr,int n){
    int key, j;
    for (int i = 1; i <= n-1; i++)
    {
        key = arr[i]; 
        j=i-1; 
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}


int main(){
    int arr[]={12,54,65,23,7,9};
    int n = 6;
    printArray(arr,n);
    insertionSort(arr,n);
    printArray(arr,n);
    return 0;
}