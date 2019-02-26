#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <assert.h>
using namespace std;

int pusha(int x) {
	return x + 1;
}
int pushb(int x) {
	x *= 2;
	if (x >= 100000) return -1;
	int i = 1;
	for (; x - i >= 0; i *= 10);
	i /= 10;
	return x - i;
}
int n, t, g;

int ans = 1234567;

void bt(int now, int cnt){
	if(now > g) return;
	if(now == g){
		ans = min(ans, cnt);
		return;
	}
	if(cnt == t) return;

	int b = pushb(now);
	if(b > now)
		bt(pushb(now), cnt+1);
	bt(pusha(now), cnt+1);
}

int main() {
	cin >> n >> t >> g;
	bt(n, 0);
	if(ans > t) cout << "ANG";
	else cout << ans;
}