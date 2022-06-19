/**
*    author:  
*    created: 19.06.2022 00:04:59
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)
typedef pair<int,int> P;

int main() {
    ll n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;

    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));

    rep(i,n){
        rep(j,m){
            if(s[i]==t[j]){
                dp[i+1][j+1]=max({dp[i][j]+1,dp[i][j+1],dp[i+1][j]});
            }else{
              dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
  
  cout << dp[n][m] << endl;

}