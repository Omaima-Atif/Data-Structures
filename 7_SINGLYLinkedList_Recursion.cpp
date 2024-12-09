#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
    int data;
    Node *next;
};
int count=0;
void sortedInsertion(Node *&head,int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    //---------------------INSERTING HEAD-------------------
     if(head==NULL){
        head=newNode;
        count=count+1;
        cout<<"the updated count is: "<<count<<endl;
        return;
    }
    //---------------------INSERTION AT HEAD----------------
    else if(head->data>value){
        newNode->next=head;
        head=newNode;
        count=count+1;
        cout<<"the updated count is: "<<count<<endl;
        return;
    }
    //-------------------------INSERTION AT TAIL----------------
    else if(head->next==NULL){
        head->next=newNode;
        count=count+1;
        cout<<"the updated count is: "<<count<<endl;
        return;
    }
    //--------------------------INSERTION AT nth POSITION------------
    else if( head->next->data>value ){
        newNode->next=head->next;
        head->next=newNode;
        count=count+1;
        cout<<"the updated count is: "<<count<<endl;
        return;
       
    }
    sortedInsertion(head->next,value);
}
void insertion(Node *&head,int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL ){
    head=newNode;
    count=count+1;
    cout<<"the updated count is: "<<count<<endl;
    return;
    }
    insertion(head->next,value);
}
void print(Node *head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    print(head->next);
}
void search(Node *head,int value,int index){
    //---------------------- if Not FOUND TILL END OF LIST-----------------
    if(head==NULL){
        cout<<"not found"<<endl;
        return;
    }
    
    //-----------------------IF FOUND-----------------------------------
    else if(head->data==value){
        cout<<"found at index "<<index<<endl;
        return;
    }
    
    search(head->next,value,index+1);
    
}
void deletion(Node *&head,int value){
    
    //-----------------If ONLY SINGLE VALUE-----------------------
    if(head->data==value && head->next==NULL){
        cout<<"SINGLE VALUE FOUND AND DELETED"<<endl;
        count=count-1;
        delete head;
        return;
    }
    
    // ----------------------IF VALUE NOT FOUND TILL END OF THE LIST---------------
    if(head->next==NULL){
        cout<<"not found"<<endl;
        return;
    }
    
    //-------------------------IF VALUE FOUND AT HEAD-------------------
    if(head->data==value){
        Node *temp1=head;
        head=temp1->next;
        delete temp1;
        count=count-1;
        cout<<"found and deleted and updated count is"<<count<<endl;
        return;
    }
    //------------------------IF VALUE FOUND AT ANY OTHER POSITION---------------------
    if(head->next!=NULL && head->next->data==value){
        Node *temp=head->next;
        head->next=temp->next;
        delete temp;
        count=count-1;
        cout<<"found and deleted and updated count is"<<count<<endl;
        return;
        
    }
    deletion(head->next,value);
}
void DeleteAll(Node *&head){
    //------------------------IF REACHED END OF LIST-------------------------
    if(head==NULL){
        cout<<"ALL deleted"<<endl;
        return;
    }
    Node *temp=head;
    head=temp->next;
    delete temp;
    DeleteAll(head);
}
Node* reverse(Node *head, Node *prev = nullptr) {
    if (head == nullptr) {
        // Base case: If the current node is null, return the previous node,
        // which is the new head of the reversed list.
        return prev;
    }
    
    Node *nextNode = head->next;
    head->next = prev;
    
    // Recursively call reverse with the next node as the current node and current node as the previous node.
    return reverse(nextNode, head);
}

int main(){
    int score=-1; // USED IN SWITCH
    Node *head=NULL; 
    int value; // USED IN INSERTION
    int index=0; //USED in SEARCH function and GIVES BACK INDEX AT WHICH FOUND
    int tosearch; // USED IN SEARCH TO SEARCH
    int todelete; // USED IN DELETE AS IN VALUE TO DELETE
    while(score!=0){
        cout<<"enter 1 to insert and 2 to print and 3 to search and 4 to delete and 5 To delete all and 6 for sorted insertion and 7 to reverse: "<<endl;
        cin>>score;
        switch(score){
            case 1:
                cout<<"enter the value to insert:"<<endl;
                cin>>value;
                insertion(head,value);
                break;
            case 2:
                cout<<"The values in list are:"<<endl;
                print(head);
                cout<<endl;
                break;
            case 3:
                cout<<"Enter value to search:"<<endl;
                cin>>tosearch;
                search(head,tosearch,index);
                break;
            case 4:
                cout<<"enter value to delete"<<endl;
                cin>>todelete;
                deletion(head,todelete);
                break;
            case 5:
                DeleteAll(head);
                break;
            case 6:
                cout<<"Enter value to insert"<<endl;
                cin>>value;
                sortedInsertion(head,value);
                break;
            case 7:
                 cout << "Reversing the list..." << endl;
                head = reverse(head);
                cout << "List reversed successfully!" << endl;
                break;


            default:
                cout<<"INVALID INPUT"<<endl;
        }
    }
}