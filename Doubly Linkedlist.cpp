#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *previous;
};

typedef struct Node node;

node *head=NULL, *tail=NULL;

node *createNode(int value) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode->data=value;
    newNode->next=NULL; 
    newNode->previous=NULL; 
    return newNode;
}

void insert_at_last(int value) {
    node *createdNode = createNode(value);
    if (head==NULL) {
        head=createdNode;
        tail=createdNode;
        return;
    } 
        tail->next=createdNode; 
        createdNode->previous=tail; 
         tail=createdNode;
    
}

void insert_at_first(int value) {
    node *createdNode = createNode(value); 
    if (head==NULL) {
        head=createdNode;
        tail=createdNode;
        return;
    } 
        createdNode->next=head;
        head->previous=createdNode;
        head=createdNode;
}

void insert_at_middle(int value, int position) {
    node *newNode=createNode(value);
    
    node *temp=(node *) malloc(sizeof(node));
    temp=head;
    if (head==NULL) {
        head=newNode;
        tail=newNode;
        return;
    }
    else {
        int i=1;
        while((i < position-1) && temp->next!=NULL) { 
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        newNode->previous=temp;
        if (temp->next) {
            temp->next->previous=newNode;
        }
        temp->next=newNode;
    }
}

void deleteItem(int position) {
    if (head==NULL) {
        return;
    } else if (position==1) {
        head=head->next;
        if (head->next==NULL) {
            tail = NULL;
        } else {
            head->next->previous=NULL;
        }
        return;
    } else {
        int i=1;
        node *temp=(node *)malloc(sizeof(node));
        node *tempAnother=(node *)malloc(sizeof(node));
        temp=head;
        while ((i<position) && (temp->next!=NULL)) {
            temp=temp->next;
            i++;
        }
        if (i==position) {
            tempAnother=temp->previous;
            tempAnother->next=temp->next;
            if (temp->next==NULL) {
                tail=tempAnother;
            } else {
                temp->next->previous= tempAnother;
                free(temp);
            }
        } else {
            cout<<endl<<"Desired position not found"<<endl<<endl;
        }
    }
}

void printLinkedForward() {
    cout<<"updated list printed here: "<<endl;
    node *nodeList = head;
    while ((nodeList!=NULL)) {
        cout<<nodeList->data<<" ";
        if (nodeList==tail) break;
        nodeList=nodeList->next; 
    }
    cout<<endl;
}

void print_backward() {
    cout<<"updated list printed backward here: "<<endl;
    node *nodeList = tail;
    while (nodeList!=NULL) {
        cout<<nodeList->data<<" ";
        nodeList=nodeList->previous;
    }
    cout<<endl;
}

int main() {
    insert_at_last(6);
    printLinkedForward();
    insert_at_last(8);
    printLinkedForward();
    insert_at_first(2);
    printLinkedForward();
    insert_at_middle(12,2);
    printLinkedForward();
    print_backward();
    deleteItem(2);
    printLinkedForward();
    return 0;
}