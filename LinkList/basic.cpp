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

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_first(int value) {
        Node* node = new Node(value);//dynamic allocated memory:can use later or in another function(* by creating pointer)
        if(head == NULL){
            head = tail = node;
            return;
        }
        else{
            node->next = head;
            head = node;
        }
    }

    void push_last(int value) {
        if(tail == NULL){
            push_first(value);
            return;
        }//empty list
        Node* node = new Node(value);
        tail->next = node;
        tail = node;
    }

    void insert_data(int value,int pos) {
        if(pos < 0){
            cout << "Invalid position" << endl;
            return;
        }
        if(pos == 0){
            push_first(value);
            return;
        }
        Node* temp;
        temp = head;
        for(int i = 1;i < pos-1;i++){
            temp = temp->next;
        }
        Node* node = new Node(value);
        node->next = temp->next;
        temp->next = node;
    }

    int pop_front() {
        if(head == NULL){
            cout << "LinkList is empty"<<endl;
            return -1;
        }
        Node* temp = head;
        int val = head->value;
        head = head->next;
        delete temp;
        if(head == NULL){
            tail = NULL;
        }
        return val;
    }

    int pop_back() {
        if(head == NULL){
            cout << "Error" << endl;
            return -1;
        }
        if(head->next == NULL){
            return pop_front();
        }
        else{
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            int val = tail->value;
            temp->next = NULL;
            delete tail;
            temp = tail;
            return val;
        }

    }
    
    int search(int data) {
        Node* temp = head;
        int index = 0;
        while(temp->next != NULL){
            if(temp->value == data){
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }
    void print() {
        Node* temp;
        temp = head;

        while(temp != NULL){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout<<"End"<<endl;
    }
};

int main(){
    List l;
    l.push_first(1);
    l.push_first(2);
    l.push_first(3);
    l.push_first(4);
    l.push_last(0);
    l.insert_data(10,3);
    l.print();
    cout << l.pop_front() << endl;
    l.print();
    cout << l.pop_back()<<endl;
    l.print();
    cout << l.search(2) << endl;
}