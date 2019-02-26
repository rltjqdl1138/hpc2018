#include <iostream>
#include <assert.h>
using namespace std;

int d[31][31] = { 1 };
int n, r;
int main() {
	cin >> n >> r;
	assert(!(n ==1 && r == 1));
	n--, r--;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0 || j == i) d[i][j] = 1;
			else d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
		}
	}
	cout << d[n][r];
}