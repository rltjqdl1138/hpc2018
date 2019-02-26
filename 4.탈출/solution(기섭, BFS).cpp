#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int visit[100000]={0};
int nextNum[50000]={0};
queue<pair<int, int> > Q;

int leng(int num){
        int a;
        for(a=1;num/a>=10;a*=10);
        return a;
}

int main()
{
        int N, T, G, a=0, now=0;
        cin >> N >> T >> G;

        //버튼B 미리 계산
        for(int i=1;i<50000;i++)
                nextNum[i]= 2*i-leng(2*i);

        //BFS 시작
        Q.push( make_pair(N, 0) );
        while( !Q.empty() ){
                a = Q.front().second;
                now = Q.front().first;
                Q.pop();
                if( now > 100000 || a > T) continue;
                if( visit[now]++ ) continue;

                if( now == G ){
                        cout << a;
                        return 0;
                }
                Q.push( make_pair( now+1, a+1 ));
                if( now < 50000 ) Q.push( make_pair( nextNum[now], a+1 ));
        }
        cout << "ANG";
}