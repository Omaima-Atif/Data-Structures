#include <iostream>
#include <cstdlib>
using namespace std;
struct Queue{
    int data;
    Queue *next;
};

void enqueue(Queue *&head,int value){
    Queue *newNode=(Queue*)malloc(sizeof(Queue));
    newNode->data=value;
    newNode->next=NULL;
    //-------------------IF QuEUE EMPTY-------------------
    if(head==NULL){
        head=newNode;
        return;
    }
    //------------------IF QUEUE ALREADY HAS ELEMENTS-----------------------------
    else{
        Queue *temp=head;
        while(temp->next!=NULL){
        temp=temp->next;
        }
        temp->next=newNode;
         return;
    }
}

void dequeue(Queue *&head){
    //--------------------------IF QUEUE EMPTY--------------------
    if(head==NULL){
        cout<<"Queue Underflow"<<endl;
        return;
    }
    //else
    Queue *temp=head;
    head=temp->next;
    cout<<"The dequeued value is: "<<temp->data<<endl;
    delete temp;
    return;
}

void peek(Queue *head){
     //--------------------------IF QUEUE EMPTY--------------------
     if(head==NULL){
        cout<<"Queue Underflow"<<endl;
        return;
    }
    //else
    cout<<"The top value is: "<<head->data<<endl;
    return;
}

void display(Queue *head){
    //------traversing till end of list-------------------
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    int score=-1;
    int value;
    Queue *head=NULL;
    while(score!=0){
        cout<<"enter 1 to enqueue and 2 to dequeue and 3 to peek and 4 to display"<<endl;
        cin>>score;;
        switch(score){
            case 1: 
                cout<<"enter value to insert "<<endl;
                cin>>value;
                enqueue(head,value);
                break;
            case 2:
                dequeue(head);
                break;
            case 3:
                peek(head);
                break;
            case 4:
            cout<<"the queue is:"<<endl;
                display(head);
                break;
            default:
                cout<<"Invalid choice"<<endl;

        }
    }
}