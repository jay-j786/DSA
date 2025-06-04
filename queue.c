#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f,r;
    int * arr;
};

int isFull(struct queue * q){
    if(q->r == q->size -1){
        printf("Queue is full\n");
        return 1;
    }
    return 0;
}

int isEmpty(struct queue * q){
    if(q->f == q->r){
        printf("Queue is empty\n");
        return 1;
    }
    return 0;
}

void enqueue(struct queue * q, int data){
    if(!isFull(q)){
        q->r++;
        q->arr[q->r]=data;
    }
}

int dequeue(struct queue * q){
    int a = -1;
    if(!isEmpty(q)){
        q->f++;
        a = q->arr[q->r];
    }

    return a;

}

int main(){
    struct queue q;
    q.size = 2;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q,1);
    enqueue(&q,2);

    printf("Removed element is %d\n",dequeue(&q));
    printf("Removed element is %d\n",dequeue(&q));


    isEmpty(&q);
    isFull(&q);


    return 0;
}