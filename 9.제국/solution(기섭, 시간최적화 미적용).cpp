#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
        int N,M;
        string u,v,s,str[501];
        int ui, vi, par[501]={0};
        cin >> N >> M;
        cin.ignore();
        for(int i=1;i<=N;i++)
                getline(cin,str[i]);
        sort(str+1,str+1+N);
        for(int i=1;i<=M;i++){
                getline(cin,s);
                int a = s.find(",");
                int b = s.find(",", a + 1);
                int w = s.back() - '0';
                u = s.substr(0, a);
                v = s.substr(a + 1, b - a - 1);
                for(int j=1;j<=N;j++){
                        if(u==str[j]) ui=j;
                        if(v==str[j]) vi=j;
                }
                if(w == 2) swap(ui, vi);
                int changing = par[ui] ? par[ui] : ui;
                if( par[vi]==ui ) continue;
                else if( par[ui]==vi ){
                        par[ui]=0;
                        changing=ui;
                }
                if( par[vi]==0 ){
                        par[vi]=changing;
                        for(int j=1;j<=N;j++){
                                if(par[j]==vi)  par[j]=changing;
                        }
                } else{
                        int ff=par[vi];
                        par[ff]=changing;
                        for(int j=1;j<=N;j++){
                                if(par[j]==ff)  par[j]=changing;
                        }
                }
        }
        int sum=0;
        for(int i=1;i<=N;i++)
                if(par[i]==0) sum++;
        cout << sum << endl;
        for(int i=1;i<=N;i++){
                if(par[i]==0) cout <<str[i] << endl;
        }
}