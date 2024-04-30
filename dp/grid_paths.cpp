#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n;


// target -> n-1 , n-1

int solve(vector<string>&grid, int i, int j, vector<vector<long long>>&dp){
    if(i>=n or j>=n or grid[i][j]=='*') return 0;
    if(i==n-1 && j==n-1 && grid[i][j]=='.') return 1;
    if(dp[i][j]!= -1) return dp[i][j];
    long long a = solve(grid, i+1, j, dp)%mod; // down
    long long b= solve(grid, i, j+1, dp)%mod; // right

    return dp[i][j]= (a + b)%mod;
    
}

int main(){
    cin>>n;
    vector<string>grid(n);
    for(int i=0; i<n; i++){
        cin>>grid[i];
    }
    if(grid[n-1][n-1]=='*'){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<long long>>dp(n+1, vector<long long>(n+1,-1));
    cout<<solve(grid, 0, 0, dp);
}