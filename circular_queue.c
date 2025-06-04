#include <stdio.h>
#include <stdlib.h>

struct circularQueue {
    int size;
    int f,r;
    int * arr;
};

int isFull(struct circularQueue * q){
    if(((q->r + 1) % q->size) == q->f){
        printf("Queue is full\n");
        return 1;
    }
    return 0;
}

int isEmpty(struct circularQueue * q){
    if(q->f == q->r){
        printf("Queue is empty\n");
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue * q, int data){
    if(!isFull(q)){
        q->r = (q->r+1)%q->size;
        q->arr[q->r]=data;
    }
}

int dequeue(struct circularQueue * q){
    int a = -1;
    if(!isEmpty(q)){
        q->f = (q->f+1)%q->size;
        a = q->arr[q->r];
    }

    return a;

}

int main(){
    struct circularQueue q;
    q.size = 3;
    q.f = q.r =0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q,1);
    enqueue(&q,2);

    printf("Removed element is %d\n",dequeue(&q));

    isEmpty(&q);
    isFull(&q);


    return 0;
}