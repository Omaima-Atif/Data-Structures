#include <iostream>
using namespace std;
void selectionsort(int array[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(array[i]>array[j]){
                int temp=array[j];
                array[j]=array[i];
                array[i]=temp;
            }
        }
    }
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
    selectionsort(array,size);
    cout<<"sorted array"<<endl;
     for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    
}