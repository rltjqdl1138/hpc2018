#include <stdio.h>
 
int main(){
    int k,n,arr[31][31];
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++){
        arr[i][1] = arr[i][i] = 1;
        for(int j=2; j<i;j++)
            arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
    }
    printf("%d",arr[n][k]);
}