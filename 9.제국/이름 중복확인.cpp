#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n, m;
int par[1001];
bool check[1001];
string name[1001];
map<string, int> number;

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void merge(int px, int py) { // x가 이김
	par[py] = px;
	check[py] = false;
}

void merge_in(int x, int y) { // u가 종주국
	par[x] = y;
	par[y] = y;
	check[x] = false;
	check[y] = true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	string s;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		name[i] = s;
		number[s] = i;

		par[i] = i;
		check[i] = true;
	}
    
    for(int i=0; i<n ;i++){
for(int j=i+1; j<n ;j++){
if(name[i] == name[j]) assert(false);}}
    
	string u, v;
	int w;
	for (int i = 0; i < m; i++) {
		getline(cin, s);
		int a = s.find(",");
		int b = s.find(",", a + 1);
		int w = s.back() - '0';
		u = s.substr(0, a);
		v = s.substr(a + 1, b - a - 1);

		int x = number[u];
		int y = number[v];
		int px = find(x);
		int py = find(y);

		if (w == 1) {
			if (px != py) {
				merge(px, py);
			}
			else if (px == y) { // 종주국이 패배 (y가 종주국)
				merge_in(y, x);
			}
		}
		else if (w == 2) {
			if (px != py) {
				merge(py, px);
			}
			else if (py == x) { // 종주국이 패배 (x가 종주국)
				merge_in(x, y);
			}
		}
	}
	vector<string> ans;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (check[i]) {
			cnt++;
			ans.push_back(name[i]);
		}
	}
	cout << cnt << '\n';
	sort(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i << '\n';
	}
}