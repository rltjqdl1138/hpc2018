#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define xx first
#define yy second

int n, m, parent[500];
string name[500];

int find(int x){
	if(parent[x]<0) return x;
	return parent[x] = find(parent[x]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin.ignore();
	for(int i=0; i<n; ++i)
		getline(cin, name[i]);
	sort(name, name+n);

	memset(parent, -1, sizeof(parent));
	while(m--){
		string input;
		getline(cin, input);
		int pos1 = input.find(',');
		int pos2 = input.find(',', pos1+1);

		string s1 = input.substr(0, pos1);
		string s2 = input.substr(pos1+1, pos2-pos1-1);
		
		int u = lower_bound(name, name+n, s1) - name;
		int v = lower_bound(name, name+n, s2) - name;
		if(input.back() == '2') swap(u,v);

		//종주국 vs 해당 종주국 속국
		if(find(u) == find(v)){
			parent[u] = -1;
			parent[v] = u;
		}

		else{
			u = find(u), v = find(v);
			parent[v] = u;
		}
	}

	int ans = 0;
	for(int i=0; i<n; ++i)
		ans += (parent[i]<0);
	cout << ans << '\n';
	for(int i=0; i<n; ++i)
		if(parent[i] < 0)
			cout << name[i] << '\n';
}
