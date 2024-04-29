#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n= s.size();
    vector<int>freq(26, 0);
    for(int i=0; i<n; i++){
        freq[s[i]-'A']++;
    }
    
    // if n is odd then there must only be one odd occ
    // otherwise there can not be any odd occ
    int odd=0, ind=-1;
    for(int i=0; i<26; i++){
        if(freq[i]%2){
            odd++;
            ind=i;
        }
    }

    if(n%2 && odd!=1){
        cout<<"NO SOLUTION";
        return 0;
    }
    if(n%2==0 && odd !=0){
        cout<<"NO SOLUTION";
        return 0;
    }
    string ans ="";
    if(odd==1 && n%2){
        ans = string(freq[ind], 'A' + ind);
    }

    for(int i=0; i<26; i++){
        if(freq[i]==0 or i==ind) continue;
        ans += string(freq[i]/2, 'A'+i);
        ans = string(freq[i]/2, 'A'+i) + ans;
    }
    
    cout<<ans;


    return 0;
}