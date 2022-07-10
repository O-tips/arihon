#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

//sとeは昇順であると仮定する
int solution(int n, vector<int> s, vector<int> e){
    //終わりが早いものから選んでいく
    int num_task = 1;
    int tmp_time = e[0];
    // tmp_timeより遅い開始時間を選ぶ
    for(int i = 0;i < n;i++){
        if(s[i] > tmp_time){
            tmp_time = e[i];
            num_task++;
        }
    }
    return num_task;
}

int main()
{
    vector<int> start = {1, 2, 4, 6, 8};
    vector<int> end = {3, 5, 7, 9, 10};
    int ans = solution(5, start, end);
    cout << ans << endl;
    return 0;
}