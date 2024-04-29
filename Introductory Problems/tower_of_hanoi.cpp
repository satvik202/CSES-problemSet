#include <bits/stdc++.h>
using namespace std;

void solve(int n, int src, int dest, int aux){
    if(n==0) return;
    solve(n-1, src, aux,dest);
    cout<<src<<" "<<dest<<"\n";
    solve(n-1,aux,dest , src);
}

int main(){
    int n; cin>>n;
    cout<<pow(2, n)-1<<endl;
    solve(n, 1, 3, 2);
    return 0;
}