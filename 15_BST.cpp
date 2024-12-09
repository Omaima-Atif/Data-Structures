#include <iostream>
#include <cstdlib>
using namespace std;
struct BSTNode{
    int data;
    BSTNode *left;
    BSTNode *right;
};

int height(BSTNode *root){
    if(root==NULL){
        return -1;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    
    if(leftheight>rightheight){
        return leftheight+1;
    }
    else{
        return rightheight+1;
    }
}

BSTNode* insertion(BSTNode *root, int value) {
    if (root == NULL) {
        
        //--------------- Create a new node for the value and return it as the new root
        BSTNode *newNode = (BSTNode*)malloc(sizeof(BSTNode));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    //----------- If the value is less than the current node's data, go to the left subtree
    
    if (value < root->data) {
        // Recursively insert into the left subtree
        root->left = insertion(root->left, value);
    }
    
    // -------------If the value is greater than or equal to the current node's data, go to the right subtree
    else{
        // Recursively insert into the right subtree
        root->right = insertion(root->right, value);
    }

    // Return the modified root
    return root;
}

void search(BSTNode *root, int value){
    if(root==NULL){
        cout<<"value not found"<<endl;
        return;
    }
    else if(root->data==value){
        cout<<"found "<<endl;
        return;
    }
    //----------- If the value is greater than the current node's data, go to the left subtree

    else if(value>root->data){
        search(root->right,value);
    }
    
    //----------- If the value is less than the current node's data, go to the left subtree
    else{
        search(root->left,value);
    }
}

void inorder(BSTNode *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(BSTNode *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
        
    }
}

void postorder(BSTNode *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int minimum(BSTNode *root){
    if(root->left==NULL){
        return root->data;
    }
    minimum(root->left);
}

int maximum(BSTNode *root){
    if(root->right==NULL){
        return root->data;
    }
    maximum(root->right);
}

BSTNode *min(BSTNode *root){
    if(root->left==NULL){
        return root;
    }
    min(root->left);
}

BSTNode *deletion(BSTNode *root,int value){
    if(root==NULL){
        cout<<"VALUE NOT FOUND"<<endl;
        return root;
    }
    
    else if(value>root->data){
        root->right=deletion(root->right,value);
    }
    
    else if(value<root->data){
        root->left=deletion(root->left,value);
    }
    else{
        //-------------NO CHILD------------------
        if(root->left==NULL && root->right==NULL){
            BSTNode *temp=root;
            root=NULL;
            cout<<"found and deleted"<<endl;
            delete temp;
           
        }
        //------------------1 CHILD (RIGHT)-------
        else if(root->left==NULL){
            BSTNode *temp=root;
            root=root->right;
            cout<<"found and deleted"<<endl;
            delete temp;
            
            
        }
        
        //--------------1 CHILD(LEFT)-----------------
        else if(root->right==NULL){
            BSTNode *temp=root;
            root=root->left;
            delete temp;
    
        }
        //-----------2 CHILD------------------
        else{
            BSTNode *temp=min(root->right);
            root->data=temp->data;
            cout<<"found and deleted"<<endl;
            root->right = deletion(root->right, temp->data);
            //function is called recursively with root->right as the root of the subtree and temp->data as the value to be deleted. This recursive call will effectively delete the minimum node from the right subtree.
            
        }
        
        }
        return root;
    }
    
        

int main(){
    int score=-1;
    BSTNode *root=NULL;
    BSTNode *succ=NULL;
    int value;
    int tosearch;
    int todelete;
    int findsucc;
    while (score!=0){
        cout<<"Enter (1) to insert a node and   (2) to search and   (3) to inorderly traverse  and (4) to preorderly traverse   and (5) to postorderly traverse   and (6) to find minimum  and   (7) to find maximum  and (8) to delete   and (9)  to find height and (10) to find successor"<<endl;
        cin>>score;
        switch(score){
            case 1:
                cout<<"enter value to enter: "<<endl;
                cin>>value;
                root=insertion(root,value);
                break;
            case 2:
                cout<<"enter value to search"<<endl;
                cin>>tosearch;
                search(root,tosearch);
                break;
            case 3:
                cout<<"INORDER TRAVERSE: "<<endl;
                inorder(root);
                cout<<endl;
                break;
             case 4:
                cout<<"PREORDER TRAVERSE: "<<endl;
                preorder(root);
                cout<<endl;
                break;
            case 5:
                cout<<"POSTORDER TRAVERSE: "<<endl;
                postorder(root);
                cout<<endl;
                break;
            case 6:
                cout<<"MINIMUM VALUE IS: "<<minimum(root)<<endl;
                break;
            case 7:
                cout<<"MAXIMUM VALUE IS: "<<maximum(root)<<endl;
                break;
            case 8:
                cout<<"enter value to delete: "<<endl;
                cin>>todelete;
                root=deletion(root,todelete);
                break;
            case 9:
                cout<<"the height of tree is: "<<height(root)<<endl;
                break;
            /*case 10:
                cout<<"enter value to find successor of: "<<endl;
                cin>>findsucc;
                cout<<"The successor is : "<<successor(root,succ,findsucc);
                cout<<endl;
                break;
            */
            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
}