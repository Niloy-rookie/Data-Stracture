#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* previous;

    Node(int value) {
        this->value = value;
        this->next = NULL;
        this->previous = NULL;
    }
};

class DLL {
    Node* head;
    Node* tail;

public:
    DLL(){
        head = tail = NULL;
    }
    int size = 0;
    void push_front(int value) {
        Node* node = new Node(value);
        if(head == NULL){
            head = tail = node;
            size++;
            return;
        }
        node->next = head;
        head->previous = node;
        head = node;
        size++;
    }
    void push_last(int value) {
        Node* node = new Node(value);
        node->previous = tail;
        tail->next = node;
        tail = node;
        size++;
    }
    void push(int value,int index) {
        if(head == NULL){
            push_front(value);
            return;
        }
        Node*temp = head;
        Node* node = new Node(value);
        for(int i = 0;i < index-1;i++){
            temp = temp->next;
        }
        if(temp == tail){
            push_last(value);
            return;
        }
        node->next = temp->next;//connection node to the adress of temp holding means next node of temp
        node->previous = temp;//connection:node to temp
        temp->next->previous = node;//connection:the node after newly node to newlynode
        temp->next = node;//connection:node before newlynode to newlynode
        size++;
    }
    int pop_back (){
        if(head->next == NULL){
            return pop_first();
        }
        Node* temp = tail;
        int val = temp->value;
        tail = tail->previous;
        tail->next = NULL;
        delete temp;
        size--;
        return val;
    }
    int pop_first(){
        if(head->next == NULL){
            int val = head->value;
            delete head;
            head = tail = NULL;
            size--;
            return val;
        }
        Node* temp = head;
        int val = temp->value;
        head = head->next;
        delete temp;
        size--;
        return val;

    }
    void print() {
        Node* temp = head;
        while(temp != NULL){
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "End" << endl;
    }
    void printrev() {
        Node* temp = tail;
        while(temp != NULL){
            cout << temp->value << "->";
            temp = temp->previous;
        }
        cout << "end" << endl;
    }
};

int main(){
    DLL dl;
    dl.push_front(1);
    dl.push_front(2);
    dl.push_front(3);
    dl.push_front(4);
    dl.printrev();
    dl.push(10,2);
    dl.print();
    dl.pop_first();
    dl.pop_back();
    dl.print();
}