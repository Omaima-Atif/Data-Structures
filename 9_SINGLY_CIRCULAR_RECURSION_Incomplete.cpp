
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int data;
    Node *next;
};
int count=0;
Node *insertTraverse(Node *head,Node *temp){
    if(temp->next==head){
        cout<<temp->data<<" ";
        return temp;
    }
     insertTraverse(head,temp->next);
}
void insert(Node *&head,Node *&temp,int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        head->next=head;
        temp=head;
        return;
    }
    temp=head;
    insertTraverse(head,temp);
         newNode->next=temp->next;
        temp->next=newNode;
        temp=newNode;
        return;
        
    

       insert(head,temp->next,value);
    
    

}

void print(Node *head,Node *&temp){
    if(head==NULL){
        cout<<"empty list"<<endl;
        return;
    }
    else if(head->next==head){
        cout<<" single element in list"<<head->data<<endl;
        return;
    }
   cout << temp->data << " ";
    if (temp->next != head) {
        print(head, temp->next);
    } else {
        cout << endl;
    }
}
    
    

int main(){
    int value;
    int position;
    Node *head=NULL;
    Node *temp=NULL;
    int score;
    cout<<"enter 1 to insert"<<endl;
    cin>>score;
    while(score!=0){
        cout<<"enter 1 to insert and 2 to print"<<endl;
        cin>>score;
        switch(score){
            case 1:
                cout<<"ENTER VALUE TO INSERT"<<endl;
                cin>>value;
                
                insert(head,temp,value);
                break;
            case 2:
            cout<<"The list is: "<<endl;
                print(head,head);
                cout<<endl;
                break;
                
        }
    }
}