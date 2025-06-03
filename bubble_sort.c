#include <stdio.h>

void bubbleSort(int * arr,int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++) // no of passes
    {
        printf("Pass rounds ::: %d\n",i+1);
        for (int j = 0; j < n-1-i; j++) // for comparison and swaping the values
        {

            if(arr[j]> arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
       
    }   
}

void bubbleSortAdaptive(int * arr,int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++) // no of passes
    {
        printf("Pass rounds ::: %d\n",i);
                isSorted = 1;
        for (int j = 0; j < n-1-i; j++) // for comparison and swaping the values
        {

            if(arr[j]> arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }   
}

int main(){
    int arr[] ={1,5,2,6,3};
    int n = 5;

    printf("Before sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
        /* code */
    }
    printf("\nAfter sorting\n");
    bubbleSort(arr,n);
    bubbleSortAdaptive(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
        /* code */
    }

    return 0;
}