#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
    int data;
    Node *next;
};

void insert(int key,int size,Node *array[]){
    
    //---------------------CREATING A NODE TO STORE KEY/VALUE----------
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=key;
    newNode->next=NULL;
    
    //--------Calculating index for key by hash function
    int index=key%size; 
    
    //------if list has no value at that index in array
    if(array[index]==NULL){
        array[index]=newNode;
        return;
    }
    
    //-----searching for available position and insertng nodes {horizontally) after that array position---
    else{
        Node *temp=array[index];
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        return;
    }
}

void print(Node *array[],int size){
    //----Accessing every element of array------
    for(int i=0;i<size;i++){
        Node *temp=array[i];
        //----Accessing consecutive horizontal nodes from that index 
        
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            
        }
        cout<<endl;
    }
    
    return;
}
bool search(Node *array[],int size,int key){
    
    //----------------Finding index of that key-----------------
    int index=key%size;
    Node *temp=array[index];
    
    //-----traversing nodes at that index  till end to find----------
    while(temp!=NULL){
        //-----------if found----------
        if(temp->data==key){
            cout<<"found at index"<<index<<endl;
            return true;
        }
        temp=temp->next;
    }
    //---else if not found---
        cout<<"Not Found"<<endl;
        return false;
    
}

void deletion(Node *array[], int size, int key) {
    int index = key % size;
    Node *temp = array[index];
    Node *prev = nullptr;

    // If the key is found at the first possible position of the index
    if (temp != nullptr && temp->data == key) {
        array[index] = temp->next;
        cout << "Found and deleted at first possible position of index " << index << endl;
        delete temp;
        return;
    }

    // Searching for the key in the linked list
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is found and is not the first node
    if (temp != nullptr) {
        prev->next = temp->next;
        cout << "Found and deleted at index " << index << endl;
        delete temp;
        return;
    }

    // If the key is not found
    cout << "Not found" << endl;
}

int main(){
   Node *head=NULL;
   int size=10;
   Node *array[size]={NULL};
   int value;
   int tosearch;
   int todelete;
   int score=-1;
   while(score!=0){
        cout<<"enter 1 to insert  2 to print 3 to search and 4 to delete and 0 exit"<<endl;
        cin>>score;
       switch(score){
        
           case 1:
                cout<<"Enter Value To Insert: "<<endl;
                cin>>value;
                insert(value,size,array);
                break;
            case 2:
                cout<<"The Values are: " <<endl;
                print(array,size);
                break;
            case 3:
                cout<<"Enter Value To search"<<endl;
                cin>>tosearch;
                search(array,size,tosearch);
                break;
            case 4: 
                cout<<"enter value to delete"<<endl;
                cin>>todelete;
                deletion(array,size,todelete);
                break;
            default:
                cout<<"Invalid Choice"<<endl;
       }
   }
}