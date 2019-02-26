#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 500LL * 10000 * 10000 + 100;
int C, E, D, n;
ll dist[1010], price[1010], dp[1010][510];

/*
현재 pos번째 지점에 있고 has만큼 기름이 있을 때 최소 금액
1. 현재 지점에서 기름을 꽉 채우거나,
2. 특정 지점에서 도달 가능할 만큼만 기름을 채우거나,
3. 기름을 채우지 않거나,
셋 중 한가지 중 반드시 최적이 있다.
*/

ll solve(int pos, int has){
	if(pos == n+1) return 0;
	auto &ret = dp[pos][has];
	if(ret != -1) return ret;

	ret = INF;

	//기름을 꽉 채워도 다음 지점으로 갈 수 없다.
	if(E*(dist[pos+1]-dist[pos]) > C) return ret;

	//기름을 꽉 채우고 다음 지점으로 간다.
	ret = min(ret, price[pos] * (C - has) + solve(pos+1, C - E*(dist[pos+1]-dist[pos])));
	
	//i번째 지점까지 간다
	for(int i=pos+1; i<=n+1; ++i){
		//기름을 아무리 채워도 한번에 갈 수 없는 경우
		int need = E*(dist[i] - dist[pos]);
		if(need > C) break;

		//기름이 충분하면 채우지 않고 그냥 간다
		if(need <= has)
			ret = min(ret, solve(i, has - need));
		//need까지 기름을 채운다
		else
			ret = min(ret, (need - has)*price[pos] + solve(i, 0));
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> C >> E >> D >> n;
	//dist[i] = 0에서 i번째 주유소까지의 거리
	//dist[0] = 시작점, dist[n+1] = 도착점
    if(n==0){
        cout << (D * E <= C ? 0 : -1);
        return 0;
    }
	for(int i=1, a, sum=0; i<=n; ++i){
		cin >> a;
		sum += a;
		dist[i] = sum;
	}
	dist[n+1] = D;

	for(int i=1; i<=n; ++i)
		cin >> price[i];
	price[0] = 123456;

	memset(dp, -1, sizeof(dp));
	ll ans = solve(0, C);
	cout << (ans >= INF ? -1 : ans);

}