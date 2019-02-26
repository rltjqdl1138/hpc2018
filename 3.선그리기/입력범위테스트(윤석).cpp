#include <iostream>
#include <assert.h>
using namespace std;
 
int p[20000];
int n, x, y;
int main() {
    cin >> n;
    if(n>10000) assert(false);
    while (n--) {
        cin >> x >> y;
        if(x >= y || x < 1 || y > 10000) assert(false);
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