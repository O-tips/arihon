#include <bits/stdc++.h>

using namespace std;

int n,W;
vector<int> w(100),v(100);
vector<vector<int>> dp(100,vector<int>(100000,0));

int main(){
    cin >> n >> W;
    for(int i=0;i<n;i++){
        cin >> w.at(i) >> v.at(i);
    }
    

    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            if(j >= w.at(i)){
                dp.at(i+1).at(j) = max(dp.at(i+1).at(j-w[i]) + v.at(i), dp.at(i).at(j));
            }else{
                dp.at(i+1).at(j) = dp.at(i).at(j);
            }
        }
    }
    cout << dp.at(n).at(W) << endl;
}