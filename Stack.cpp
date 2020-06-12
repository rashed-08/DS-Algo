#include<bits/stdc++.h>
using namespace std;

#define stackSize 100

int stacks[stackSize],top=-1;

void push(int value)
{
    if (top>=stackSize) {
        cout<<"Stack is full now!"<<endl;
    } else {
        stacks[++top]=value;
    }
}

void pick() 
{
    cout<<"Peek top value of the stack"<<endl;
    cout<<stacks[top]<<endl;
}

void pop()
{
    if (top<0) cout<<"stack is underflow"<<endl;
    else {
        stacks[--top];
    }
}

void display()
{
    cout<<"Update stack printed here!"<<endl;
    for (int i=0;i<=top;i++) {
        cout<<stacks[i]<<endl;
    }
}

int main()
{
    push(7);
    push(8);
    push(2);
    push(3);
    display();
    pick();
    pop();
    display();
    return 0;
}