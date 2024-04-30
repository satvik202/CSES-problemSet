#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>nums(n), dp(n,1);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    // time complexity O(n²)
    // this method will give you a TLE

    // for(int i=1; i<n; i++){
    //     for(int j=0; j<i; j++){
    //         if(nums[i]>nums[j] && dp[j]+1 > dp[i]){
    //             dp[i]= dp[j]+1;
    //         }
    //     }
    // }

    // cout<<*max_element(begin(dp), end(dp))<<endl;
    // now we'll be using binary search 

    vector<int>lis;
    lis.push_back(nums[0]);

    for(int i=1; i<n; i++){
        if(nums[i] > lis.back()){
            lis.push_back(nums[i]);
        }
        else{
            // i need to place this value to it's rightful place 
            auto it = lower_bound(begin(lis), end(lis), nums[i]);
            *it = nums[i];
        }
    }



    cout<<lis.size()<<endl;
}