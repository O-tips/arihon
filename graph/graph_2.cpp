#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <iomanip>

#define MAX_N 5010
#define INF 100000000

using namespace std;

struct edge{ 
    int to;
    int cost; 
};
typedef pair<int, int> P;  //firstは最短距離、secondは頂点番号

int N, R;
vector<edge> G[MAX_N];

int dist[MAX_N];
int dist2[MAX_N];

void solve(){
    //priority_queue<(要素の型), (内部実装のコンテナクラス), (比較の仕方)>
    //greaterは昇順
    priority_queue<P, vector<P>, greater<P> > que;

    //無限大で埋める
    fill(dist, dist + N, INF);
    fill(dist2, dist2 + N, INF);

    dist[0] = 0;
    que.push(P(0, 0));

    while(!que.empty()){
        P p = que.top();que.pop();
        int v = p.second; //頂点番号
        int d = p.first; //最短距離
        if(dist2[v] < d) continue; 

        for(int i=0;i<G[v].size();i++){
            edge &e = G[v][i];
            int d2 = d + e.cost;

            //最短路を求める
            if(dist[e.to] > d2){
                swap(dist[e.to], d2);
                que.push(P(dist[e.to], e.to));
            }

            //2番目の最短路を求める
            if(dist2[e.to] > d2 && dist[e.to] < d2){
                dist2[e.to] = d2;
                que.push(P(dist2[e.to], e.to));
            }
        }
    }
    cout << dist2[N-1] << endl;
}

int main(){
    cin >> N >> R;
    
    //TO DO 重みつきグラフをGに格納

    solve();
}   



