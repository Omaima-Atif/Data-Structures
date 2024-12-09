#include <iostream>
using namespace std;
void selectionsort(int array[],int start,int end){
    if(start==end){
        return;
    }
    for(int i=start+1;i<end;i++){
        if(array[start]>array[i]){
            int temp=array[i];
            array[i]=array[start];
            array[start]=temp;
        }
    }
    selectionsort(array,start+1,end); //use ++start or start+1 (using start++ leads to infinite loop)
    
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
    selectionsort(array,0,size);
    cout<<"sorted array"<<endl;
     for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    
}