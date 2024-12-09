#include <iostream>
using namespace std;
void enqueue(int &front,int &rear,int value,int queue[],int size){
    //--------------------------IF REAR BECOMES EquAL TO fRONT--------------------
    if((rear+1)%size==front){
        cout<<"Queue overflowed"<<endl ;
        return;
    }
    //----------------------IF EMPTY QUEUE------------
    else if(front==-1 && rear==-1){
        front=rear=0;
        
        queue[front]=value;
        return;
    }
    //--------------------INSERTION--------------------------
    else{
        rear=(rear+1)%size;
        queue[rear]=value;
        return;
    }
}
void dequeue(int &front,int &rear,int size,int queue[]){
        //----------------------IF EMPTY QUEUE------------
    if(front==-1 && rear==-1 ){
        cout<<"Queue empty"<<endl;
        return;
    }
    //----------------------IF ONLY ONE ELEMENT IN QUEUE
    else if(front==rear){
         cout<<"The only dequeued value is: "<<queue[front]<<endl;
        front=rear=0;
        return;
        
    }
    //----------------SIMPLE DEQUEUING--------------------------
    else{
        cout<<"the dequeued value is"<<queue[front]<<endl;
        front=(front+1)%size;
        return;
    }
}

void display(int front,int rear,int queue[],int size){
    //----------------------IF EMPTY LIST------------------------------
    if(front==-1 && rear==-1){
        cout<<"Empty list"<<endl;
        return;
    }
    //--------------------TRAVERSING AND PRINTNG TILL FRONT BECOMES EQUAL TO REAR--------------
     int i = front;
    do {
        cout << queue[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    cout << endl;
    return;
}

void peek(int front,int rear,int queue[]){
     //----------------------IF EMPTY LIST------------------------------
    if(front==-1 && rear==-1){
        cout<<"Empty list"<<endl;
        return;
    }
    else{
        cout<<"the peeked value is "<<queue[front]<<endl;
        return;
    } 
}
int main(){
    int size;
    cout<<"enter size of queue"<<endl;
    cin>>size;
    int queue[size];
    int score=-1;
    int value;
    int front=-1;
    int rear=-1;
    while(score!=0){
        cout<<"enter 1 to enqueue and 2 to dequeue and 3 to print and 4 to peek "<<endl;
        cin>>score;
        switch(score){
            case 1:
                cout<<"enter value to insert: "<<endl;
                cin>>value;
                enqueue(front,rear,value,queue,size);
                break;
            case 2: 
                dequeue
                (front ,rear,size,queue);
                break;
            case 3:
            cout<<"the values in list are"<<endl;
                display(front,rear,queue,size);
                break;
            case 4:
                peek(front,rear,queue);
                break;
            default:
                cout <<"Invalid Choice"<<endl;
        }
    }
}