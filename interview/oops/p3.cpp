#include<bits/stdc++.h>
using namespace std;

int main(){
    string A  = "892795";
    int n = A.size();
    for(int i=n-1;i>=1;--i){
        if(A[i]>A[i-1]){
            
            sort(A.begin()+i,A.end());
            cout<<A<<'\n';
            int x = A[i-1]-'0';
            cout<<x<<'\n';
            cout<<i<<'\n';
            int index = lower_bound(A.begin()+i,A.end(),x+1)-(A.begin()+i);
            cout<<index<<'\n';
            swap(A[i-1],A[index+i]);
            sort(A.begin()+i,A.end());
            cout<<A<<'\n';break;
        }
    }
    A="59";
    int index = lower_bound(A.begin(),A.end(),9)-(A.begin());
    cout<<index<<'\n';

}