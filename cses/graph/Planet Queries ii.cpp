/*
functional graphs are those that have a cycle at its core and all are trees that lead up to it
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,q;cin>>n>>q;
	vector<int>next(n);
	vector<vector<int>>before(n);
	for(int i=0;i<n;++i){
		cin>>next[i];
		next[i]--;
		before[next[i]].push_back(i);
	}
	vector<int>cycle_id(n,-2);
	//-2 for not processed, -1 if in tree, else id(>=0) of the cycle it is a part of
	vector<map<int,int>>cycles;
	//this map contains the id of the cycle that the tree has at its core

	for(int i=0;i<n;++i){
		if(cycle_id[i]!=-2) continue;

		int at=i;
		vector<int>path{i};
		while(cycle_id[next[at]]==-2){
			at=next[at];
			path.push_back(at);
			cycle_id[at]=-3;
		}
		map<int,int>cycle;
		bool in_cycle=false;
		int f=0;
		for(int i:path){
			if(next[at]==i){
				in_cycle=true;
			}
			if(in_cycle){
				f=1;
				cycle[i]=cycle.size();
			}
			cycle_id[i]=in_cycle?cycles.size():-1;
		}
		if(f==1)cycles.push_back(cycle);
	}

	vector<int>cyc_dist(n);
	for(int i=0;i<n;++i){
		if(cycle_id[next[i]]==-1 || cycle_id[i]>=0){
			continue;
		}
		cyc_dist[i]=1;
		vector<int>stack(before[i]);
		while(!stack.empty()){
			int c=stack.back();
			stack.pop_back();
			cyc_dist[c]=cyc_dist[next[c]]+1;
			stack.insert(stack.end(),before[c].begin(),before[c].end());
		}
	}

	int log2=ceil(std::log2(n));
	vector<vector<int>>down(log2+1,vector<int>(n));

	for(int i=0;i<n;++i){
		down[0][i]=next[i];
	}
	for(int i=1;i<=log2;++i){
		for(int j=0;j<n;++j){
			down[i][j]= down[i-1][down[i-1][j]];
		}
	}
	auto advance = [&](int pos,int dist){
		for(int i=0;i<=log2;++i){
			if(dist&(1<<i)){
				pos=down[i][pos];
			}
		}
		return pos;
	};


	while(q--){
		int a,b;cin>>a>>b;
		--a,--b;
		if(cycle_id[down[log2][a]]!=cycle_id[down[log2][b]]){
			cout<<-1<<'\n';
			continue;
		}
		if(cycle_id[a]!=-1 || cycle_id[b]!=-1){
			if(cycle_id[b]==-1){
				cout<<-1<<'\n'; continue;
			}
			int dist=cyc_dist[a];
			int u_cyc = advance(a,dist);
			map<int,int>&mp = cycles[cycle_id[u_cyc]];
			int u_index = mp[u_cyc];
			int v_index = mp[b];

			if(u_index<=v_index){
				cout<<v_index-u_index + dist<<'\n';
			}else{
				cout<<mp.size()-(u_index-v_index) + dist<<'\n';
			}

		}else{
			if(cyc_dist[a]<cyc_dist[b]){
				cout<<-1<<'\n';
			}else{
				int diff = cyc_dist[a]-cyc_dist[b];
				if(advance(a,diff) == b){
					cout<<diff<<'\n';
				}else{
					cout<<-1<<'\n';
				}
			}
		}
	}
}