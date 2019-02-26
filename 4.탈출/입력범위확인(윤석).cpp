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
int dist[100000];
queue<int> q;
int main() {
	memset(dist, -1, sizeof(dist));
	cin >> n >> t >> g;
    if(n< 0 || n >99999 || t < 1 || t >99999 || g <0 || g >99999)
        assert(false);
	dist[n] = 0;
	q.push(n);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		if (x == g) break;
		if (dist[x] >= t) continue;

		int a = pusha(x);
		int b = pushb(x);
		//if (a < 0 || b < 0 || a >= 100000 || b >= 100000) assert(false);
		if (0 <= a && a < 100000 && dist[a] == -1) {
			q.push(a);
			dist[a] = dist[x] + 1;
		}

		if (0 <= b && b < 100000 && dist[b] == -1) {
			q.push(b);
			dist[b] = dist[x] + 1;
		}
	}
	if (dist[g] == -1 || dist[g] > t) cout << "ANG";
	else cout << dist[g];
}