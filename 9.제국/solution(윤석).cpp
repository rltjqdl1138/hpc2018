#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n, m;
map<string, string> par;
map<string, bool> check;
string find(const string &x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void merge(const string &pu, const string &pv) { // u가 이김
	par[pv] = pu;
	check[pv] = false;
}

void merge_in(const string &u, const string &v) { // u가 종주국
	par[u] = v;
	par[v] = v;
	check[u] = false;
	check[v] = true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	string s;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		par[s] = s;
		check[s] = true;
	}

	string u, v;
	int w;
	for (int i = 0; i < m; i++) {
		getline(cin, s);
		int a = s.find(",");
		int b = s.find(",", a + 1);
		int w = s.back() - '0';
		u = s.substr(0, a);
		v = s.substr(a + 1, b - a - 1);

		string pu = find(u);
		string pv = find(v);

		if (w == 1) {
			if (pu != pv) {
				merge(pu, pv);
			}
			else if (pu == v) { // 종주국이 패배 (v가 종주국)
				merge_in(v, u);
			}
		}
		else if (w == 2) {
			if (pu != pv) {
				merge(pv, pu);
			}
			else if (pv == u) { // 종주국이 패배 (u가 종주국)
				merge_in(u, v);
			}
		}
	}

	int cnt = 0;
	for (auto x : check) {
		if (x.second) cnt++;
	}
	cout << cnt << '\n';
	for (auto x : check) {
		if (x.second) cout << x.first << '\n';
	}
}