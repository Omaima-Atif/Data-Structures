#include <iostream>
using namespace std;
void binarysearch(int array[],int start,int end,int key){
    int flag=0;
    int mid=(start+end)/2;
    if(array[mid]==key){
        flag=1;
        cout<<"the value is found at: "<<mid;
    }
    else if(array[mid]>key){
         binarysearch(array,start,mid-1,key);
    }
    else{
        binarysearch(array,mid+1,end,key);
    }
    
}
int main(){
    int size;
    cout<<"enter size for array"<<endl;
    cin>>size;
    int array[size];
    int value;
    int start=0;
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
     binarysearch(array,start,size,key);
    
}