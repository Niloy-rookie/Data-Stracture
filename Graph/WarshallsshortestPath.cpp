#include<bits/stdc++.h>
using namespace std;

class WarshallsAlgorithm {
private:
    int row,col;

public:
    vector<vector<int>> input() {
        cout<< "Enter row and coloum: ";
        cin >> row >> col;

        vector<vector<int>> arr(row,vector<int>(col));

        cout << "Enter matrix: " << endl;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                cin >> arr[i][j];
            }
        }
        return arr;
    }

    vector<vector<int>> Algorithm(vector<vector<int>> & arr) {
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(arr[i][j] == -1){
                    arr[i][j] = 1e9;
                }
            }
        }
        
        //key algo
        for(int k = 0;k < row;k++){
            for(int i = 0;i < row;i++){
                for(int j = 0;j < col;j++){
                    arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
                }
            }
        }

        //make it actual
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(arr[i][j] == 1e9){
                    arr[i][j] = -1;
                }
            }
        }
        return arr;
    }

    void display(vector<vector<int>>& arr){
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                cout << arr[i][j]<< " ";
            }
            cout << endl;
        }
    }
};

int main(){
    WarshallsAlgorithm w;
    vector<vector<int>>arr = w.input();
    arr = w.Algorithm(arr);
    cout << "Shortest path: "<< endl;
    w.display(arr);
}