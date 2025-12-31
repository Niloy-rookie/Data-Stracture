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

    //Added DFS
    void DFS() {
        vector<bool> visited(size,false);
        for(int i = 1;i < size;i++){
            if(!visited[i]){
                DFShelper(i, visited);
            }
        }
        cout << endl;
    }
    void DFShelper(int src,vector<bool>&visited) {
        cout << src << " ";
        visited[src] = true;

        for(int it:l[src]){
            if(!visited[it]){
                DFShelper(it,visited);
            }
        }
    }

    //undirected graph cycle exist
    bool isCyclicUndrGraph(int src,int parent,vector<bool>&visited) {
        visited[src] = true;
        list<int>neighbor = l[src];//to check immidiate neigbors are visited and are not equal to parent

        for(int it:neighbor){
            if(!visited[it]){
                isCyclicUndrGraph(it,src,visited);
            }
            else if(it != parent){
                return true;
            }
        }
        return false;
    }
    bool isCyclic() {
        vector<bool>visited (size,false);

        //incase graph has multiple indibidual graph or cycle
        for(int i = 1;i < size;i++){
            if(!visited[i]){
                if(isCyclicUndrGraph(i,-1,visited)){
                    return true;
                }
            }
        }
        return false;
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
    cout << "BFS: ";
    g.BFS();

    cout << "DFS: ";
    g.DFS();
    
    if(g.isCyclic()){
        cout << "Graph is cyclic"<< endl;
    }
    else{
        cout << "Graph isnt cyclic" << endl;
    }
    return 0;
}