#include <iostream>
using namespace std;
void insertionsort(int array[],int start,int end){
  if(start==end){
      return;
  }
  int temp=array[start];
  int j=start-1;
  while(array[j]>temp && j>=0 ){
      array[j+1]=array[j];
      j--;
  }
  array[j+1]=temp;
  insertionsort(array,start+1,end);
  
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
    insertionsort(array,1,size);
    cout<<"sorted array"<<endl;
     for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    
}