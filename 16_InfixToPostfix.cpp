#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node *next;
};


Node *top = NULL;


void push(Node *&top, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = value; 
    newNode->next = top; 
    top = newNode; 
}


char pop(Node *&top) {
    if (top == NULL) {
        return '\0'; // Return null character if the stack is empty
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


string infixtopostfix(string infixEquation) {
    string postfix = "";
    for (int i = 0; i < infixEquation.length(); i++) {
        char curr = infixEquation[i];
        if (isalnum(curr)) { 
            postfix = postfix + curr; 
        }

        // If the character is an opening parenthesis  Push it onto the stack
        else if(curr=='('){ 
            push(top,curr); 
        }

        // If the character is a closing parenthesis Pop operators from the stack until '(' is encountered and append
        else if(curr==')'){ 
            while(top!=NULL && top->data!='('){ 
                postfix=postfix+pop(top); 
            }
            pop(top); // Pop '(' from the stack
        }

         // If the character is an operator
        else{
            postfix=postfix+" "; // Add space before appending operators to postfix expression
            while(top!=NULL && precedence(curr)<=precedence(top->data)){ // Pop operators from the stack with higher or equal precedence
                postfix=postfix+pop(top); // Append the popped operator to the postfix expression
            }
            push(top,curr); // Push the current operator onto the stack
        }
    }
    // Pop any remaining operators from the stack
    while (top!=NULL) {
        postfix =postfix+ pop(top);
    }

    return postfix; 
}

int main(){
    string infixExpression;
    cout << "Enter infix expression: ";
    getline(cin, infixExpression); // Input infix expression from the user

    string postfixExpression = infixtopostfix(infixExpression); // Convert infix to postfix
    cout << "Postfix expression: " << postfixExpression << endl; // Output the postfix expression

    return 0; 
}
