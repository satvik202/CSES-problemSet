#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&coins, int sum, int n, vector<int>&dp){
    if(sum==0){
        return 0;
    }
    if(dp[sum]!=-1) return dp[sum];
    int res = 1e9;
    for(int ind=0; ind<n; ind++){
        if(coins[ind]<=sum){
            res = min(res, 1 + solve(coins, sum - coins[ind], n, dp));
        }
    }
    return dp[sum]= res;
}

int main(){
    int n, sum;
    cin>>n>>sum;
    vector<int>coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];
    vector<int>dp(sum+1, -1);
    int ans = solve(coins,sum, n, dp);
    cout<<(ans==1e9 ? -1 : ans)<<endl;
    return 0;
}