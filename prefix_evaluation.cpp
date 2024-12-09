#include <iostream>
#include <algorithm> 
using namespace std;

struct Node {
    int val;
    Node* next;
};
Node *top = nullptr;

void push (int num) {
    Node *ptr = (Node*) malloc (sizeof(Node));
    ptr -> val = num;
    ptr -> next = top;
    top = ptr;
}

int pop () { 
    if (top == nullptr) {
        return 0;
    }
    Node* temp = top;
    int poppedValue = top -> val;
    top = top -> next;
    free (temp);
    return poppedValue;
}

int prefixEvaluation (string prefixExpression) {
    reverse (prefixExpression.begin(), prefixExpression.end());
    for (int i = 0; i < prefixExpression.length(); i++) {
        char ch = prefixExpression[i];
        if (ch >= '0' && ch <= '9') {
            push (ch - '0');
        }
        else {
            int ans = ch;
            int lop = pop ();
            int rop = pop ();
            switch (ans) {
                case '*':
                    ans = lop * rop;
                    break;
                case '/':
                    ans = lop / rop;
                    break;
                case '+':
                    ans = lop + rop;
                    break;
                case '-':
                    ans = lop - rop;
                    break;
                case '%':
                    ans = lop % rop;
                    break;
                case '<':
                    ans = lop < rop;
                    break;
                case '>':
                    ans = lop > rop;
                    break;
                case '=':
                    ans = lop == rop;
                    break;
                case '!':
                    ans = lop != rop;
                    break;
                case '&':
                    ans = lop && rop;
                    break;
                case '||':
                    ans = lop || rop;
                    break;
                default:
                    break;
            }
            push (ans);
        }
        
    }
    int result = pop ();
    return result;
}

int main () {
    string prefixExpression;
    cout << "Enter prefix expression: ";
    cin >> prefixExpression;

    int ans = prefixEvaluation (prefixExpression);
    cout << "The answer is: " << ans;

}