#include <bits/stdc++.h>
using namespace std;


void print(vector<int>&arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n; cin>>n;
    long long sum = n*1ll*(n+1)/2;
    if(sum%2){
        cout<<"NO";
        return 0;
    }
    vector<int>v1;
    vector<int>v2;
    vector<int>vis(n+1, 0);

    long long s =0;
    int j= n;
    while(s<sum/2){
        if(s+j<=sum/2) s+= j, vis[j]=1;
        j--;
    }

    for(int i=1; i<=n; i++){
        if(vis[i]){
            v1.emplace_back(i);
        }else v2.emplace_back(i);
    }
    

    cout<<"YES\n";
    cout<<v1.size()<<"\n";
    print(v1, v1.size());
    cout<<v2.size()<<"\n";
    print(v2, v2.size());
    

    return 0;
}