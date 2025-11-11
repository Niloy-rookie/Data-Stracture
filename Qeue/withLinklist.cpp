#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};
class Qeue {
Node* front;
Node* rear;
public:
    Qeue() {
        front = rear = NULL;
    }
    void push(int value) {
        Node* node = new Node(value);
        if(front == NULL){
            front = rear = node;
            return;
        }
        rear->next = node;
        rear = node;
    }
    int pop() {
        Node* del = front;
        int val = front->value;
        if(front->next == NULL){
            front = rear = NULL;
            delete del;
            return val;
        }
        front = front->next;
        delete del;
        return val;
    }
    int top() {
        if(front == NULL){
            cout<< "empty" << endl;
        }
        return front->value;
    }
    void print() {
        Node* temp = front;
        while(temp != NULL){
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    Qeue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.print();
    q.pop();
    q.print();
    q.top();
}