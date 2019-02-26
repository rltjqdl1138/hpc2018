#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> edge;
const int MAX = 1000;

int n, dist[MAX][MAX];
vector<edge> E;

/*
스패닝 트리의 간선을 이용한 그래프를 만들어 (adj)
유니온 파인드 대신 DFS로 사이클이 있는제 확인
*/

vector<int> adj[MAX];
bool visit[MAX];
void DFS(int a){
	visit[a] = 1;
	for(int &b : adj[a])
		if(!visit[b])
			DFS(b);
}
bool isCycle(int u, int v){
	memset(visit, 0, sizeof(visit));
	DFS(u);
	if(visit[v]) return 0;
	adj[u].push_back(v);
	adj[v].push_back(u);
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

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
	for(int i=0; cnt<n-1; ++i)
		if(isCycle(get<1>(E[i]), get<2>(E[i]))){
			ans += get<0>(E[i]);
			++cnt;
		}
	cout << ans;
}