#include <stdio.h>
 
int main(){
    int N, sum=0,start, end, arr[10001]={0};
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d", &start, &end);
        for(int j=start; j<end; j++)
            arr[j]=1;
    }
    for(int i=1;i<10000;i++)
        if(arr[i])sum++;
    printf("%d",sum);
 
}