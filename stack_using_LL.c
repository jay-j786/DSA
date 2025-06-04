// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};


struct Node * top = NULL;

void traversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element %d\n",ptr->data);
        ptr=ptr->next;
    }
}

int isEmpty(struct Node * ptr){
    if(ptr==NULL){
        return -1;
    }
    return 0;
}

int isFull(){
    struct Node * s = (struct Node *)malloc(sizeof(struct Node));
    if(s==NULL){
        return -1;
    }
    return 0;
}

struct Node * push(struct Node * ptr, int data){
    if(isFull()){
        printf("Stack is overflow");
    }
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->next=ptr;
    ptr=n;
    return ptr;
    
}

int pop(struct Node * ptr){
    if(isEmpty(ptr)){
        printf("Stack is underflow\n");
    }
    struct Node * n = ptr;
    top = ptr->next;
    int data = ptr->data;
    free(n);
    return data;
}

int peek(struct Node * ptr,int  position){
    struct Node * p = ptr;
        
    for (int i = 0; i < position-1 && p->next != NULL; i++)
    {
        p=p->next;
    }
    if(p!=NULL){
        return p->data;
    }

    return -1;
}

int main() {
    top = push(top, 7);
    top = push(top, 78);
    top = push(top, 90);
    traversal(top);   
    // printf("Poped Element is : %d\n",pop(top));
    // traversal(top);   

    int element = peek(top, 1);
    printf("Element at postion %d is %d",1,element);
    
    return 0;
}