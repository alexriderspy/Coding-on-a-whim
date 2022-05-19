#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;cin>>n;
    while(n--){
        cin>>x;
        int c=0;
        for(int j=1;j*j<=x;++j){
            if(x%j == 0){
                c+=2;
                if(j*j==x){
                    --c;
                }
            }
        }
        cout<<c<<'\n';
    }
}