#include <iostream>
using namespace std;
 
int p[20000];
int n, x, y;
int main() {
    cin >> n;
    while (n--) {
        cin >> x >> y;
        for (int i = x; i < y; i++) {
            p[i] = 1;
        }
    }
 
    int ans = 0;
    for (int i = 1; i < 10000; i++) {
        if (p[i]) ans++;
    }
    cout << ans;
}