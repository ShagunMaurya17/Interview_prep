#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int index =0;index<n;index++){
        cin>>arr[index];
    }
    vector<int> prefix_sum(n,0);
    prefix_sum[0]=arr[0];
    for(int index = 1;index<n;index++){
        prefix_sum[index]=prefix_sum[index-1]+arr[index];
    }
    int testc;
    cin>>testc;
    while(testc--){
        int begin,end;
        cin >> begin >> end;
        if(begin == 0){
            cout<<prefix_sum[end]<<"\n";
        }
        else{
            cout<< prefix_sum[end]-prefix_sum[begin-1]<<"\n";
        }
        
    }
    return 0;
}

// stdin                   // stdout
3                               4
1 4 1                           5
3                               6
1 1
1 2 
0 2
