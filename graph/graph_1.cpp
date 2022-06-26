//二部グラフ判定
#include <bits/stdc++.h>

using namespace std;

vector<int> G[10000];
int V;//頂点数
int E;//辺数

int color[1000];//頂点の色を1 or -1で表す

bool dfs(int v,int c){
    color[v] = c;//頂点vをcで塗る
    for(int i=0;i<G[v].size();i++){
        if(color[G[v][i]]==c) return false;
        if(color[G[v][i]]==0 && !dfs(G[v][i],-c)) return false;
        
    }
    return true;
}

int main(){
    cin >> V >> E;
    for(int i=0;i<E;i++){
        int s,t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    for(int i=0; i<V; i++){
        if(color[i]==0){
            if(!dfs(i,1)){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
