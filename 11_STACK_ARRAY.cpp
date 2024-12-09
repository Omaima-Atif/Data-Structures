#include <iostream>
using namespace std;

void isempty(int top){
    if(top==-1){
        cout<<"Stack UnderFLOW"<<endl;
        return;
    }
  
}

void isFull(int top,int size){
    if(top==size-1){
        cout<<"Stack OverFlow"<<endl;
        return;
    }
    
}

void push(int &top,int stack[],int value,int size){
    //-------------------checks for overflow condition------------------
    isFull(top,size);
    top++;
    stack[top]=value;
    return;
}

int pop(int stack[],int &top,int &popvalue){
    isempty(top);
    popvalue=stack[top];
    top--;
    return popvalue;
}
void peek(int stack[],int top){
    cout<<"the top is:"<<stack[top]<<endl;
    return;
    
}
void display(int stack[],int top){
    for(int i=0;i<=top;i++){
        cout<<stack[i]<<" ";
        
    }
    cout<<endl;
    return;
}
int main(){
    int size;
    int value;
    int popvalue;
    cout<<"Enter size of Stack: "<<endl;
    cin>>size;
    int stack[size];
    int top=-1;
    int score=-1;
    while(score!=0){
        cout<<"Enter (1) to push (2) to pop (3) to display an (4) to peek "<<endl;
        cin>>score;
        switch(score){
        case 1:
            cout<<"Enter value to push: "<<endl;
            cin>>value;
            push(top,stack,value,size);
            break;
        case 2:
            //checks if the list is not empty and is not returning address
            if (isempty){
                cout<<"cannot pop"<<endl;
            }
            //else
            pop(stack,top,popvalue);
           
            break;
            
        case 3:
            cout<<"the values in stack are: "<<endl;
            display(stack,top);
            break;
        case 4:
            peek(stack,top);
            break;
      
        default:
            cout<<"invald choice"<<endl;
            
            
        }
    }
}