#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * r = NULL;
struct Node * f = NULL;

void traverseLinkedList(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element %d \n", ptr->data);
        ptr=ptr->next;
    }
}


void enqueue(int val){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is full!\n");
    }else{   
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }else{
            r->next = n;
            r=n;
        }
    }
}


int dequeue(){
    int val = -1;
    struct Node * ptr = f;
    if(f==NULL){
        printf("Queue is empty!\n");
    }else{
        f=f->next;
        val = ptr->data;
        free(ptr);
    }

    return val;
}

int main(){
    

    traverseLinkedList(f);

    enqueue(7);
    enqueue(8);
    enqueue(9);
    
    printf("Removed element is %d\n",dequeue());
    traverseLinkedList(f);



    return 0;
}