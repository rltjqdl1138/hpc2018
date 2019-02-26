#include <iostream>
#include <algorithm>
using namespace std;

int main(){
        int N, A, B;
        int arr[10001];
        int dp1[10001]={0};
        int dists[10001][10001] ={0};

        cin >> N;
        cin >> A >> B;
        for(int i=1;i<=N;i++)
                cin >> arr[i];
        sort(arr+1, arr+N+1);

        for(int i=1;i<=N;i++){
                dists[i][i]=B;
                for(int j=i+1; j<=N; j++){
                        int dist=B;
                        for(int k=i; k<=j; k++)
                                dist+=(max(arr[k]-arr[(i+j+1)/2],arr[(i+j+1)/2]-arr[k]))*A;
                        dists[i][j]=dist;
                }
        }
        for(int i=1;i<=N;i++){
                dp1[i]=dp1[i-1]+arr[i]*A;
                for(int j=i; j>=1 && j>i-40; j--){
                        dp1[i]=min(dp1[i], dp1[j-1] + dists[j][i]);
                }

        }
        cout << dp1[N];
}