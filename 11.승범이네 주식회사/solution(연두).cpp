#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
vector<int> adj[MAX];
int cnt, child[MAX], S[MAX], E[MAX];
int make_tree(int here){
	int &ret = child[here] = 1;
	for(int there : adj[here])
		ret += make_tree(there);
	E[here] = cnt++;
	S[here] = E[here] - ret + 1;
	return ret;
}

long long seg[MAX*4], lazy[MAX*4];
void update_lazy(int node, int nodeL, int nodeR){
	if(lazy[node] != 0){
		seg[node] += (nodeR - nodeL +1)*lazy[node];
		if(nodeL != nodeR){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int l, int r, long long value, int node, int nodeL, int nodeR){
	update_lazy(node, nodeL, nodeR);
	if(r<nodeL || nodeR<l) return;
	if(l <= nodeL && nodeR <= r){
		seg[node] += (nodeR - nodeL +1)*value;
		if(nodeL != nodeR){
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}
		return;
	}
	int mid = (nodeL+nodeR)/2;
	update(l,r,value,node*2,nodeL,mid);
	update(l,r,value,node*2+1,mid+1,nodeR);
	seg[node] = seg[node*2] + seg[node*2+1];
}
long long query(int l, int r, int node, int nodeL, int nodeR){
	update_lazy(node, nodeL, nodeR);
	if(r<nodeL || nodeR<l) return 0;
	if(l <= nodeL && nodeR <= r) return seg[node];
	long long mid = (nodeL + nodeR)/2;
	return query(l,r,node*2,nodeL,mid) + query(l,r,node*2+1,mid+1,nodeR);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b, c;
	cin >> n >> m >> a;
	for(int i=2; i<=n; ++i){
		cin >> a;
		adj[a].push_back(i);
	}
	make_tree(1);
	while(m--){
		cin >> a;
		if(a == 1){
			cin >> b >> c;
			update(S[b], E[b], c, 1, 0, n-1);
		}
		else{
			cin >> b;
			cout << query(E[b], E[b], 1, 0, n-1) << '\n';
		}
	}
}