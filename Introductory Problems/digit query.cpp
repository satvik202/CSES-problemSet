#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 


/*
     1,2,3....9  ==> 9 digits (1 to 9)  -> 1 digit numbers |||  10 -1
     10, 11, 12, 13,.... 99 ==> 90 number => 180 digits -> 2 digit numbers ||| 100 -10

*/


vector<ll> ccc(19,1);
void solve(){

    ll index; cin>>index;

    ll digit_till_now =0;
    ll digit_before_req_block=0;

    ll digit_in_req_no;

    for(int i=1; i<=18; i++){
        digit_till_now+= (ccc[i] - ccc[i-1])*i;

        if(digit_till_now>=index){
            digit_in_req_no = i;
            break;
        }

        digit_before_req_block+= (ccc[i] - ccc[i-1])*i;
    }

    //now we know the number of digits our number can have, it's lower bound and upper bound

    // [1,10,100,1000] 
    // if the number is 2 digit 
    // then range -> {10 , 99}  ===> arr[digit in req no - 1] to arr[digit in req no] - 1

    ll low = ccc[digit_in_req_no-1];
    ll high = ccc[digit_in_req_no] - 1;
    ll num=0;
    ll starting_pos_of_num =0;
    while(low<=high){
        ll mid = (high + low)/2;

        ll pos_of_mid= digit_before_req_block+1 + (mid - ccc[digit_in_req_no-1])*digit_in_req_no;

        if(pos_of_mid<=index){
            if(mid > num){
                num = mid;
                starting_pos_of_num = pos_of_mid;
            }
            low = mid+1;
        }else{
            high = mid-1;
        }

    }

    string number = to_string(num);


    cout<<number[index - starting_pos_of_num]<<endl;
 
}
int main()
{
 fast_cin();


 for(int i=1; i<=18; i++){
    ccc[i] = ccc[i-1]*10;
 }

 ll t;
 cin >> t;
 while(t--) {
solve();
 }
 return 0;
}