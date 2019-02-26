#include<bits/stdc++.h>
using namespace std;

int n, A, B, pos[10010], dp[10010];

inline int cal(int S, int E){
	int pivot = (S+E)/2, ret = 0;
	for(int i=S; i<=E; ++i)
		ret += abs(pos[pivot] - pos[i]);
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
	memset(dp, -1, sizeof(dp));
	cout << solve(1);
}