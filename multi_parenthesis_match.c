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
    if(stk->top ==-1){
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


char pop(struct stack * stk){
    if(isEmpty(stk)){
        return 0;
    }
    char d = stk->arr[stk->top];
    stk->top--;
    return d;
}

int isMatching(struct stack * stk, char e){
    if(isEmpty(stk)){
        return 0;
    }
    char popedValue = pop(stk);

    if(popedValue == '(' && e == ')'){
        return 1;
    }

    if(popedValue == '{' && e == '}'){
        return 1;
    }
    
    if(popedValue == '[' && e == ']'){
        return 1;
    }

    return 0;
}

int multiParenthesisMatch(char * exp){
    printf("%s\n",exp);
    struct stack * sp;
    int sizeOfExp = sizeof(exp)/sizeof(char);
    sp->size = 100;
    sp->top=-1;
    sp->arr = (char *)malloc(sizeOfExp*sizeof(char));

    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(sp,exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty(sp)){
                return 0;
            }
            if(!isMatching(sp,exp[i])){
                return 0;
            }
        }
    }

    return isEmpty(sp);
}


int main(){
    char * exp ="{7-(3-2)+[8+(99-11)]}";
    if(multiParenthesisMatch(exp)){
        printf("Parenthesis is matching\n");
    }else{
        printf("Parenthesis is not matching\n");
    }

    return 0;
}