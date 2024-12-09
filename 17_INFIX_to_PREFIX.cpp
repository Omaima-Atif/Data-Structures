#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
    char data;
    Node *next;
};

Node *top=NULL;

void push(Node *&top,int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=top;
    top=newNode;
    return;
}

char pop(Node *&top){
    if(top==NULL){
        return -1;
    }
    char value=top->data;
    Node *temp=top;
    top=top->next;
    delete temp;
    return value;
}
int precedence(char ch) {
    if (ch == '|') {
        return 1;
    } else if (ch == '&') {
        return 2;
    } else if (ch == '=' || ch == '!') {
        return 3;
    } else if (ch == '<' || ch == '>') {
        return 4;
    } else if (ch == '+' || ch == '-') {
        return 5;
    } else if (ch == '*' || ch == '/' || ch == '%') {
        return 6;
    } else {
        return -1; // Return -1 for unknown operators
    }
}

string infixtoprefix(string reverseinfix){
    string prefix=" ";
    for(int i=0;i<reverseinfix.length();i++){
        char temp=reverseinfix[i];
        if(isalnum(temp)){
            prefix=prefix+temp;
        }
        else if(temp==')'){
            push(top,temp);
            
        }
        else if(temp=='('){
            while( top!=NULL && top->data!=')'){
                prefix=prefix+pop(top);
            }
            pop(top); //pop'('
        }
        else{
            prefix=prefix+" ";
            while(top!=NULL && precedence(temp)<precedence(top->data)){
                prefix=prefix+pop(top);
            }
            push(top,temp);  //push current operator
        }
         
    }
    while(top!=NULL){
            prefix=prefix+pop(top);
    }
    return prefix;
}

int main(){
    string infixExpression;
    cout << "Enter infix expression: ";
    getline(cin, infixExpression); // Input infix expression from the user
    
    string reverseinfix=" ";
    for(int i=infixExpression.length()-1;i>=0;i--){
        char temp=infixExpression[i];
        reverseinfix=reverseinfix+temp;
    }
    string prefixExpression = infixtoprefix(reverseinfix); // Convert infix to prefix
    string finalprefix=" ";
    for(int i=prefixExpression.length()-1;i>=0;i--){
        char temp=prefixExpression[i];
        finalprefix=finalprefix+temp;
    }
    cout << "Prefix expression: " << finalprefix << endl; // Output the prefix expression

    return 0; 
}