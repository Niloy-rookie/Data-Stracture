#include<bits/stdc++.h>
using namespace std;

//creating node structure
class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int Value) {
        this->left = this->right = NULL;
        this->value = Value;
    }
};

//create binary search tree
class BST {
private:
    Node* root = NULL;
public:
    Node* insert(Node* root,int value) {
        if(root == NULL){
            return new Node(value);
        }
        if(value < root->value){
            root->left = insert(root->left,value);
        }
        else{
            root->right = insert(root->right,value);
        }
        return root;
    }



public:
    Node* populate(vector<int>& arr) {
        for(int i:arr){
            root = insert(root,i);
        }
        return root;
    }

public:
    bool isBalanced() {
        int heightDiff = check(root);

        if(heightDiff == -1){
            cout << "The tree is not balanced." << endl;
            return false;
        }
        else{
            cout << "The tree is balanced." << endl;
            return true;
        }
    }
private:
    int check(Node* node) {
        if(node == NULL) {
            return 0;
        }
        int left = check(node->left);
        if(left == -1){
            return -1;
        }
        int right = check(node->right);
         if(right == -1){
            return -1;
        }
        if(abs(left - right) > 1){
            return -1;
        }
        return max(left,right) + 1;
    }

public:
    bool search(int key) {
        if(search(root,key)){
            cout << "Element found in the tree." << endl;
            return true;
        }
        else{
            cout << "Element not found in the tree." << endl;
            return false;
        }
    }
private:
    bool search(Node* node,int key) {
        if(node == NULL){
            return false;
        }
        if(node->value == key){
            return true;
        }
        if(key < node->value){
            return search(node->left,key);
        }
        else{
            return search(node->right,key);
        }
    }

private:
    Node* getInorderSuccessor(Node* node) {
        Node* temp = node;
        while(temp && temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }

public:
    Node* deleteNode(int key) {
        return deleteNode(root,key);
    }
private:
    Node* deleteNode(Node* node,int key) {
        if(node == NULL){
            return NULL;
        }
        if(key < node->value){
            node->left = deleteNode(node->left,key);
        }
        else if(key > node->value){
            node->right = deleteNode(node->right,key);
        }
        else{
            //node with only one child or no child
            if(node->left == NULL){
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right ==NULL){
                Node* temp = node->left;
                delete node;
                return temp;
            }
            //node with two children: get the inorder successor (smallest in the right subtree)
            else{
                Node* IS = getInorderSuccessor(node->right);
                node->value = IS->value;
                node->right = deleteNode(node->right,IS->value);
            }
        }
        return node;
    }

public:
    void display(){
        display(root,0);
    }
private:
    void display(Node* node,int level) {
        if(node == NULL){
            return;
        }
        display(node->right,level+1);
        if(level != 0){
            for(int i = 0;i < level-1;i++){
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

int main() {
    BST tree;
    vector<int> arr;
    int val;
    string line;

    cout<< "Enter elements:"<< endl;
    getline(cin,line);
    stringstream ss(line); // break the string into word by word or number by number
    while(ss >> val){
        arr.push_back(val);
    }
    tree.populate(arr);
    cout << "The binary search tree is:" << endl;

    tree.display();

    tree.isBalanced();

    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;
    tree.search(key);

    cout << "Enter the element to be deleted: ";
    cin >> key;
    tree.deleteNode(key);
    cout << "The binary search tree after deletion is:" << endl;
    tree.display();
    return 0;

}