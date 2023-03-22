// optimised using sum of a section in 2d array using prefix sum O(N^2)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int row,col;
    cin >> row >> col;
    vector<vector<int>> arr(row,vector<int>(col,0));
    for(int i = 0;i<row;i++){
        for(int j =0;j<col;j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> pre_arr(row, vector<int>(col,0));
    pre_arr[0][0] = arr[0][0];
    for(int i = 1;i<row;i++){
        pre_arr[i][0] = pre_arr[i-1][0]+arr[i][0];
    }
    for(int j = 1;j<col;j++){
        pre_arr[0][j]= pre_arr[0][j-1]+arr[0][j];
    }
    for(int i =1;i<row;i++){
        for(int j =1;j<col;j++){
            pre_arr[i][j] = pre_arr[i-1][j]+pre_arr[i][j-1] - pre_arr[i-1][j-1] + arr[i][j];
        }
    }
    int start_row,start_col,end_row,end_col;
    cin >> start_row >> start_col >> end_row >> end_col;
    
    if(start_row == 0 && start_col == 0){
        cout<< pre_arr[end_row][end_col]<<"\n";
    }
    else if( start_row == 0){
        cout<< pre_arr[end_row][end_col] - pre_arr[end_row][start_col-1] << "\n";
    }
    else if( start_col == 0){
        cout<< pre_arr[end_row][end_col] - pre_arr[start_row-1][end_col] << "\n";
    }
    else{
        cout<< pre_arr[end_row][end_col] - pre_arr[start_row-1][end_col] - pre_arr[end_row][start_col-1] + pre_arr[start_row-1][start_col-1];
    }
    
    
    return 0;
}

// stdin    // Stdout
3 3            4
1 2 3
2 1 1
1 1 1
1 1 2 2
