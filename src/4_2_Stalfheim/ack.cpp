#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

using namespace std;

int calc(int num1, int num2, char op);
int pop();
bool push(int x);
bool isEmpty();
bool isFull();

int top;
int stack[MAX];


int main(void){
    top = 0;
    char op[100];
    
    cout << "enter formula" << endl;

    while((op = cin.get()) != '\n'){
        if(op[0] == '+' || op[0] == '-' || op[0] == '*'){
            int result = calc(pop(), pop(), op[0]);
            push(result);

        }else{
            push(atoi(op));
        }
    }

    cout << pop() << endl;
}


int calc(int num1, int num2, char op){
    cout << op << endl;
    switch(op){
        case '+':
            return num1 + num2;
        
        case '-':
            return num1 - num2;

        case '*':
            return num1 * num2;

        default:
            return false;
    }
}


int pop(){
    if(isEmpty()){
        return false;
    }
    return stack[top--];
}


bool push(int x){
    if(isFull()){
        return false;
    }
    stack[++top] = x;
    return true;
}


bool isEmpty(){
    if(top == 0){
        return true;
    }
    return false;
}


bool isFull(){
    if(top == MAX-1){
        return true;
    }
    return false;
}