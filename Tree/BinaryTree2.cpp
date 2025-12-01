#include<bits/stdc++.h>
using namespace std;

//creating node structure
class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        this->left = this->right = NULL;
    }
};
//create binary tree
class Tree {
private:
    Node* root = NULL;

public:
    void populate() {
        cout << "Enter the root node: ";
        int val;
        cin >> val;
        root = new Node(val);
        populate(root);
    }

private:
    void populate(Node* root) {
        cout << "Do you want to add left child of " << root->value << "?";
        bool left;
        cin >> left;
        
        if(left){
            cout << "Enter the left child of " << root->value << ":";
            int leftval;
            cin >> leftval;
            Node* leftnode = new Node(leftval);
            root->left = leftnode;
            populate(leftnode);
        }

        cout << "Do you want to add right child of " << root->value << "?";
        bool right;
        cin >> right;

        if(right){
            cout << "Enter the right child of " << root->value << ":";
            int rightval;
            cin >> rightval;
            Node* rightnode = new Node(rightval);
            root->right = rightnode;
            populate(rightnode);
        }
    }

public:

    void display() {
        display(root,0);
    }

private:

    void display(Node* node, int level){
        if(node == NULL){
            return;
        }
        display(node->right, level+1);
        if(level != 0){
            for(int i = 0;i < level-1; i++){
                cout << "|\t";
            }
            cout << "|-------" << node->value << endl;
        }
        else{
            cout << node->value << endl;
        }
        display(node->left, level+1);
    }

    //create height(max length from root to leafnode)every node is at height 1
public:

    int height() {
        return height(root);
    }

private:

    int height(Node* node){
        if(node == NULL){
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight)+1;
    }

public:
    int nodeCount() {
        return nodeCount(root);
    }
private:
    int nodeCount(Node* node) {
        if(node == NULL){
            return 0;
        }
        int leftNode = nodeCount(node->left);
        int rightNode = nodeCount(node->right);
        return leftNode + rightNode + 1;
    }
public:
    int sum() {
        return sum(root);
    }
private:
    int sum(Node* node) {
        if(node == NULL){
            return 0;
        }
        int leftSum = sum(node->left);
        int rightSum = sum(node->right);
        return leftSum + rightSum + node->value;
    }
};

int main(){

    Tree tree;
    tree.populate();
    cout << "The binary tree is:" << endl;
    tree.display();
    cout << endl;
    cout << "Node Count: " << tree.nodeCount() <<  endl;
    cout << "HEight: " << tree.height() << endl;
    cout<< "Sum of nodes: " << tree.sum() << endl;
    return 0;

}