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

class CircularLinklist {
    Node* head;
    Node* tail;
public:
    CircularLinklist() {
        head = tail = NULL;
    }

    void insert_first(int value) {
        Node* node = new Node(value);
        if(head == NULL){//empty list
            head = tail = node;
            tail->next = node;        }
        else{
            node->next = head;
            head = node;
            tail->next = node;
        }
    }
    void insert_last(int value) {
        Node* node = new Node(value);
        if(head == NULL){
            return insert_first(value);
        }
        else{
            tail->next = node;
            tail = node;
            tail->next = head;
        }
    }
    int Delete(int value){
        Node* temp = head;
        if(head == NULL){
            return -1;
        }
        if(head == tail){
            int val = head->value;
            delete head;
            head = tail = NULL;
            return val;
        }
        do{
            if(head->value == value){
                int val = head->value;
                head = head->next;
                tail->next = head;
                delete temp;
                return val;
            }
            if(temp->next->value == value){
                Node* del = temp->next;
                int val = del->value;
                if(del == tail){
                    tail = temp;
                }
                temp->next = del->next;
                delete del;
                return val;
            }
            temp = temp->next;

        }   while(temp != head);
        return -1;
    }

    void print() {
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do{
            cout << temp->value << "->";
            temp = temp->next;
        }while(temp != head);
        cout<< head->value<<endl;
    }
};
int main(){
    CircularLinklist cl;
    cl.insert_first(1);
    cl.insert_first(2);
    cl.insert_first(3);
    cl.insert_first(4);
    cl.insert_first(5);
    cl.insert_first(6);
    cl.insert_first(7);
    cl.insert_first(8);
    cl.insert_last(0);
    cl.print();
    cl.Delete(0);
    cl.print();
}