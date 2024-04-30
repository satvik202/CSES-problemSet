#include <bits/stdc++.h>
using namespace std;
int n, money;

int solve(vector<int>&cost, vector<int>&pages, int ind, int target, vector<vector<int>>&dp){
    if(ind==n){
        return 0;
    }
    if(target==0) return 0;
    if(dp[ind][target]!= -1) return dp[ind][target];
    // pick
    int a =0;
    if(cost[ind]<=target) a = pages[ind] + solve(cost, pages, ind +1 , target - cost[ind],dp);
    // not pick
    int b = solve(cost, pages, ind+1, target, dp);

    return dp[ind][target] = max(a, b);
}

int main(){
    cin>>n>>money;
    vector<int>cost(n), pages(n);

    for(int i=0; i<n; i++) cin>>cost[i];
    for(int i=0; i<n; i++) cin>>pages[i];
    vector<vector<int>>dp(n+1, vector<int>(money+1, 0));
    // cout<<solve(cost, pages, 0, money, dp);

    for(int ind = n-1; ind>=0; ind--){
        for(int target =0; target<=money; target++){
            int a =0;
            if(cost[ind]<=target) a = pages[ind] + dp[ind+1][target - cost[ind]];
            // not pick
            int b = dp[ind+1][target];

            dp[ind][target] = max(a, b);
        }
    }

    cout<<dp[0][money];

    return 0;
}