#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
const int LOG = 18;

int up[LOG][N];

int main(){
    int a,n,q;cin>>n>>q;
    
    for(int i=2;i<=n;++i){
        cin>>a;
        up[0][i]=(a);
    }
    for(int i=1;i<LOG;++i){
        for(int j=1;j<=n;++j){
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }
    while(q--){
        int x,k;
        cin>>x>>k;
        int val=(x);
        for(int i=0;i<LOG;++i){
            if(k&(1<<i)){
                val=up[i][val];
            }
        }
        if(val==0){
            cout<<-1<<'\n';
        }else cout<<val<<'\n';
    }
}