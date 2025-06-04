#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    char * arr;
};

int isFull(struct stack * stk){
    if(stk->top == stk->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct stack * stk){
    if(stk->top == -1){
        return 1;
    }
    return 0;
}

int push(struct stack * stk, char data){
    if(isFull(stk)){
        return 0;
    }
    stk->top++;
    stk->arr[stk->top]=data;
    return 1;
}

int pop(struct stack * stk){
    if(isEmpty(stk)){
        return 0;
    }

    stk->top--;
    return 1;
}

int parenthesisMatch(char * exp){
    struct stack * sp;
    sp->size = 100;
    sp->top=-1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));

    for (int i = 0; exp[i]!='\0'; i++)
    {
        printf("%c ",exp[i]);
        if(exp[i] == '(') {
            push(sp,'(');
        }else if(exp[i] == ')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }

    return isEmpty(sp);
    
}

int main(){
    char * exp ="(8*(3))";
    if(parenthesisMatch(exp)){
        printf("Parenthesis is matching\n");
    }else{
        printf("Parenthesis is not matching\n");
    }

    return 0;
}