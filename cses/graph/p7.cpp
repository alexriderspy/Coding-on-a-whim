//matrix bfs - two times bfs run, clean code!

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

#define pii pair<int,int>

int n,m;
const int nm = 1005;
int oo = INT32_MAX;
int paths[nm][nm];
pii from[nm][nm];
queue<pii>q;
pii A;
bool mora=false,possible= false;

string ans="";

void retrace(pii loc){
    pii prev = from[loc.first][loc.second];
    if(prev==pii(-1,-1)){
        return;
    }
    if(prev.first+1 == loc.first) ans+="D";
    if(prev.first-1 == loc.first) ans+="U";
    if(prev.second+1 == loc.second) ans+="R";
    if(prev.second-1 == loc.second) ans+="L";

    retrace(prev);
}

void check(pii loc,pii nex){
    int pl = paths[loc.first][loc.second];
    if(pl+1 < paths[nex.first][nex.second]){
        paths[nex.first][nex.second] = pl+1;
        q.push(nex);
        from[nex.first][nex.second]=loc;
    }
}
//mora is false when monster bfs else true
void bfs(){
    while(!q.empty()){
        pii loc = q.front(),nex;
        q.pop();
        nex = loc; nex.first++; check(loc,nex);
        nex = loc; nex.second++; check(loc,nex);
        nex = loc; nex.first--; check(loc,nex);
        nex = loc; nex.second--; check(loc,nex);

        if(mora && (loc.first == 0 || loc.first == n-1 || loc.second == 0 || loc.second == m-1)){
            cout<<"YES\n";
            cout<<paths[loc.first][loc.second]<<'\n';
            retrace(loc);
            possible = true;
            return;
        }
    }
}
int main(){
    cin>>n>>m;

    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        for(int j=0;j<m;++j){
            paths[i][j]=oo;
            if(s[j]=='#') paths[i][j]=0;
            else if(s[j] == 'M') {
                q.push({i,j}); //monsters
                paths[i][j]=0;
            }else if(s[j]=='A'){
                A = {i,j};
            }
        }
    }
    bfs();
    from[A.first][A.second]=pii(-1,-1);
    paths[A.first][A.second]=0;
    q.push(A);
    mora = true;
    bfs();
    if(possible == true){
        reverse(ans.begin(),ans.end());
        cout<<ans<<'\n';
    }else{
        cout<<"NO\n";
    }
}