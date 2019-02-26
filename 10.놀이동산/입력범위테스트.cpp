#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

int main(){
        int N, A, B;
        int arr[10001];
        int dp1[10001]={0};

        cin >> N;
        cin >> A >> B;
        assert(N<=10000);
        assert(A<=1000);
        assert(B<=100000);
        for(int i=1;i<=N;i++){
                cin >> arr[i];
                assert(arr[i]>0 && arr[i]<=10000);
        }
        sort(arr+1, arr+N+1);

        for(int i=1;i<=N;i++){
                dp1[i]=dp1[i-1]+arr[i]*A;
                for(int j=i; j>0 && j>i-40; j--){
                        int dist=B;
                        for(int k=j; k<=i; k++)
                                dist+=(max(arr[k]-arr[(i+j+1)/2],arr[(i+j+1)/2]-arr[k]))*A;
                        dp1[i]=min(dp1[i], dp1[j-1] + dist);
                }

        }
        cout << dp1[N];
}