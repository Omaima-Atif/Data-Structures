#include <iostream>
#include <cstdlib> // For malloc
using namespace std;

struct Tree {
    int data;
    int leftheight;
    int rightheight;
    Tree* left;
    Tree* right;
};

int maxheight(int a, int b) {
    return (a > b) ? a : b;
}

int height(Tree* node) {
    if (node == NULL) return 0;
    return maxheight(node->leftheight, node->rightheight) + 1;
}

int getBalance(Tree* node) {
    if (node == NULL) return 0;
    return node->leftheight - node->rightheight;
}

Tree* rightShift(Tree* root) {
    Tree* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

Tree* leftShift(Tree* root) {
    Tree* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

Tree* AVLinsertion(Tree*& root, int value) {
    if (root == NULL) {
        Tree* newNode = (Tree*)malloc(sizeof(Tree));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->leftheight = 0;
        newNode->rightheight = 0;
        root = newNode;
        return root;
    }

    if (value < root->data) {
        AVLinsertion(root->left, value);
        root->leftheight = maxheight(root->left->leftheight, root->left->rightheight) + 1;

        int nodeheight = root->leftheight - root->rightheight;

        if (nodeheight > 1 && value < root->left->data) {
            root = rightShift(root);
        }
        else if (nodeheight > 1 && value > root->left->data) {
            root->left = leftShift(root->left);
            root = rightShift(root);
        }
    }
    else if (value > root->data) {
        AVLinsertion(root->right, value);
        root->rightheight = maxheight(root->right->leftheight, root->right->rightheight) + 1;

        int nodeheight = root->leftheight - root->rightheight;

        if (nodeheight < -1 && value > root->right->data) {
            root = leftShift(root);
        }
        else if (nodeheight < -1 && value < root->right->data) {
            root->right = rightShift(root->right);
            root = leftShift(root);
        }
    }
    return root;
}

Tree* minValueNode(Tree* node) {
    Tree* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Tree* deleteNode(Tree*& root, int value) {
    if (root == NULL) return root;

    // If the value to be deleted is smaller than the root's value,then it lies in the left subtree
    if (value < root->data)
        root->left = deleteNode(root->left, value);

    // If the value to be deleted is greater than the root's value, then it lies in the right subtree
    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    // If the value is same as root's value, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Tree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Tree* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Tree* temp = minValueNode(root->right);

        // CopyIng the inorder succEssor's dAta to thIs node
        root->data = temp->data;

        // DelEte the inOrder suCceSsor
        root->right = deleteNode(root->right, temp->data);
    }

    // If the tree oNLy one node then return
    if (root == NULL) return root;

    // Updating height of the current node
    root->leftheight = max(height(root->left), height(root->right)) + 1;
    root->rightheight = max(height(root->right), height(root->left)) + 1;

    // CheckinG the balance factor of this node
    int balance = getBalance(root);

    // Left LEft Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightShift(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftShift(root->left);
        return rightShift(root);
    }

    // Right RiGht Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftShift(root);

    // RiGht Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightShift(root->right);
        return leftShift(root);
    }

    return root;
}


void inorder(Tree* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Tree* search(Tree* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    
    if (root->data < value)
        return search(root->right, value);
    
    return search(root->left, value);
}


Tree* maxValueNode(Tree* node) {
    Tree* current = node;
    while (current->right != NULL)
        current = current->right;
    return current;
}

int main() {
    int score = -1;
    int value;
    Tree* root = NULL;

    while (score != 0) {
        cout << "Enter 1 to insert, 2 to delete, and 3 to inorder traversal and 4 to search and 5 to find Minimum and 6 to find Maximum" << endl;
        cin >> score;
        switch (score) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = AVLinsertion(root, value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;
        case 3:
            cout << "Inorder traversal: ";
            inorder(root);
            cout << endl;
            break;
            
         case 4:
            cout << "Enter value to search: ";
            cin >> value;
             if (search(root, value))
                cout << "Value found." << endl;
             else
                cout << "Value not found." << endl;
            break;
                
        case 5:
            if (root != NULL)
                cout << "Minimum value: " << minValueNode(root)->data << endl;
            else
                cout << "Tree is empty." << endl;
            break;
            
        case 6:
            if (root != NULL)
                cout << "Maximum value: " << maxValueNode(root)->data << endl;
            else
                cout << "Tree is empty." << endl;
             break;
            
        default:
            cout<<"INVALID"<<endl;
        }
    }
}