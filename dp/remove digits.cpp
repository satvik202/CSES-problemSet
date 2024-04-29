#include <bits/stdc++.h>
using namespace std;


int dp[int(1e6) + 1];

int solve(int n){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int x=n;
    int ans = 1e9;

    // since n is upto 10^6 
    // this while loop will run for at max 6 times
    int i=0;
    while(x){
        int dig = x%10;
        int a = 1e9;
        if(dig!=0) a = 1 + solve(n - dig);
        x/=10;
        i++;
        ans = min(ans, a);
    }
    return dp[n] =  ans;
}


int main(){
    int n; cin>>n;
    memset(dp, -1, sizeof(dp));
    cout<<solve(n);
    // cout<<n;
    return 0;
}