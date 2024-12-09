#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    char data;
    Node *next;
};


Node *top = NULL;


void push(Node *&top, char value) {
    Node *newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = value; 
    newNode->next = top; 
    top = newNode; 
}

char pop(Node *&top) {
    if (top == NULL) {
        return -1; // Return null character if the stack is empty
    } else {
        char value = top->data; 
        Node *temp = top; 
        top = top->next; 
        delete temp; 
        return value; 
    }
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

int prefixevaluation(string stringnumeric) {
    for(int i = 0; i < stringnumeric.length(); i++) {
        char temp = stringnumeric[i];
        if(isdigit(temp)) {
            push(top, temp - '0'); // Convert char to int
        } else {
            int temp2 = pop(top);
            int temp1 = pop(top);
            int calc;
            switch(temp) {
                case '+':
                    calc = temp2 + temp1;
                    break;
                case '-':
                    calc = temp2 - temp1;
                    break;
                case '*':
                    calc = temp2 * temp1;
                    break;
                case '/':
                    calc = temp2 / temp1;
                    break;
                case '%':
                    calc = temp2 % temp1;
                    break;
                case '<':
                    calc = temp2 < temp1;
                    break;
                case '>':
                    calc = temp2 > temp1;
                    break;
                case '!':
                    calc = temp2 != temp1;
                    break;
                case '|':
                    calc = temp2 || temp1;
                    break;
                case '&':
                    calc = temp2 && temp1;
                    break;
                default:
                    break;
            }
            push(top, calc);
        }
    }
    int result = pop(top);

    // Ensure that the stack is empty after evaluation
    if (top != NULL) {
        cout<<"Error: Invalid postfix expression" << endl;
        return -1; // Indicate error
    }

    return result;
}

string infixtopostfix(string reverseinfix){
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

    string reverseinfix="";
    for(int i=infixExpression.length();i>=0;i--){
        char temp=infixExpression[i];
        reverseinfix=reverseinfix+temp;
    }
    
    string postfixExpression = infixtopostfix(reverseinfix); // Convert reversed infix to postfix
    
    string prefixExpression="";
    for(int i=postfixExpression.length()-1;i>=0;i--){
        char temp=postfixExpression[i];
        prefixExpression=prefixExpression+temp;
    }
    cout<<"PREFIX EXPRESSION: "<<prefixExpression<<endl;

    // Convert prefixExpression to a string of numeric values
    string stringnumeric;
    for(int i = 0; i < prefixExpression.length(); i++) {
        char temp = prefixExpression[i];
         
        if(isalnum(temp)) {
            switch (temp) {
                case 'a': case 'A':
                    stringnumeric += '1';
                    break;
                case 'b': case 'B':
                    stringnumeric += '2';
                    break;
                case 'c': case 'C':
                    stringnumeric += '3';
                    break;
                case 'd': case 'D':
                    stringnumeric += '4';
                    break;
                default:
                    break;
            }
        } else {
            stringnumeric += temp;
        }
    }

    cout << "Prefix numeric expression: " << stringnumeric << endl;

    // Evaluate the postfix numeric expression
    int result = prefixevaluation(stringnumeric);
    cout << "Result: " << result << endl;
    return 0; 
}
