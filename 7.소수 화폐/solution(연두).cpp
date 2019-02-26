#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define xx first
#define yy second

const int MAX = 40010, MOD = 123456789;
bool isPrime[MAX+2];
vector<int> prime;
void find_prime(){
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int sqMAX = sqrt(MAX)+1;
	for(long long i=2; i<=MAX; ++i)
		if(isPrime[i]){
			prime.push_back(i);
			for(long long j=i*i; j<=MAX; j+=i)
				isPrime[j] = false;
		}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	find_prime();
	int n, dp[40001] = {};
	cin >> n;
	dp[0] = 1;
	for(int i=0; i<prime.size(); ++i){
		for(int j=prime[i]; j<=n; ++j){
			dp[j] += dp[j-prime[i]];
			dp[j] %= MOD;
		}
		//cout << prime[i] << ' ' << dp[j] << '\n';
	}
	cout << dp[n];
}