#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

/*
重さと価値がそれぞれwi, viであるようなn個の品物があります。
これらの品物からWを超えないように選んだときの価値の総和の最大値を求めなさい  
*/

int solution(vector<int> w, vector<int> v, int MAX_w){
    int n = w.size();
    int dp[n + 1][MAX_w + 1];
    //初期化
    for(int i = 0;i <= n;i++){
        for(int j = 0; j <= MAX_w;j++){
           dp[i][j] = 0;
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0; j <= MAX_w;j++){
            if(j < w[i]){
                dp[i + 1][j] = dp[i][j];
            }
            else{
                dp[i + 1][j] = max(dp[i][j - w[i]] + v[i], dp[i][j]);
            } 
        }
    }
    return dp[n][MAX_w];
}

int main()
{
    vector<int> w = {2, 1, 3, 4};
    vector<int> v = {3, 2, 4, 2};
    int W = 5;
    int ans = solution(w, v, W);
    cout << "最大価値は" << ans << "です" << endl;
    return 0;
}