#include <iostream>
using namespace std;
 
int main(){
    int k,n,arr[31][31];
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        arr[i][1] = arr[i][i] = 1;
        for(int j=2; j<i;j++)
            arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
    }
    cout << arr[n][k];
}