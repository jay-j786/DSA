#include <stdio.h>

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    int temp;

    do{
        while (arr[i]<=pivot){
            i++;
        }
        
        while (arr[j] > pivot){
            j--;
        }
        
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j]= temp;
        }
    }while(i<j);
    
    // swap 
    temp = arr[low];
    arr[low] = arr[j];
    arr[j]= temp;

    return j;
}

void quickSort(int arr[],int low,int high){
    int partitionIndex;

    if(low<high){
        partitionIndex = partition(arr,low,high);
        printf("Partition index %d\n",partitionIndex);
        quickSort(arr,low,partitionIndex-1); // sort left subarray
        quickSort(arr,partitionIndex+1,high); // sort right subarray
    }
    
}

int main(){

    int arr[] = {9,8,1,2,7,4,9};
    int n = 7;

    printArray(arr,n);
    quickSort(arr,0, n-1);
    printArray(arr,n);

    return 0;
}