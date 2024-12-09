#include <iostream>
#include <cmath>
using namespace std;

void insertion(int key,int size,int hashtable[]){
    int index=key%size; //changing as we are probing
    int temp=index;   //using this so initial calculated index is stored somewhere unchanged
    int i=1;
    int probing=0;
    
    //----------------if index already preoccupied----------------
    while(hashtable[index]!=-1){
        if(probing>=size){
            cout<<"No more space left"<<endl;
            return;
        }
        index=temp+pow(i,2);
        index=index%size;      //making it circular
        i=i+1;
        probing=probing+1;
    }
    
    //--------------------inserting key at found space------------
    hashtable[index]=key;
    cout<<"Insertion in: "<< probing<<" probing(s)"<<endl;
    return;
}

int search(int key,int size,int hashtable[]){
    int index=key%size;
    int temp=index;
    int i_linearprobing=0;
    int i_quadraticprobing=0;
    
     // Check if the key is already at the initial index
    if(hashtable[index]==key){
        cout<<"value found at index: "<<index<<endl;
        return index;
    }
        
    // Iterate using quadratic probing until the key is found or a threshold is reached
    while (hashtable[index]!=key && i_quadraticprobing<(size/2)){
        index=temp+pow(i_quadraticprobing,2);
        index=index%size;
        i_quadraticprobing=i_quadraticprobing+1;
        
    }
    
    // If the key is not found using quadratic probing, switch to linear probing
    while (hashtable[index]!=key && i_linearprobing<(size/2)){
        index=(index+1)%size;
        i_linearprobing=i_linearprobing+1;
    }
    
    // Check if the key is found and print the result
    if(hashtable[index]==key){
        cout<<"value found at index: "<<index<<endl;
        return index;
    }
    else{
        cout<<"NOT FOUND"<<endl;
        return -1 ;
    }
    
}
void print(int hashtable[],int size){
    for(int i=0;i<size;i++){
        cout<<"The value is: "<<hashtable[i]<<endl;
    }
    cout<<endl;
}

void deletion(int key,int size,int hashtable[]){
    
    //------------search for value using search function------------------
    int index=search(key,size,hashtable);
    
    //------------------------if found-------------------------
    if(index!=-1){
        hashtable[index]=-1;
        cout<<"found and deleted"<<endl;
        return;
    }
    
}

int main(){
    int score=-1;
    int key;
    int tosearch;
    int todelete;
    int size=10;
    int hashtable[size];
    
    //------------------INITIALIZE ARRAY Empty with -1---------------------------
    for(int i=0;i<size;i++){
        hashtable[i]=-1;
    }
    cout<<endl;
    
    //----------------------switch
    while(score!=0){
        cout<<"enter 1 to insert and 2 to search and 3 to print and 4 to delete"<<endl;
        cin>>score;
        switch(score){
            case 1:
                cout<<"enter value to insert"<<endl;
                cin>>key;
                insertion(key,size,hashtable);
                break;
            case 2:
                cout<<"enter value to search"<<endl;
                cin>>tosearch;
                search(tosearch,size,hashtable);
                break;
            case 3:
                cout<<"The values in hashtable are: "<<endl;
                print(hashtable,size);
                break;
            case 4:
                cout<<"enter value to delete"<<endl;
                cin>>todelete;
                deletion(todelete,size,hashtable);
                break;
            default:
                cout<<"invalid choice"<<endl;
        }
    }
}