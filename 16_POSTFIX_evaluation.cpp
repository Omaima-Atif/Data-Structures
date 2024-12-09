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

int postfixevaluation(string stringnumeric) {
    for(int i = 0; i < stringnumeric.length(); i++) {
        char temp = stringnumeric[i];
        if(isdigit(temp)) {
            push(top, temp - '0'); // Convert char to int
        } else {
            int temp1 = pop(top);
            int temp2 = pop(top);
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
        cout << "Error: Invalid postfix expression" << endl;
        return -1; // Indicate error
    }

    return result;
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
            //postfix=postfix+" "; // Add space before appending operators to postfix expression
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
    
    // Convert postfixExpression to a string of numeric values
    string stringnumeric;
    for(int i = 0; i < postfixExpression.length(); i++) {
        char temp = postfixExpression[i];
         
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

    cout << "Postfix numeric expression: " << stringnumeric << endl;

    // Evaluate the postfix numeric expression
    int result = postfixevaluation(stringnumeric);
    cout << "Result: " << result << endl;
    return 0; 
}
