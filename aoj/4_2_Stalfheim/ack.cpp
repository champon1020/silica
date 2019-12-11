#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


int calc(int num1, int num2, char op);
int pop();
void push(int x);

int top;
int stack[MAX];


int main(void){
    top = 0;
    char op[100];
    
    std::cout << "enter formula" << std::endl;

    while(scanf("%s", op) != EOF){
        if(op[0] == '+' || op[0] == '-' || op[0] == '*'){
            push(calc(pop(), pop(), op[0]));

        }else{
            push(atoi(op));
        }

        std::cout << "stack[top] = " << stack[top] << std::endl;
    }
}


int calc(int num1, int num2, char op){
    switch(op){
        case '+':
            return num1 + num2;
        
        case '-':
            return num1 - num2;

        case '*':
            return num1 * num2;

        default:
            std::cout << "error" << std::endl;
            break;
    }

    return -1;
}


int pop(){
    return stack[top--];
}


void push(int x){
    stack[++top] = x;
}