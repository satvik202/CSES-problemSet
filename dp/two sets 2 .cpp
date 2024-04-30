#include <bits/stdc++.h>
using namespace std;
using ll =  long long;

const int mod = 1e9 +7;

// classic pick or not pick
// smilar to knapsack problem
// dp[i][x] = number of ways to make sum x using subsets of the numbers 1..i .
//            (not pick)    (pick)
// dp[i][x] = dp[i-1][x] + dp[i-1][x-i].


int main(){
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    if(sum%2==1){
        cout<<0<<endl;
        return 0;
    }
    ll target = sum/2;
  vector<vector<int>> dp(n,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      (dp[i][j]+= j-i>=0 ? dp[i-1][j-i] : 0 )%=mod;
     
    }
  }
  cout << dp[n-1][target] << endl;
    
    return 0;
}