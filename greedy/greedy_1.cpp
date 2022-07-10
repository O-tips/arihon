#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)
typedef pair<int,int> P;

int main() {
    const int v[6]={500,100,50,10,5,1};
    ll ans=0,a;
    vector<ll>c(6);
    cin >> a;
    rep(i,6){
        cin >> c[5-i];
    }

    rep(i,5){
        ll t = min(a/v[i],c[i]);
        a -= t*v[i];
        ans+=t;
    }

    cout << ans << endl;


}