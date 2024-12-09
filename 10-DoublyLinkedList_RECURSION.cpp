#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
};
int count;

void sortedInsertion(Node *&head,Node *temp,int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    //-----------------------INSERTING HEAD---------------------
    if(head==NULL){
        head=newNode;
        count=count+1;
        return;
    }
    //-----------------------INSERTION AT HEAD-------------------
    else if(head->data>value){
        newNode->next=temp;
        temp->prev=newNode;
        head=newNode;
        count=count+1;
        return;
    }
    //--------------------------INSERTING IN BETWEEN--------------------
    else if(temp->data>value){
        newNode->next=temp;
        newNode->prev=temp->prev;
        temp->prev->next=newNode;
        temp->prev=newNode;
        count=count+1;
        return;
        
    }
    //--------------------------INSERTING AT END---------------------------
    else if(temp->next==NULL){
        temp->next=newNode;
        newNode->prev=temp;
        count=count+1;
        return;
    }
    sortedInsertion(head,temp->next,value);
}

void insertion(Node *&head, Node *&temp,int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        count=count+1;
        return;
    }
    else if(temp->next==NULL){
        temp->next=newNode;
        newNode->prev=temp;
        return;
    }
    insertion(head,temp->next,value);
}
void print(Node *head,Node *temp){
    if(head==NULL){
        cout<<"Empty List"<<endl;
        return;
        
    }
    else if(temp!=NULL){
        cout<<temp->data<<" ";
        print(head,temp->next);
    }
    cout<<endl;
    return;
}

void search(Node *head,Node *temp,int value,int index){
    if(temp==NULL){
        cout<<"NOT FOUND"<<endl;
        return;
    }
    else if(temp->data==value){
        cout<<"VALUE FOUND AT:"<<index<<endl;
        return;
    }
   
        search(head,temp->next,value,index+1);
}

void deletion(Node *&head,Node *temp,int value){
    //----------------------IF NOT FOUND TILL END OF LIST---------------------------
    if(temp==NULL){
        cout<<"NOT FOUND"<<endl;
        return;
    }
    //-----------------DELETING HEAD------------------------------
    else if(head->data==value && head->prev==NULL && head->next==NULL){
        cout<<"single element found and deleted "<<endl;
        delete head;
        head=NULL; //so that it doesnt point to blank memory location
        count=count-1;
        return;
        
    }
    //------------------DELETION AT HEAD--------------------------
    else if(head->data==value && head->prev==NULL) {
        head=temp->next;
        delete temp;
        head->prev=NULL;
        count=count-1;
        return;
    }
    //-----------------------DELETION IN BETWEEN---------------
    else if(temp->data==value && temp->next!=NULL){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
        count=count-1;
        return;
    }
    //---------------------------DELETION AT TAIL-----------------
    else if(temp->data==value && temp->next==NULL){
        temp->prev->next=NULL;
        delete temp;
        count=count-1;
        return;
    }
    deletion(head,temp->next,value);
}
void DeleteAll(Node *&head,Node *temp){
    //-------------------IF EMPTY LIST--------------------------------------------------
    if(head==NULL){
        cout<<"empty List"<<endl;
        return;
    }
    //-------------------IF ONLY ONE ELEMENT PRESENT IN LIST------------------------------------
    else if(temp->next==NULL && temp->prev==NULL){
        delete head;
        count=count-1;
        head=NULL; // Assigning null so it doesnot point to a empty memory address
        cout<<"All Deleted"<<endl;
        return;
    }
    //--------------------IF MULTIPLE ELEMENT (ALso delete continuously till reaching last element)-------------
    else{
        head=temp->next;
        delete temp;
        count=count-1;
        head->prev=NULL;
        
    }
    DeleteAll(head,temp->next);
}

int main(){
    Node *head=NULL; 
    int score=-1;
    int value; //USED AS A KEY IN INSERTION AND SORTED INSERTION
    int tosearch;// USED AS A KEY IN SEARCH 
    int index=0; // USED AS A RETURN VALUE IN SEARCH
    int todelete; // USED AS A KEY IN DELETE
    while(score!=0){
        cout<<"Enter (1) to INSERT and (2) to PRINT and (3) to search and (4) to delete and (5) to Delete All and (6) for Sorted Inserion"<<endl;
        cin>>score;
        switch(score){
            case 1:
                cout<<"enter value to insert: "<<endl;
                cin>>value;
                insertion(head,head,value);
                break;
            case 2:
                cout<<"the List Is: "<<endl;
                print(head,head);
                break;
            case 3:
                cout<<"Enter value To search"<<endl;
                cin>>tosearch;
                search(head,head,tosearch,index);
                break;
            case 4:
                cout<<"Enter value to delete: "<<endl;
                cin>>todelete;
                deletion(head,head,todelete);
                break;
            case 5:
                DeleteAll(head,head);
                break;
            case 6:
                cout<<"enter value to insert"<<endl;
                cin>>value;
                sortedInsertion(head,head,value);
                break;
            default:
                cout<<"INVALID CHOICE"<<endl;
                
            
        }
    }
}
