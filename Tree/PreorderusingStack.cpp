#include<bits/stdc++.h>
using namespace std;

//creating node 
class Node {
public:
    string value;
    Node* left;
    Node* right;
    Node(string val) {
        this->value = val;
        this->right = this->left = NULL;
    }
};

Node* buildTree(vector<string> &nodes,int &index) {
    if(index >= nodes.size() || nodes[index] == "-1"){
        index++;
        return NULL;
    }
    Node* root = new Node(nodes[index]);
    index++;
    root->left = buildTree(nodes,index);
    root->right = buildTree(nodes,index);
    return root;
}

void preorderUsingStack(Node* root) {
    if(root == NULL){
        return;
    }
    stack<Node*> st;
    while(!st.empty() || root != NULL){
        while(root != NULL){
            cout << root->value<< " ";
            if(root->right != NULL){
                st.push(root->right);
            }
            root = root->left;
        }
        if(!st.empty()){
            root = st.top();
            st.pop();
        }
    }
}

void display(Node *node, int level){
    if (node == NULL){
        return;
    }
    display(node->right, level + 1);
    if (level != 0){
        for (int i = 0; i < level - 1; i++){
            cout << "|\t";
        }

        cout << "|-------" << node->value << endl;
    }
    else{
        cout << node->value << endl;
    }

    display(node->left, level + 1);
}

int main() {
    vector<string> nodes;
    string val;
    getline(cin,val);
    stringstream ss(val);
    string token;
    while(ss >> token){
        nodes.push_back(token);
    }

    int index = 0;
    Node* root = buildTree(nodes,index);
    preorderUsingStack(root);
    cout << endl << "The binary tree is:" << endl;
    display(root,0);
    return 0;
}