#include<bits/stdc++.h>

using namespace std;

const int inf=1e7;
int main(){
    int n,tmp;
    cin>>n;
    tmp=n;
    set<int>nums;
    
    vector<int>steps(n+1,inf);
    steps[n]=0;
    //need steps[0]
    for(int i=n;i>=0;i--){
        tmp=i;
        while(tmp){
            nums.insert(tmp%10);
            tmp/=10;
        }
        
        for(auto num:nums){
            if(i-num>=0)
            steps[i-num]=min(steps[i]+1,steps[i-num]);
            
        }
        nums.clear();
    }
   // for(int i=0;i<steps.size();i++) cout<<steps[i]<<'\n';
    cout<<steps[0]<<'\n';

}