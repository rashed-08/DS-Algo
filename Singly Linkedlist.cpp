#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node node;

node *head=NULL, *last=NULL;

void insert_at_first(int value)
{
    node* new_head = (node*)malloc(sizeof(node)); 
    new_head->data=value;
    new_head->next=head;
    head=new_head;
}

void insert_at_last(int value) {
    node* temp_node=(node *)malloc(sizeof(node));
    temp_node->data=value;
    temp_node->next=NULL;
    if (head==NULL) {
        head=temp_node;
        last=temp_node;
    }
    else {
        last->next=temp_node;
        last=temp_node;
    }
}

void insert_after(int key, int data) {
    node *new_node=head;
    int flag=0;
    while (new_node!=NULL) {
        if (new_node->data==key) {
            node *my_node = (node*) malloc(sizeof(node));
            my_node->data=data;
            my_node->next=new_node->next;
            new_node->next=my_node;
            cout<<data<<" inserted after "<<key<<endl;
            flag=1;
            break;
        } 
        else {
            new_node=new_node->next;
        }
    }
    if (flag==0) cout<<key<<" not found to insert"<<endl;
}

void search_item(int data) {
    node *myNode=head;
    int flag=0;
    while (myNode!=NULL) {
        if (myNode->data==data) {
            cout<<"Data item found, the item is: "<<data<<endl;
            flag=1;
            break;
        }
        myNode=myNode->next;
    }
    if (flag==0) cout<<data<<" not found in the list"<<endl;
}

void delete_item(int value) {
    node *myNode=head, *previous=NULL;
    int flag =0;
    while (myNode!=NULL) {
        if (myNode->data==value) {
            if (previous==NULL) {
                head=myNode->next;
            } else {
                previous->next=myNode->next;
            }
            cout<<value<<" deleted from list"<<endl;
            flag=1;
            break;
        }
        previous=myNode;
        myNode=myNode->next;
    }
    if (flag==0) cout<<value<<" not found to delete"<<endl;
}

void display() {
  node *ptr=head;
  while (ptr!=NULL) {
    cout<<" "<<ptr->data;
    ptr=ptr->next;
  }
  cout<<endl;
}

int main()
{
  insert_at_last(3);
  insert_at_last(8);
  insert_at_last(2);
  insert_at_last(9);
  display();
  cout<<endl; 
  insert_at_first(7);
  insert_at_first(1);
  display();
  cout<<endl;
  insert_after(2, 5);
  insert_after(9, 10);
  insert_after(15, 4);
  display();
  delete_item(8);
  delete_item(20);
  display();
  search_item(9);
  search_item(12);
  return 0;
}