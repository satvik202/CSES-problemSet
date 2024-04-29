#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int solve(vector<string>&grid, int i, int j){
    if(i>=n or i<0 or j>=n or j<0) return 0;
    if(i==n-1 && j==n-1 && grid[i][j]=='.') return 1;

    
    
}

int main(){
    cin>>n;
    vector<string>grid(n);
    for(int i=0; i<n; i++){
        cin>>grid[i];
    }


    cout<<solve(grid, 0, 0);
}