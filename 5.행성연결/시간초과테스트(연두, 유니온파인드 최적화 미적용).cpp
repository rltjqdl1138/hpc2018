#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> edge;
const int MAX = 1000;

int n, parent[MAX], dist[MAX][MAX];
vector<edge> E;

int find(int a){
	if(parent[a]<0) return a;
	return find(parent[a]);
}
bool merge(int a, int b){
	a = find(a), b = find(b);
	if(a==b) return 0;
	parent[a] = b;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(parent, -1, sizeof(parent));

	cin >> n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j){
			cin >> dist[i][j];
			if(i < j)
				E.emplace_back(make_tuple(dist[i][j],i,j));
		}
	sort(E.begin(), E.end());
	ll ans = 0;
	int cnt = 0;
	for(int i=0; cnt < n - 1; ++i)
		if(merge(get<1>(E[i]), get<2>(E[i]))){
			ans += get<0>(E[i]);
			++cnt;
		}
	cout << ans;
}