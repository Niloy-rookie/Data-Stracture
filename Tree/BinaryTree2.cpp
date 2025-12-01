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
};

int main(){
    Tree tree;
    tree.populate();
    cout << "The binary tree is:" << endl;
    tree.display();
    return 0;
}