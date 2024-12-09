#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next=NULL;
};
int count;
void sortedInsertion(Node *&head,int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    if (head==NULL){
        head=newNode;
        head->next=head;
        
    }
   
    //-------------------IF VALUE INSERTED AT HEAD---------------------------
    else if(head->data>value){
        Node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newNode->next=head;
        temp->next=newNode;
        head=newNode;
        return;
    }
    //-----------------------IF VALUE IS INSERTED AT TAIL OR RANDOM POSITION------------------------
    else{
        Node *temp=head;
        while(temp->next!=head && temp->next->data<value){
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
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        count=count+1;
        return;
    }
    //--------------INSERTION AT HEAD------------------------
    else if(position==0){
        Node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newNode->next=head;
        temp->next=newNode;
        head=newNode;
        count=count+1;
        return;
    }
    //--------------------INSERTION AT TAIL----------------------------
    else if(position==-1){
        Node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newNode->next=head;
        temp->next=newNode;
        count=count+1;
        return;
    }
    //--------------------------IF INVALID POSITION INPUT---------------------
    else if(position>count-1){
        cout<<"invalid position"<<endl;
        return;
    }
    //--------------------INSERTION AT ANY OTHER POSITION---------------------
    else{
        int index=0;
        Node *temp=head;
        while(index!=position-1 && index<=count){
            temp=temp->next;
            index=index+1;
        }
        newNode->next=temp->next;;
        temp->next=newNode;
        
        count=count+1;
        return;
    }  
    
}
void print(Node *head){
    //---------------------IF LIST IS EMPTY------------------------------
    if(head==NULL){
        cout<<"empty list "<<endl;
        return;
    }
    //-----------------------ELSE (using do while to traverse till end of list)----------------------
    Node *temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    } while(temp!=head);
    cout<<endl;
    return;
}


void search(Node *head,int value){
    Node *temp=head;
    int index=0;
    int flag=0;
    //-----------------do while to traverse till end of list-----------------------------
    do{
        //-------------------IF VALUE FOUND-----------------------------
        if(temp->data==value){
            flag=1;
            cout<<"found at index"<<index<<endl;
            return;
        }
        //-----traversing-----------
        temp=temp->next;
        index=index+1;
    } while ( temp!=head );
    //-----------------------IF NOT FOUND TILL END OF LIST-------------------------
    if(flag==0){
        cout<<"not found"<<endl;
        return;
    }
    
}

void deletion(Node *&head,int value){
    
    //----------------------List empty--------------------
    if(head==NULL){
        cout<<"list empty"<<endl;
        return;
    }
    Node *temp=head;
    do{
        
        //-----------------found at head and single element---------------------
        if(head->data==value && head->next==head){
            cout<<" single element found and deleted"<<endl;
            delete head;
            count=count-1;
            return;
        }
        
        //-----------------found at head--------------------------
        else if(head->data==value){
            Node *traverse=head;
           // Node *temp1=head;
            while(traverse->next!=head){
                traverse=traverse->next;
            }
            traverse->next=head->next;
            head=temp->next;
            delete temp;
            count=count-1;
            return;
        }
        
        //---------------------found at random position or at tail----------------------
        else if(temp->next->data==value){
            Node *deleteNode=temp->next;
            temp->next=deleteNode->next;
            delete deleteNode;
            count=count-1;
            return;
        }
        temp=temp->next;
        
    } while(temp!=head);
    
    //------------------IF NOT FOUND TILL END OF LIST----------------------------
    cout<<"not found"<<endl;
}

void deleteAll(Node *&head){
    
    while(head->next!=head){
        Node *temp=head;
        Node *traverse=head;
        while(traverse->next!=head){
            traverse=traverse->next;
        }
        traverse->next=temp->next;
        head=temp->next;
        delete temp;
        count=count-1;
    }
    delete head;
    cout<<"ALL deleted"<<endl;
    return;
}

int main()
{
    Node *head=NULL;
    int value; // used in insertion and sorted insertion to take input
    int position; // used in insertion to insert at specific position
    int tosearch; // used in search to take search input
    int todelete; // used in delete to delete specific value 
    int score; // used in switch 
    cout<<"enter (1) to INSERT   and (2) to PRINT   and (3) to SEARCH    and (4) to DELETE   and (5) to DELETE ALL   and (6) for SORTED INSERTION    and (0) to EXIT"<<endl;
    cin>>score;
    while(score!=0){
        cout<<"enter (1) to INSERT   and (2) to PRINT   and (3) to SEARCH    and (4) to DELETE   and (5) to DELETE ALL   and (6) for SORTED INSERTION  and (7) for reversing  and (0) to EXIT"<<endl;
        cin>>score;
        switch(score){
            case 1:
                cout<<"Enter value to insert "<<endl;
                cin>>value;
                cout<<"enter (0) to insert at head or (-1) to insert at tail or enter index no to insert at: "<<endl;
                cin>>position;
                insertion(head,value,position);
                cout<<"the updated count is: "<<count<<endl;
                break;
            case 2:
                print(head);
                break;
            case 3:
                cout<<"enter value to search: "<<endl;
                cin>>tosearch;
                search(head,tosearch);
                break;
            case 4:
                cout<<"Enter value to delete: "<<endl;
                cin>>todelete;
                deletion(head,todelete);
                cout<<"the updated count is: "<<count<<endl;
                break;
            case 5:
                deleteAll(head);
                break;
            case 6:
                cout<<"enter value to insert"<<endl;
                cin>>value;
                sortedInsertion(head,value);
                break;
            
            default:
                cout<<"invalid choice"<<endl;
                break;
            
        }
    }
}

