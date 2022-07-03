#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <iomanip>

using namespace std;

int n, a[25], k;

bool dfs(int i, int sum){
    //iが数列の範囲を超えたら、今までの和sumとkが等しいか調べる
    if(i == n){
        return sum == k;
    }
    //a[i]を使わない場合
    if(dfs(i+1, sum)) return true;

    //a[i]を使う場合
    if(dfs(i+1, sum + a[i])) return true;

    //a[i]を使う使わないに関わらずkが作れないのでfalseを返す
    return false;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    cin >> k;

    if(dfs(0, 0)) cout << "Yes" << endl;
    else cout << "No" << endl;
}