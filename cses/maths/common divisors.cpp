#include<cmath>
#include<iostream>

using namespace std;

const int MAX_VAL = 1e6;
int divisors[MAX_VAL + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a;cin>>n;

    for(int i=0;i<n;++i){
        cin>>a;
        int sqr = (int)sqrt(a);
        for(int j=1;j<=sqr;++j){
            if(a%j==0){
                divisors[j]++;
                
                if(j!=a/j){
                    divisors[a/j]++;
                }
            }
        }
    }
    for(int i=MAX_VAL;i>=1;--i){
        if(divisors[i]>=2){
            
            cout<<i<<endl;
            break;
        }
    }
    
}