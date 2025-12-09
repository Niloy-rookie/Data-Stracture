#include<bits/stdc++.h>
using namespace std;

//creating node structure
class Node {
    public:
    char data;
    Node* left;
    Node* right;
    Node(char data) {
        this->data = data;
        this->right = this->left = NULL;
    }
};

//function to build prefix

int precedence(char op){
    if(op == '+' || op == '-'){
        return 1;
    }
    else if(op == '*' || op == '/'){
        return 2;
    }
    else if(op == '^'){
        return 3;
    }
    return 0;
}
//maintaining openning and closing brackets

bool match(char a,char b){
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

string buildPrefix(string infix) {
    stack<char> st;
    string prefix;
    reverse(infix.begin(),infix.end());//reverse the infix expression(rules for prefix)
    for(int i = 0;i < infix.length();i++){
        if(infix[i] == '('){
            infix[i] = ')';
        }
        else if(infix[i] == ')'){
            infix[i] = '(';
        }
        else if(infix[i] == '['){
            infix[i] = ']';
        }
        else if(infix[i] == ']'){
            infix[i] = '[';
        }
        else if(infix[i] == '{'){
            infix[i] = '}';
        }
        else if(infix[i] == '}'){
            infix[i] = '{';
        }
   }

   for(char ch : infix){
        if(isalpha(ch) || isdigit(ch)){
            prefix += ch;
        }
        else if(ch == '(' || ch =='{' || ch =='['){
            st.push(ch);
        }
        else if(ch == ')' || ch =='}' || ch ==']'){
            while(!st.empty() && !match(st.top(),ch)){
                prefix += st.top();
                st.pop();
            }
            st.pop(); //pop the opening bracket
        }
        else{
            while(!st.empty() && precedence(st.top()) >= precedence(ch)){
                prefix += st.top();
                st.pop();
            }
            st.push(ch);
        }
   }
   while(!st.empty()){
        prefix += st.top();
        st.pop();
   }
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

//build tree from prefix expression
int i = 0;
bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' ||c == '/' || c == '^');
}
Node* build(string prefix) {
    
        if(i >= prefix.size()){
            return NULL;
        }
        char ch = prefix[i];
        i++;
        Node* node = new Node(ch);

        if(isOperator(ch)) {
            node->left = build(prefix);
            node->right = build(prefix);
        }

        return node;
}
void preOrder(Node* root) {
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void display(Node* root,int space = 0,int gap = 5) {
    if(root == NULL){
        return;
    }
    space += gap;
    display(root->right,space);
    cout << endl;
    for(int i = gap; i <= space;i++) {
        if(i == space){
            cout << root->data << endl;
        }
        cout << " ";
    }
    display(root->left,space);
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin,infix);
    string prefix = buildPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    Node* root = build(prefix);
    cout << "Preorder traversal of the expression tree: ";
    preOrder(root);
    cout << endl;
    cout << "Display expression tree: " << endl;
    display(root);
    return 0;
}