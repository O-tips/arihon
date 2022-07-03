/**
*    author:  Dooloper
*    created: 03.07.2022 16:45:50
**/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)
typedef tuple<ll,ll,ll> T;
ll n,m;
vector<vector<bool>> t(100,vector<bool>(100,false));

int main() {

    cin >> n >> m;

    vector<vector<char>> g(n,vector<char>(m));
    int x,y,co;
    rep(i,n){
        rep(j,m){
            cin >> g[i][j];
            if(g[i][j] == 'S'){
                x=i;
                y=j;
              t[x][y]=true;
            }
        }
    }
  queue<T> q;
  q.push(make_tuple(x,y,0));
  tie(x,y,co)=q.front();

  while(g[x][y]!='G'){
    q.pop();
    //cout << x << y << endl;
    t[x][y]=true;
      if(x-1>=0 && g[x-1][y]!='#' && !t[x-1][y]){         
        q.push(make_tuple(x-1,y,co+1));
      }
      if(y-1>=0 && g[x][y-1]!='#' && !t[x][y-1]){
        //cout << x << y-1 << endl;
         q.push(make_tuple(x,y-1,co+1));
      }
      if(x+1<n && g[x+1][y]!='#' && !t[x+1][y]){
         q.push(make_tuple(x+1,y,co+1));
      }
      if(y+1<m && g[x][y+1]!='#' && !t[x][y+1]){
          q.push(make_tuple(x,y+1,co+1));
      }
    tie(x,y,co)=q.front();
  }
  
  cout << co << endl;

    
}