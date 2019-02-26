#include <iostream>
#include <algorithm>
#include <vector>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

struct Edge {
	int from, to;
	ll cost;
	Edge(int f = 0, int t = 0, ll c = 0) :from(f), to(t), cost(c) {}
};
vector<Edge> p;
int n;
int par[1001];
int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}
void merge(int u, int v) {
	par[u] = par[v];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
	ll x;
	for (int i = 1; i < n + 1; i++) {
		par[i] = i;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> x;
			if (i >= j) continue;
			p.emplace_back(i, j, x);
		}
	}
	sort(all(p), [&](const Edge &a, const Edge &b) {
		return a.cost < b.cost;
	});
	ll ans = 0;
	for (auto e : p) {
		int u = e.to, v = e.from;
		ll c = e.cost;
		u = find(u);
		v = find(v);
		if (u != v) {
			merge(u, v);
			ans += c;
		}
	}
	cout << ans;
}