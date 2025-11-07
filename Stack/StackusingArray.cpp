#include<iostream>
using namespace std;

class Stack{
    int data[10];
public:
    int top = -1;

    void push(int value) {
        top++;
        data[top] = value;
    }
    int pop() {
        int i = top;
        top--;
        return data[i];
    }
    int First() {
        if(top == -1){
            cout<<"Empty"<<endl;
            return -1;
        }
        return data[top];
    }
    void print() {
        int temp = top;
        while(temp != -1){
            cout << data[temp] << "->";
            temp--;
        }
        cout << "End" << endl;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.print();
    cout<< s.pop() << endl;
    cout << s.First() << endl;
    s.print();
}