// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int * arr;
};

int isFull(struct stack * s){
    if(s->top == s->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct stack * s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

int push(struct stack * s, int data){
     if(isFull(s)){
         return 0;
     }
         s->top++;
         s->arr[s->top]=data;
         return 1;        
}

int pop(struct stack * s){
    if(isEmpty(s)){
        return 0;
    }
    int prevTop = s->top;
    s->top--;
    return s->arr[prevTop];
}

int peek(struct stack * s, int index){
    if(s->top-index+1 < 0 ){
        return -1;
    }
    return s->arr[s->top-index+1];
}


int main() {
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));

    int result = push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
        
    if(result){
        printf("Element Pushed\n");
    }else{
        printf("Stack is overflow\n");
    }

    int popResult = pop(s);
    if(popResult){
        printf("Element Is Popped %d\n",popResult);
    }else{
        printf("Stack is underflow\n");
    }

    for(int i; i < s->top+1;i++){  
    printf("at Index %d element %d\n",i, peek(s,i));
    }
    return 0;
}