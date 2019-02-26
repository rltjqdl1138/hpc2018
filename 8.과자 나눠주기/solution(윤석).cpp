#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


vector<ll> p;
int n, m;
ll cal(ll x) {
	ll res = 0;
	for (int i = 0; i < n; i++) res += p[i] / x;
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;
	ll x;
	ll l = 1, r = -0x3f3f3f3f;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (r < x) r = x;
		p.push_back(x);
	}
	ll mid = 0;
	ll ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		ll res = cal(mid);
		if (res >= m) {
			l = mid + 1;
			ans = max(ans, mid);
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
}