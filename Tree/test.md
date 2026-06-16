#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

// check if operator
bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

// build tree from prefix
Node* buildFromPrefix(string &prefix, int &i) {
    if (i >= prefix.size()) return NULL;

    char c = prefix[i];
    i++; // move to next char

    Node* root = new Node(c);

    if (isOperator(c)) {
        root->left = buildFromPrefix(prefix, i);
        root->right = buildFromPrefix(prefix, i);
    }

    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    string prefix = "*+a-bc/-de+fgh";
    int index = 0;

    Node* root = buildFromPrefix(prefix, index);

    cout << "Preorder again: ";
    preorder(root);
}
