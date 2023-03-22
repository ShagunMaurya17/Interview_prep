// brute force prefix sum 2d O(N^4) 

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
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            int sum = 0;
            for(int k = 0;k<=i;k++){
                for(int l = 0;l<=j;l++){
                    sum+=arr[k][l];
                }
            }
            prefix_arr[i][j] = sum;
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
// stdin   //stdout
3 3        1 3 6
1 2 3      3 8 15
2 3 4      6 15 27
3 4 5
