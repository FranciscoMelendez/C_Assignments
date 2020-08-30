/*
*Created by fmele on 2/25/2020.
*/
#include <stdio.h>
#include <stdlib.h>
/*#include <cstdlib>*/
#define MAXVAL 100
struct stack{
    unsigned short maxsize;     //maximum size of stack
    int top;         //top of stack
    unsigned short *items;      //pointer to stuff in stack
};

struct stack* newStack(){
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
    pt->maxsize = MAXVAL;
    pt->top = -1;
    pt->items = (unsigned short*)malloc(sizeof(unsigned short) * MAXVAL);
    return pt;
}

void push(struct stack *pt, int num){
    pt->items[++pt->top] = num;
}

int pop(struct stack *pt){
    return pt->items[pt->top--];
}

int main(int argc, char *argv[]){
    struct stack* stack = newStack();
    int i=1;	/*increment*/
    int op2;
    int num;
    while(i <= argc-1){
        if(*argv[i] != '+' && *argv[i] != '-' && *argv[i] != '*' && *argv[i] != '/' && *argv[i] != 'x'){
	    num = atoi(argv[i]);
            push(stack, num);
        }
	else{
            switch(*argv[i]){
                case '+':
                push(stack, pop(stack) + pop(stack));
                break;
		case 'x':
                push(stack, pop(stack) * pop(stack));
                break;
                case '-':
                op2 = pop(stack);
                push(stack, pop(stack) - op2);
                break;
                case '/':
                op2 = pop(stack);
                push(stack, pop(stack) / op2);
                break;
                default:
                printf("Bad input");
                break;
	    }
        }
	i++;
    }
    num = pop(stack);
    printf("Result is %d\n", num);

}
