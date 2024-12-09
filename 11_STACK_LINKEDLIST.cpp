#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node *&head,int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    return;
}
void pop(Node *&head){
    //checks for stack underflow
    if(head==NULL){
        cout<<"Stack UnderFlow"<<endl;
        return;
    }
    //else
    Node *temp=head;
    head=temp->next;
    cout<<"The popped value is:"<<temp->data<<endl;
    delete temp;
    return;
}  
void peek(Node *head){
    //checks for stack underflow
    if(head==NULL){
        cout<<"Stack UnderFlow"<<endl;
        return;
    }
    //else
    cout<<"The value at the top of stack is:"<<head->data<<endl;
    return;
}
void display(Node *head){
    //checks for stack underflow
    if(head==NULL){
        cout<<"Stack UnderFlow"<<endl;
        return;
    }
    //else
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
int main(){
    int score=-1;
    Node *head=NULL;
    int value;
    while(score!=0){
        cout<<"Enter (1) to push  (2) to pop and (3) to display and (4) to peek"<<endl;
        cin>>score;
        switch(score){
            case 1:
                cout<<"enter value to insert:"<<endl;
                cin>>value;
                push(head,value);
                break;
            case 2:
                pop(head);
                break;
            case 3:
                cout<<"the elements in stack are: "<<endl;
                display(head);
                break;
            case 4:
                peek(head);
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}