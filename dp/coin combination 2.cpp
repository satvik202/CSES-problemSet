#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(vector<int>&coins, int ind, int k, vector<vector<long long>>&dp){
    if(ind==0){
        return k%coins[0]==0;
    }
    if(dp[ind][k]!=-1) return dp[ind][k];
    // not pick
    int notPick = solve(coins, ind-1, k, dp);
    // pick
    int pick =0;
    if(coins[ind]<=k) pick = solve(coins, ind, k-coins[ind], dp);

    return dp[ind][k] = (pick + notPick)%mod;
}
int main(){
 
    long long n, K; cin>>n>>K;
 
    vector<int>coins(n);
    for(int i=0; i<n; i++) cin>> coins[i];
    vector<long long>prev(K+1, 0), curr(K+1, 0);

    for(int i=0; i<=K; i++){
        prev[i] = i%coins[0]==0;
    }

    for(int ind= 1; ind<n; ind++){
        for(int k= 0; k<=K; k++){
            int notPick = prev[k];;
            int pick =0;
            if(coins[ind]<=k) pick = curr[k-coins[ind]];

            curr[k] = (pick + notPick)%mod;
        }

        prev = curr;
    }
    cout<<prev[K]<<endl;
}