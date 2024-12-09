#include <iostream>
using namespace std;

void bubblesort(int array[],int size){
    for(int i=1;i<size;i++){
        for(int j=0;j<size-i;j++){
            if(array[j]>array[j+1]){
            int temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
            }
        }
    }
}
int main(){
    int value;
    int size;
    cout<<"Enter size of array:"<<endl;
    cin>>size;
    int array[size];
    //-----------------------------ARRAY INSERTION------------
    for(int i=0;i<size;i++){
        cout<<"enter value to be inserted"<<endl;
        cin>>value;
        array[i]=value;
    }
    //--------------------------------ARRAY PRINTING BEFORE SORTING-----------------------
    cout<<"UNSORTED ARRAY IS: "<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
        
    }
    cout<<endl;
    //---------------------calling function and then printing----------------
    bubblesort(array,size);
    cout<<"SORTED ARRAY IS: "<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
        
    }
    cout<<endl;
}