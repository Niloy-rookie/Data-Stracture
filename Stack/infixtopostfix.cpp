#include<bits/stdc++.h>
using namespace std;
stack<char>st;
string postfix;

int precedence(char op) {
    if(op == '^'){
        return 3;
    }
    if(op == '*' || op == '/'){
        return 2;
    }
    if(op == '+' || op == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

void infixtopostfix(string infix) {
    for(char symbol : infix){
        switch(symbol) {
            case '(':
                st.push(symbol);
                break;
            
            case ')':
                while(!st.empty() && st.top() != '('){
                    postfix += st.top();
                    st.pop();
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!st.empty() && precedence(st.top()) >=precedence(symbol)){
                    postfix += st.top();
                    st.pop();
                }
                st.push(symbol);
                break;

            default:
            if(!isspace(symbol))
                postfix += symbol;
                break;
        }
    }
    while(!st.empty()){
        if(st.top() == '('){
            st.pop();
            continue;
        }
        postfix += st.top();
        st.pop();
    }
    cout << "Postfix: ";

    for(char s : postfix){
        cout << s;
    }
    cout << endl;
}

int main(){
    string infix;
    cout << "Enter infix:"<< endl;
    getline(cin , infix);

    infixtopostfix(infix);
    return 0;
}