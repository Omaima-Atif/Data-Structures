#include <iostream>
using namespace std;
void bubblesort(int array[],int start,int end){
    if(start==end-1){
        return;
    }
    for(int i=0;i<end-1;i++){
        if(array[i]>array[i+1]){
            int temp=array[i];
            array[i]=array[i+1];
            array[i+1]=temp;
        }
    }
    bubblesort(array,start,end-1);
}
int main(){
    int size;
    cout<<"enter size: "<<endl;
    cin>>size;
    int array[size];
    int value;
    //-------------------TAKING VALUES OF ARRAY------------------
    for(int i=0;i<size;i++){
        cout<<"enter value to insert"<<endl;
        cin>>value;
        array[i]=value;
    }
    //-----------------------ARRAY PRINTING(UNSORTED)-----------------------
    cout<<"unsorted array: "<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    //----------------------Function calling and printing sorted ARRAY------------------
    bubblesort(array,0,size);
    cout<<"sorted array"<<endl;
     for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    
}