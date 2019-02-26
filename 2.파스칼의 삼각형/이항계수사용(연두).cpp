#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define xx first
#define yy second

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, r;
	cin >> n >> r;
	--n, --r;
	r = min(r, n-r);
    
	ll ans = 1;
	for(int i=n; i>=n-r+1; --i)
		ans *= i;
	for(int i=r; i; --i)
		ans /= i;
	cout << ans;
}