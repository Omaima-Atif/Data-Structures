
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int data;
    Node *next;
};
int count=0;

void SortedInsertion(Node *&head,int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    //----------------- IF HEAD IS NULL -----------------------------
    if(head==NULL){
        head=newNode;
        
        return;
    }
    //---------------------- IF NEW VALUE IS SMALLER THAN HEAD --------
    else if(head->data>value){
        newNode->next=head;
        head=newNode;
        return;
        
    }
    //----------------- IF INSERTION INBETWEEN OR AT END -----------------
    else{
        Node *temp=head;
        while(temp->next!=NULL && temp->next->data<=value ){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        return;
    }
    
}
void insertion(Node *&head,int value,int position){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        count=count+1;
        cout<<"the elements in list are: "<<count<<endl;
        return;
    }
      //-------------------PRINT IF THE GIVEN POSITION IS INVALID---------------------------
    else if(position<0 || position>count-1){
        cout<<" invalid input"<<endl;
        return;
    }
    // -------------------------Insertion At Head-----------------------
    else if(position==0){
        newNode->next=head;
        head=newNode;
        count=count+1;
        cout<<"the elements in list are: "<<count<<endl;
        return;
    }
    //-----------------AT TAIL------------------------------
    else if(position==100){
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        count=count+1;
        cout<<"the elements in list are: "<<count<<endl;
        return;
    }
    //---------------------At nth index----------------------------
    else{
    int index=0;
    Node *ntemp=head;
    while(index!=position-1 && position<count && position>=0){
        index=index+1;
        ntemp=ntemp->next;

    }
    newNode->next=ntemp->next;
    ntemp->next=newNode;
    count=count+1;
    cout<<"the elements in list are: "<<count<<endl;
   
    return;
    
}
}
void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
        
    }
    cout<<endl;
}

void search(Node *head,int value){
    int index=0;
    int flag=0;
    while(head!=NULL){
        if(head->data==value){
            cout<<"found at index: "<<index<<endl;
            flag=1;
            return;
            
        }
    head=head->next;
    index=index+1;
    }
    if(flag==0){
        cout<<" not found"<<endl;
    }

}
void Delete(Node *&head,int value){
    //---------------------empty list-------------------------------
    if(head==NULL){
        cout<<"empty list"<<endl;
        return;
    }
    Node *temp=head;
    Node *prev=NULL;
    //--------------------------DElETION AT HEAD----------------------------
    if(temp->data==value){
        head=temp->next;
        delete temp;
        count=count-1;
        cout<<"deleted and the updated count is: "<<count<<endl;
        return;
    }
    //--------------------------DElETION AT nth POSITION-------------------------
    while(temp!=NULL && temp->data!=value){
        prev=temp;
        temp=temp->next;
        
    }
    //--------------------if value not found till end of list-------------------
    if(temp==NULL){
        cout<<"value not found"<<endl;
        return;
    }
    //------------------if found------------------------------
    prev->next=temp->next;
    delete temp;
    count=count-1;
    cout<<"deleted and the updated count is: "<<count<<endl;
   
    return;
    
    
}

void DeleteAll(Node *&head){
    while(head!=NULL){
        Node *temp=head;
        head=temp->next;
        cout<<"the deleted value is "<<temp->data<<endl;
        delete temp;
        count=count-1;
        cout<<"the updated count is "<<count<<endl;
    }
    return;
}
void reversing(Node *&head){
    Node *prevnode=NULL;
    Node *currentnode=head;
    Node *nextnode=head;
    while(nextnode!=NULL){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}
int main(){
    Node *head=NULL;
    int tosearch; // parameter for ssearch function
    int value; // data equivalent of struct to take input
    int position; // insertion at  what position variable
    int todelete; //value to be deleted
    int score=-1; //switch variable
    while(score!=0){
        cout<<"enter 1 for insertion and 2 to print and 3 to search and  4 to delete and 5 to delete all and 6 for sorted insertion and 7 to reverse 0 to exit"<<endl;
        cin>>score;
        switch(score){
            case 1:
                cout<<"enter the value to be inserted: "<<endl;
                cin>>value;
                cout<<"enter (0) to insert at head and (100) to insert at tail or index no:    "<<endl;
                cin>>position;
                insertion(head,value,position);
                break;
            case 2:
                cout<<"The values in list are:"<<endl;
                print(head);
                break;
            case 3:
                cout<<"enter the value to search"<<endl;
                cin>>tosearch;
                search(head,tosearch);
                break;
            case 4:
               cout<<"enter value to delete"<<endl;
               cin>>todelete;
               Delete(head,todelete);
               break;
            case 5:
                DeleteAll(head);
                break;
            case 6:
                cout<<"enter value to insert:"<<endl;
                cin>>value;
                SortedInsertion(head,value);
                break;
            case 7:
                reversing(head);
                break;
            default:
                cout<<"invalid choice"<<endl;
        }
    }
    
}
