#include <iostream>
using namespace std;
int insertionsort(int array[],int size){
    for(int i=0;i<size;i++){
        int temp=array[i];
         int j=i-1;
         while(j>=0 && array[j]>temp){
            array[j+1]=array[j];
            j--;
         }
         array[j+1]=temp;
    }
}
int main(){
    int value;
    int size;
    cout<<"enter size of array:"<<endl;
    cin>>size;
    int array[size];
    //-----------------------------ARRAY INSERTION-------------
    for(int i=0;i<size;i++){
        cout<<"enter value to be inserted: "<<endl;
        cin>>value;
        array[i]=value;

    }
    //---------------------ARRAY PRINTING(UNSORTED------------------
    cout<<"unsorted array: "<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    //------------------function calling and printing sorted array-----------------
    insertionsort(array,value);
    cout<<"sorted array: "<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}