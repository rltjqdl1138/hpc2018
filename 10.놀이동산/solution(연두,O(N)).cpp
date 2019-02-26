#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, A, B, dp[10010], pos[10010];
ll sum[10010];


// S~E번째 사람이 한 곳으로 모이는 거리의 합
inline int cal(int S, int E){
	ll ret = 0;
	int mid = (S+E)/2;
	ret += sum[E] - sum[mid];
	ret -= sum[mid-1] - sum[S-1];
	if((E-S+1)%2 == 0) ret -= pos[mid];
	return ret;
}


//here~N-1번 사람이 놀이동산에 도착하는 총 비용
int solve(int here){
	if(here == n+1) return 0;
	int &ret = dp[here];
	if(ret != -1) return ret;
	
	//혼자 택시를 타는 경우
	ret = pos[here] * A + solve(here+1);
	//i번째 사람까지 같이 버스를 타는 경우
	int E = min(n, here + 39);
	for(int i=here; i<=E; ++i)
		ret = min(ret, cal(here, i)*A + B + solve(i+1));
    return ret;
}

int main(){
	cin >> n >> A >> B;
	for(int i=1; i<=n; ++i)
		cin >> pos[i];
	sort(pos+1, pos+n+1);
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + pos[i];
	memset(dp, -1, sizeof(dp));
	cout << solve(1);
}