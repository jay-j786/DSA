#include <stdio.h>

void printArray(int * a, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void selectionSort(int * arr,int n){
    int indexOfMin;
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[indexOfMin] ){
                indexOfMin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp; 
    }
}


int main(){
    int arr[]={3,1,5,4,2,0};
    int n = 6;
    printArray(arr,n);
    selectionSort(arr,n);
    printArray(arr,n);
    return 0;
}