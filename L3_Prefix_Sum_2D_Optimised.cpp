// Optimised prefix sum 2D O(N^2)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int row,col;
    cin>> row >> col;
    vector<vector<int>> arr(row,vector<int>(col,0));
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            cin>> arr[i][j];
        }
    }
    vector<vector<int>> prefix_arr(row,vector<int> (col,0));
    prefix_arr[0][0] = arr[0][0];
    for(int i =1;i< row;i++){
        prefix_arr[i][0] = prefix_arr[i-1][0]+ arr[i][0];
    }
    for(int i =1 ;i<row;i++){
        prefix_arr[0][i] = prefix_arr[0][i-1]+arr[0][i];
    }
    for(int i =1;i<col;i++){
        for(int j= 1;j<col;j++){
            prefix_arr[i][j] = prefix_arr[i-1][j]+prefix_arr[i][j-1]-prefix_arr[i-1][j-1]+arr[i][j];
        }
    }
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            cout << prefix_arr[i][j]<< " ";
        }
        cout<<endl;
    }
    
    return 0;
}

// stdin     // stdout
3 3          1 3 6
1 2 3        3 11 21
2 6 7        6 18 33
3 4 5
