#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
};
int count=-1;

void sortedInsertion(Node *&head,int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    //----------------------INSERTING HEAD------------------
    if(head==NULL){
        head=newNode;
        count=count+1;
        return;
    }
    //-----------------------INSERTING AT HEAD---------------
    else if(head->data>value){
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        count=count+1;
        return;
     }
    //--------------------------------INSERTING IN BETWEEN AND TAIL----------------------------
    else {
        //traverse till value less than new node or end of list
        Node *temp=head;
        while(temp->next!=NULL && temp->next->data<value){
            temp=temp->next;
        }
        //insert at tail
        if(temp->next==NULL){
            temp->next=newNode;
            newNode->prev=temp;
            count=count+1;
            return;
        }
        // insert inbetween
        else{
            newNode->next=temp->next;
            temp->next->prev=newNode;
            temp->next=newNode;
            newNode->prev=temp;
            count=count+1;
            return;
        }
       
    }

}
void insert(Node *&head,int value,int position){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    //--------------------INSERTING HEAD------------------
    if(head==NULL){
        head=newNode;
        count=count+1;
        return;
        
    }
    //----------------------INSERTING AT HEAD------------------
    else if(position==0){
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        count=count+1;
        return;
    }
    //----------------------INVALID POSITION------------------
    else if(position>count+1 || position<0){
        cout<<"invalid position"<<endl;
        return;
    }
    //------------------------INSERTING IN BETWEEN----------------------------
    else if(position<=count){
        int index=0;
        Node *temp=head;
        while( temp->next!=NULL && index!=position-1){
            temp=temp->next;
            index=index+1;
        }
        
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next->prev=newNode;
        count=count+1;
        return;
        
    }
    //----------------------INSERTION AT TAIL-----------------------------
    else if(position==count+1){
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        count=count+1;
        return;
    }
 
}

void print(Node *head){
    //--------------------------IF EMPTY LIST-----------------------
    if(head==NULL){
        cout<<"Empty List "<<endl;
        return;
    }
    //-----------------------ELSE--------------------------------
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}

void search(Node *head,int value){
    Node *temp=head;
    int index=0;
    // traverse till found or end of list
    while(temp->next!=NULL && temp->data!=value){
        temp=temp->next;
        index=index+1;
    }
    //if found
    if(temp->data==value){
        cout<<"value found at index: "<<index<<endl;
        return;
    }
    //if not found
    else{
        cout<<"not found"<<endl;
        return;
    }
}

void deletion(Node *&head,int value){
    //----------------EMPTY LIST--------------------------
    if(head==NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    
    //------------------DELETING HEAD-------------------
    else if(head->data==value){
        Node *temp=head;
        head=temp->next;
        delete temp;
        head->prev=NULL;
        count=count-1;
        cout<<"found and deleted"<<endl;
        return;
    }
    //-----------------DELETING IN-BETWEEN AND TAIL-------------------
    else{
        Node *temp=head;
        while(temp->next!=NULL && temp->data!=value){
            temp=temp->next;
        }
        //-------------------DELETING AT nth POSITION------------------
        if(temp->data==value && temp->next!=NULL){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            cout<<"found and deleted"<<endl;
            count=count-1;
            return;
        }
        //-----------------------------DELETING AT TAIL------------------
        else if(temp->data==value && temp->next==NULL){
            temp->prev->next=NULL;
            delete temp;
            cout<<"found and deleted"<<endl;
            count=count-1;
            return;
        }
        //------------------------IF NOT FOUND-----------------------
        else{
            cout<<"NOT FOUND"<<endl;
            return;
        }
    }
    
}

void deleteAll(Node *&head){
    //---------------------------EMPTY LIST-----------------
    if(head==NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    //----------------------------DELETING ALL---------------------
    while(head!=NULL){
        //deleting head
        if(head->next==NULL){
            delete head;
            count=count-1;
            cout<<"ALL DELETED"<<endl;
            head=NULL;
            return;
        }
        //traversing and deleting till head->next becomes NULL
        Node *temp=head;
        head=temp->next;
        delete temp;
        count=count-1;
        head->prev=NULL;
        
    }
    
    return;
}
void reverse(Node *&head) {
    Node *current = head;
    Node *temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        head = current;
        current = current->prev;
    }
}

int main(){
    Node *head=NULL;
    int score=-1;
    int position; //used in insert to take position to insert input
    int value;    //used in insert and sorted insert
    int tosearch; //used in search as to search key input
    int todelete; // used as a key to take delete value input
    while(score!=0){
        cout<<"Enter (1) to insert and (2) to print and (3) to search and (4) to delete and (5) to Delete All and (6) for Sorted Insertion"<<endl;
        cin>>score;
        switch(score){
            case 1: 
                cout<<"enter value to insert"<<endl;
                cin>>value;
                cout<<"enter (0) to INSERT at HEAD  (OR)  enter POSITION to INSERT at"<<endl;
                cin>>position;
                insert(head,value,position);
                break;
            case 2:
                cout<<"The list is: ";
                print(head);
                break;
            case 3:
                cout<<"Enter value to search: "<<endl;
                cin>>tosearch;
                search(head,tosearch);
                break;
            case 4:
                cout<<"Enter value to delete: "<<endl;
                cin>>todelete;
                deletion(head,todelete);
                break;
            case 5:
                deleteAll(head);
                break;
            case 6:
                cout<<"enter value to insert"<<endl;
                cin>>value;
                sortedInsertion(head,value);
                break;
            case 7:
                cout << "Reversing the list..." << endl;
                reverse(head);
                cout << "List reversed successfully!" << endl;
                break;

            default:
                cout<<"INVALID CHOICE"<<endl;
        }
    }
        

}