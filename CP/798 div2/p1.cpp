#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,m,k;cin>>n>>m>>k;
    string a,b;cin>>a>>b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    string c="";
    int cnt=0,i=0,j=0;
    char l;
    while(i<n && j<m){
        if(cnt==k) {
            if(l=='i') l='j';
            else l='i';
            cnt=1;
        }else{
            if(a[i]<b[j]){
                if(l=='i'){
                    cnt++;
                }else{
                    cnt=1;
                    l='i';    
                }
            }else{
                if(l=='j'){
                    cnt++;
                }else{
                    cnt=1;
                    l='j';    
                }

            }
        }
        if(l=='i') c+=a[i],++i;
        else c+=b[j],++j;
        
    }
    cout<<c<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}