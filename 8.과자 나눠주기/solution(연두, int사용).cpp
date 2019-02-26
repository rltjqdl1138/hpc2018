#include<bits/stdc++.h>
using namespace std;
int n, m, len[10000000];

bool can(int x){
	if(x==0) return 1;
	int cnt = 0;
	for(int i=0; i<m; ++i)
		cnt += len[i] / x;
	return cnt >= n;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int lo = 0, hi = 1000000001;
	for(int i=0; i<m; ++i)
		cin >> len[i];
	
	while(lo +1 != hi){
		int mid = (lo+hi)/2;
		if(can(mid)) lo = mid;
		else hi = mid;
	}
    assert(lo!=1000000000);
	cout << lo;
}