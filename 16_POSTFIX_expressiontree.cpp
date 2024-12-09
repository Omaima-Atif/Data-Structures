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
TreeNode *buildExpressionTree(string postfix){
    for(int i=0;i<postfix.length();i++){
        char curr=postfix[i];
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
            node->right=pop();
            node->left=pop();
            push(node);
        }
    }
    // After processing the entire postfix expression, the last node remaining in the stack is the root of the expression tree
    TreeNode *root = pop();
    return root;
}


void postOrderTraversal(TreeNode *root){
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

 
 int main(){
     string postfixEq = "abc*d/x*+fd*-";
     TreeNode *root=buildExpressionTree(postfixEq);
     postOrderTraversal(root);
}
 