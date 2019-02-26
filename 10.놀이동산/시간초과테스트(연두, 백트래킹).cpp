#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, A, B, dp[10010], pos[10010];
ll sum[10010];
ll ans;

// S~E번째 사람이 한 곳으로 모이는 거리의 합
inline int cal(int S, int E){
	int ret=0, mid = (S+E)/2;
	ret += sum[E] - sum[mid];
	ret -= sum[mid-1] - sum[S-1];
	if((E-S+1)%2 == 0) ret -= pos[mid];
	return ret;
}

void bt(int here, long long ret){
	if(ret >= ans) return;
	if(here == n+1){
		ans = min(ans, ret);
		return;
	}
	bt(here+1, ret + pos[here] * A);
	int E = min(n, here + 39);
	for(int i=here; i<=E; ++i)
		bt(i+1, ret + cal(here, i)*A + B);
}

int main(){
	cin >> n >> A >> B;
	for(int i=1; i<=n; ++i)
		cin >> pos[i];
	sort(pos+1, pos+n+1);
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + pos[i];
	ans = sum[n] * min(A,B);
	bt(1, 0);
	cout << ans;
}