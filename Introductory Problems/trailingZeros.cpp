#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int res=0;
    for(int i=5; i<=n; i+=5){
        int x=0;
        int j=i;
        while(j%5==0){
            j/=5;
            x++;
        }

        res+=x;
    }
    cout<<res;
    return 0;
}