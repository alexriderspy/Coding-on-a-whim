#include<bits/stdc++.h>
using namespace std;

#define int long long

int query2(int a,int b){
    int x;
    cout<<"? "<<2<<" "<<a<<" "<<b<<endl;
    cin>>x;
    return x;
}

char query1(int a){
    char x;
    cout<<"? "<<1<<" "<<a<<endl;
    cin>>x;
    return x;
}
void solve(){
    int p,x=1,y,n;cin>>n;
    vector<char>s(n,'.');
    vector<int>lst(26,-1);
    s[0]=query1(1);
    lst[s[0]-'a']=1;
    for(int i=2;i<=n;++i){
        y=query2(1,i);
        if(y!=x){
            s[i-1]=query1(i);
            lst[s[i-1]-'a']=i;
            ++x;
            continue;
        }
        vector<pair<int,char>>lsts;
        for(int i=0;i<26;++i){
            if(lst[i]!=-1){
                lsts.push_back({lst[i],'a'+i});
            }
        }
        sort(lsts.begin(),lsts.end());
        int low = 0, high = (int)lsts.size()-1;
        while(low < high){
            int mid = (low + high + 1)/2;
            int v = query2(lsts[mid].first,i);
            if(v==(int)lsts.size()-mid){
                low = mid;
            }else{
                high = mid-1;
            }
        }
        s[i-1]=lsts[low].second;
        lst[s[i-1]-'a']=i;
    }
    cout<<"! ";
    for(int i=0;i<n;++i) cout<<s[i];
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin>>t;
    solve();
}