#include<bits/stdc++.h>
using namespace std;

#define queueSize 100

int queues[queueSize], front = 0, rear = -1, dataCounter=0;

void enqueue(int value) 
{
	if (rear >= queueSize) cout<<"Queue is fulled"<<endl;
	else {
		queues[++rear]=value;
	}
}

void dequeue()
{
	if (front >= queueSize) cout<<"Queue is empty"<<endl;
	else {
		queues[++front];
	}
}

void display()
{
	for (int i=front;i<=rear;i++) {
		cout<<queues[i]<<endl;
	}
	cout<<endl;
}

int main()
{
	enqueue(3);
	enqueue(2);
	enqueue(6);
	enqueue(1);
	cout<<"Print Queue List"<<endl;
	display();
	dequeue();
	dequeue();
	cout<<"Print update list"<<endl;
	display();
	return 0;
}
