#include <bits/stdc++.h>
using namespace std;

set<string>ans;

void solve(string s, int n, string t, vector<bool>&picked){
    if(t.size()==n){
        ans.insert(t);
        return;
    }

    for(int i=0; i<n; i++){
        if(!picked[i]){
            t+=s[i];
            picked[i]=true;
            solve(s, n, t, picked);
            picked[i]=false;
            t.pop_back();
        }
    }
}

void print(auto &arr){
    for(auto &it : arr){
        cout<<it<<"\n";
    }
    cout<<endl;
}


int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<bool>picked(n,false);
    solve(s, n, "", picked);
    cout<<ans.size()<<endl;
    print(ans);

    return 0;
}