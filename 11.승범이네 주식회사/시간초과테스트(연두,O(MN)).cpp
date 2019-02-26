#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;

vector<int> child[MAX];
int n,m,parent[MAX],money[MAX];

void DFS(int here, int w){
	money[here] += w;
	for(int i : child[here])
		DFS(i,w);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> parent[1];
	for(int i=2; i<=n; ++i){
		cin >> parent[i];
		child[parent[i]].push_back(i);
	}
	while(m--){
		int a,b,c;
		cin >> a;
		if(a == 1){
			cin >> b >> c;
			DFS(b,c);
		}
		else{
			cin >> b;
			cout << money[b] << '\n';
		}
	}
}