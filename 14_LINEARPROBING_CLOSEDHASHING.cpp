 #include <iostream>
 using namespace std;
 
 void insertion(int key,int size,int array[]){
     int probing=0;   //find no. of probings
     int index=key%size; 
     int originalindex=index;
     
     //------------------TrAVERSING ARRAY TILL EMPTY POSITION IS FOUND---------------
     while(array[index]!=-1){
         index=(index+1)%size;
         probing=probing+1;
         
         //------------reaches where it started from and no emty positions found in between-----
         if(index==originalindex){
             cout<<"NO MORE SPACE"<<endl;
             return;
         }
     }
     
     //--------------INSERTION AT AVAILABLE POSITION---------------------
     array[index]=key;
     cout<<key<<" is inserted in "<<probing<<" probing(s)"<<endl;
 }
 
 int search(int key,int size,int array[]){
     int index=key%size;
     int originalindex=index;
     
     //------------traversing till that value to serach is found-------------
     while(array[index]!=key){
         index=(index+1)%size;
         //----------if no value at that calculated index or till reaching the end of list-------
         if(array[index]==-1 || index==originalindex){
             cout<<"not found"<<endl;
             return -1;
         }
         
     }
     
     //----------------else if found----------------------
     cout<<"Found at Index No."<<index<<endl;
     return index;
 }
 
 void print(int array[],int size){
     //-----------------traversing the whole list and printing elements or empty------------
     for(int i=0;i<size;i++){
         if(array[i]==-1){
             cout<<"Empty"<<" ";
         }
         else{
             cout<<array[i]<<" ";
         }
     }
     cout<<endl;
 }
 
 void deletion(int key,int size,int array[]){
     
     //------calling search function to find index of value to be deleted
     int index=search( key, size, array);
     
     //------------if index found------------------------
     if(index!=-1){
         cout<<"value found at index "<<index<<" and deleted"<<endl;
         array[index]=-1;
         return;
     }
 }
 int main(){
     int size=10;
     int hashtable[size];
     int value;  //used in insertion
     int tosearch; //used in tosearch
     int todelete; //used in deletiom
     //---------------INITIALIZNG ARRAY WITH -1---------------------
     for(int i=0;i<size;i++){
         hashtable[i]=-1;
     }
     
    //------------------------------switch------------
    int score=-1;
    while(score!=0){
        cout<<"Enter 1 to insert and 2 to search and 3 to print and 4 to delete"<<endl;
        cin>>score;
        switch(score){
        case 1:
            cout<<"Enter value to insert: "<<endl;
            cin>>value;
            insertion(value,size,hashtable);
            break;
        case 2:
            cout<<"Enter value to search: "<<endl;
            cin>>tosearch;
            search(tosearch,size,hashtable);
            break;
        case 3:
            print(hashtable,size);
            break;
        case 4:
            cout<<"enter value to delete"<<endl;
            cin>>todelete;
            deletion(todelete,size,hashtable);
            break;
        default:
            cout<<"Invalid choice"<<endl;
        }
    }
    
 }