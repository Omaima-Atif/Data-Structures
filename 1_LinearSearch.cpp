#include <iostream>
using namespace std;

void linearsearch(int array[],int key,int size){
    int flag=0;
    for(int i=0;i<size;i++){
        if(array[i]==key){
            flag=1;
            cout<<"the value is at index: "<<i;
            return; //remove return if want to find two or more same values index number
        }
    }
    if(flag==0){
        cout<<"not found"<<endl;
    }
}
int main(){
    int value;
    int size;
    cout<<"enter size"<<endl;
    cin>>size;
    int array[size];
    //------------------array INSERTION------------------------------
    for(int i=0;i<size;i++){
        cout<<"enter value to insert"<<endl;
        cin>>value;
        array[i]=value;
        
    }
    //-----------------------------ARRAY PRINTING-------------------------------
    for(int i=0;i<size;i++){
        cout<<array [i]<<" ";
    }
    cout<<endl; 
    //---------------------------tAKING VALUE AND SEARCHING----------------------------
    int key;
    cout<<" enter value to search: "<<endl;
    cin>>key;
    linearsearch(array,key,size);
}