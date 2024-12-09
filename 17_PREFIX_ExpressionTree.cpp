 #include <iostream>
 #include <cstdlib>
 using namespace std;
 
 struct TreeNode{
     char data;
     TreeNode *left;
     TreeNode *right;
 };
 
 struct Stack{
     TreeNode *node;
     Stack *next;
 };
 
 Stack *top=NULL;
 void push(TreeNode *TNode){
     Stack *Snode=(Stack*)malloc(sizeof(Stack));
     Snode->node=TNode;  //Initializing stack node to tree node
     Snode->next=top;
     top=Snode;
 }
 
 TreeNode *pop(){
    if (top == NULL){
        return NULL;
     }

     TreeNode *popped=top->node;  //storing top of stack node
     Stack *temp=top;
     top=top->next;
     delete temp;
     return popped;
 }
 string reverseString(string str){
  string revString;
  for (int i = 0; i < str.length(); i++){
    revString = str[i] + revString;
  }
  return revString;
}

TreeNode *buildExpressionTree(string prefix){
    string reverseprefix=reverseString(prefix);
    for(int i=0;i<reverseprefix.length();i++){
        char curr=reverseprefix[i];
        if(isalnum(curr) ){
            TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
            node->data=curr;
            node->left=NULL;
            node->right=NULL;
            push(node);
         }
        else{
            TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
            node->data=curr;
            node->left=pop();
            node->right=pop();
            push(node);
        }
    }
    // After processing the entire postfix expression, the last node remaining in the stack is the root of the expression tree
    TreeNode *root = pop();
    return root;
}


void preOrderTraversal(TreeNode *root){
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
}

 
 int main(){
     string prefixEq = "%-+ab*cd/^fg-hi";
     TreeNode *root=buildExpressionTree(prefixEq);
     preOrderTraversal(root);
}
 