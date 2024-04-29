#include <bits/stdc++.h>
using namespace std;

const int mod = int(1e9)+7;
long long dp[int(1e6)+1];
int main(){
    int n, x; cin>>n>>x;
    vector<int>coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];
    dp[0]=1;
    for(int wt=0; wt<=x; wt++){
        for(int i=0; i<n; i++){
            if(coins[i]<=wt){
                dp[wt] += (dp[wt-coins[i]]);
                dp[wt]%=mod;
            }
        }
    }

    cout<<dp[x]<<'\n';
}