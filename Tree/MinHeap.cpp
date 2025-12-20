#include<bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    int* arr;
    int capacity;
    int size;

    int parent(int i) {
        return (i-1)/2;
    }
    int left_child(int i) {
    	return (2*i)+1;
    }
    int right_child(int i){
    	return (2*i)+2;
    }
    
public:
    MinHeap(int cap) {
    	capacity = cap;
    	size = 0;
    	arr = new int[cap];
    }
    
    void insert(int val) {
        if(size == capacity){
            return;
        }
        int i = size;
        arr[i] = val;
        size++;
        
        while(i != 0 && arr[parent(i)] > arr[i]){
            swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
    }
    void display() {
        cout << "Heap: ";
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getMin() {
        return arr[0];
    }

    int DeleteMin() {
        if(size == 0){
            return -1;
        }
        if(size == 1){
            return arr[--size];
        }
        int root = arr[0];
        arr[0] = arr[size-1];
        size--;

        heapify(0);
        return root;
   }
   void heapify(int i) {
        int smallest = i;
        int left = left_child(i);
        int right = right_child(i);
        
        if(left < size && arr[left] < arr[smallest]){
            smallest = left;
        }
        if(right < size && arr[right] < arr[smallest]){
            smallest = right;
        }
        if(smallest != i){
            swap(arr[i],arr[smallest]);
            heapify(smallest);
        }
   }
};

int main() {
    MinHeap h(10);

    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);

    h.display();

    h.DeleteMin();
    h.display();
    h.insert(1);
    h.display();
    return 0;
}