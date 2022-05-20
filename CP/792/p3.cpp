#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    int a=-1,b=-1;
    bool possible=true;
    vector<vector<int>>grid(n,vector<int>(m));
    vector<int>row1(m),row2(m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>row1[j];
            row2[j]=row1[j];
            grid[i][j]=row1[j];
        }

        if(possible==false) continue;

        sort(row2.begin(),row2.end());
        int cnt=0;

        for(int j=0;j<m;++j){
            if(row2[j]!=row1[j] && cnt>=2){
                possible=false;break;
            }

            if(row2[j]!=row1[j] && cnt==0){
                a=j;
                cnt++;continue;
            }
            if(row2[j]!=row1[j] && cnt==1){
                b=j;
                cnt++;
                continue;
            }

        }
    }
    if(possible==false){
        cout<<-1<<'\n';
    }else{
        if(a==-1 && b==-1){
            cout<<1<<' '<<1<<'\n';return;
        }
        vector<int>row1(m),row2(m);
        for(int i=0;i<n;++i){
            row1=grid[i];
            row2=grid[i];
            sort(row2.begin(),row2.end());
            int cnt=0;
            for(int j=0;j<m;++j){

                if(row2[j]!=row1[j] && cnt==0){
                    if(a!=j){
                        cout<<-1<<'\n';return;
                    }
                    cnt++;continue;
                }
                if(row2[j]!=row1[j] && cnt==1){
                    if(b!=j){
                        cout<<-1<<'\n';return;
                    }
                    cnt++;
                    continue;
                }
                

            }
            if(row1[a]==row2[b]){
                continue;
            }
            if(cnt!=2){
                cout<<-1<<'\n';return;
            }
        }
        cout<<a+1<<' '<<b+1<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}