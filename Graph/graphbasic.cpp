#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int size;
    list<int> *l;//dynamically alloted

public:
    Graph(int v) {
        this->size = v+1;
        l = new list<int> [size];
    }
    // for delete and free up space in heap
    ~Graph() {
        delete[] l;
    }
    //undirected graph TC-O(2E)
    void addNodes(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print(){
        for(int i = 0;i < size;i++){
            cout<< i <<": ";
            for(int neigh:l[i]){
                cout << neigh;
            }
            cout << endl;
        }
    }
    
    //BFS Traversal
    void BFS() {
        queue<int> q;
        vector<bool> visited(size,false);
        q.push(2);//putting source node into queue;
        visited[2] = true;

        //outer loop for checking immidiate neighbour
        while(!q.empty()){
            int src = q.front();
            q.pop();
            cout<< src << " ";
            //inner loop for visited node
            for(int it : l[src]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        cout << endl;
    }
};

int main(){
    Graph g(5);//0...4
    g.addNodes(1,2);
    g.addNodes(2,3);
    g.addNodes(2,4);
    g.addNodes(3,4);
    g.addNodes(4,5);

    //g.print();
    g.BFS();
}