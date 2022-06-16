#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;cin>>n>>k;
    vector<int>p(k);
    for(int i=0;i<k;++i) cin>>p[i];
    sort(p.begin(),p.end());
    string s="";
    s+="W";
    for(int i=1;i<n;++i){
        int f=0;
        for(int j=0;j<k;++j){
            if((i-p[j])>=0){
                if(s[i-p[j]]=='L'){
                    s+="W";
                    f=1;
                    break;
                }
            }else if(i==p[j]-1){
                s+="W";
                f=1;break;
            }else{
                break;
            }
        }
        if(!f){
            s+="L";
        }
        
    }
    cout<<s<<'\n';
}