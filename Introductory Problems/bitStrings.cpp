#include <bits/stdc++.h>
using namespace std;


#define MOD 1000000007

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main(){
    int n; cin>>n;
    cout<<power(2, n)<<endl;
    return 0;
}