#include <iostream>
using namespace std;
void binarysearch(int array[],int size,int key){
    int start=0;
    int end=size;
    int flag=0;
    int mid;
    while(flag!=1){
        mid=(start+end)/2;
        if(array[mid]==key){
            flag=1;
            cout<<"value found at index: "<<mid;
            return;
        }
        else if(array[mid]<key){
            start=mid+1;
            
        }
        else{
            end=mid-1;
        }
    }
    if(flag==0){
        cout<<"value not found"<<endl;
    }
}
int main(){
    int size;
    cout<<"enter size for array"<<endl;
    cin>>size;
    int array[size];
    int value;
    //------------------------VALUE INSERTION-----------------------------------
    for(int i=0;i<size;i++){
        cout<<"enter value to insert in array: "<<endl;
        cin>>value;
        array[i]=value;
    }
    
    //------------------------ARRAY PRINTING----------------------------------
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    //--------------------------SEARCHING-----------------------------------------
    int key;
    cout<<"enter value to search: "<<endl;
    cin>>key;
     binarysearch(array,size,key);
    
}