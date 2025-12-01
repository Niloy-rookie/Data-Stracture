#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
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

static int idx = -1;//global variable for index 

Node* buildTree(vector<int> preorder) {//in return we will get root node

    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);//recursive function for left subtree

    root->right = buildTree(preorder);//recursive function for right subtree

    return root;
}
//trevarsal function
class Tree {
public:
    void preorder(Node* root) {
        if(root == NULL){
            return;
        }
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(Node* root) {
        if(root == NULL){
            return;
        }
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
    void postorder(Node* root) {
        if(root == NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
    void levelorder(Node* root) {
        queue<Node*> q;

        q.push(root);
        q.push(NULL);//level marker

        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            if(current == NULL){
                if(!q.empty()){
                    q.push(NULL);
                    cout << endl;
                    continue;
                }
                else{
                    break;
                }
            }

            cout<<current->value<<" ";

            if(current->left != NULL){
                q.push(current->left);
            }
            if(current->right != NULL){
                q.push(current->right);
            }
        
        }
        cout << endl;
    }
};

int main(){
    vector<int>preorder = {1,2,-1, -1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    Tree tree;
    cout<<"Preorder Traversal: ";
    tree.preorder(root);
    cout<<endl;
    cout<<"Inorder Traversal: ";
    tree.inorder(root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    tree.postorder(root);
    cout<<endl;
    cout<<"Levelorder Traversal: "<<endl;
    tree.levelorder(root);
    return 0;
}