#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int check[1001]={0};

int findroot( int n ){
        if( check[n]==n ) return n;
        return findroot( check[n] );
}
int main(){
        int N, a;
        long long int sum=0;
        vector<pair<int,pair<int,int> > > v;

        //입력 및 그래프 생성
        cin >> N;
        for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                        cin >> a;
                        if( i==j ) continue;
                        v.push_back( make_pair( a,make_pair(i,j) ));
                }
        }

        //Kruskal을 위한 Edge의 sorting과
        //Cycle이 생겼는지 판단하기 위한 check 초기화
        for(int i=1;i<=N;i++) check[i]=i;
        sort(v.begin(), v.end());

        //계산
        for(int i=0;i<v.size();i++){
                int color1 = findroot( v[i].second.first );
                int color2 = findroot( v[i].second.second );

                if(color1 == color2)    continue;
                if(color1 > color2 )    swap( color1, color2 );
                check[color2] = color1;

                sum += v[i].first;
        }
        cout << sum << endl;
}