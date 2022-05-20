#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
    string n;cin>>n;
    if(n.size()>=3){
        int mini=9;
        for(int i=0;i<n.size();++i){
            mini=min(mini,n[i]-'0');
        }
        cout<<mini<<'\n';
    }else{
        cout<<n[1]<<'\n';
    }
    }
}