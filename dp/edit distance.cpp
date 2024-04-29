#include <bits/stdc++.h>
using namespace std;

int n,m;

int solve(string &a, string &b, int i, int j, vector<vector<int>>&dp){
    if(i==n){
        return m-j;
    }

    if(j==m) return n-i;

    if(dp[i][j]!=-1) return dp[i][j];

    if(a[i]==b[j]){
        return solve(a, b, i+1, j+1, dp);
    }

    // not equal
    // 3 options ---> remove / replace / insert

    int x = solve(a,b, i+1,j,dp);// remove
    int y= solve(a,b, i, j+1, dp); // insert
    int z= solve(a,b, i+1, j+1, dp); // replace

    return dp[i][j]= min(x, min(y,z)) + 1;
}

int main(){
    string a,b;
    cin>>a>>b;
    n= a.size(), m= b.size();

    vector<vector<int>>dp(n+1, vector<int>(m+1,-1));

    cout<<solve(a,b, 0,0, dp)<<endl;
}