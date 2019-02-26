#include <iostream>
#include <assert.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n < 1946 || n > 1000000) assert(false);
	cout << n - 1946;
}