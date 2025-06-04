#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char * arr;
};

char prefixToPostfix(char infix){
    struct stack * s;
    s->size=100;
    s->top=-1;
    s->arr=(char *)malloc(s->size*sizeof(char));
    char postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));

    int i = 0;
    int j = 0;
    
}

int main(){
    char infix = "a+b";
    printf("Postfix : %s\n",prefixToPostfix(infix));
    return 0;
}