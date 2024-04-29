#include <bits/stdc++.h>
using namespace std;
vector<string> solve(int n){
    if(n==1){
        return {"0", "1"};
    }
    auto a = solve(n-1);
    auto b= a;
    reverse(begin(b), end(b));
    for(int i=0; i<a.size(); i++){
        a[i] = '0'+a[i];
    }
    for(int i=0; i<b.size(); i++){
        b[i] = '1' + b[i];
    }
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

void print(auto &arr){
    for(auto &it : arr){
        cout<<it<<"\n";
    }
    cout<<endl;
}

int main(){
    int n; cin>>n;
    //string s = string(n, '0');
    vector<string> ans = solve(n);
    print(ans);
    return 0;
}