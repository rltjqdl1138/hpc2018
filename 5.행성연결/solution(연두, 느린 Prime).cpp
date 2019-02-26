// 코드 원본 출처: https://www.crocus.co.kr/733

#include <bits/stdc++.h>
 
#define MAX_NODE 1001
 
using namespace std;
 
typedef pair<int, int> pii;
 
bool visit[MAX_NODE];
vector<pii> vc[MAX_NODE];
int V;
void prim(int start)
{
    visit[start] = true;
 
    // 우선 순위 큐(최소 힙)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
 
    // 1번 정점을 시작점으로 한다.
    for (int i = 0; i < vc[start].size(); i++)
    {
        // 정점과 가중치를 priority_queue에 넣어준다.
        int next = vc[start][i].first;
        int nextCost = vc[start][i].second;
 
        pq.push(pii(nextCost, next));
    }
 
    int ans = 0;
 	int cnt = 0;
    while (cnt < V-1)
    {
        int here = pq.top().second;
        int hereCost = pq.top().first;
 
        pq.pop();
 
        // 이미 방문한 정점은 무시한다.
        if (visit[here])
            continue;
 		++cnt;
        visit[here] = true;
 
        ans += hereCost;
 
        // 다음 정점을 우선순위 큐에 넣어준다.
        for (int i = 0; i < vc[here].size(); i++)
        {
            int there = vc[here][i].first;
            int thereCost = vc[here][i].second;
 
            pq.push(pii(thereCost, there));
        }
    }
 
    printf("%d", ans);
}
 
int main()
{
    
    cin >> V;
 
 	for(int i=0; i<V; ++i)
 		for(int j=0; j<V; ++j){
            int a;
 			cin >> a;
 			vc[i].push_back({j,a});
 			vc[j].push_back({i,a});
 		}

    prim(0);
 
    return 0;
}

