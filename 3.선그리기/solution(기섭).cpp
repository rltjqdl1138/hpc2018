#include <iostream>
using namespace std;
 
int main(){
    int N, sum=0,start, end, arr[10001]={0};
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> start >> end;
        for(int j=start; j<end; j++)
            arr[j]=1;
    }
    for(int i=1;i<10000;i++)
        if(arr[i])sum++;
    cout << sum;
 
}