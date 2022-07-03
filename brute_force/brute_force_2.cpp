//Lake Counting
#include <bits/stdc++.h>

using namespace std;

int N,M;
char field[100][100];

//(x,y)が現在位置
void dfs(int x,int y){
    field[x][y] = '.';//今いるところを.に置き換える

    //8方向に移動
    for(int dx=-1; dx<=1; dx++){
        for(int dy=-1; dy<=1; dy++){
            int nx = x + dx;
            int ny = y + dy;

            //(nx,ny)が範囲内かつ水溜りならdfs呼び出す
            if(0<=nx && nx<N && 0<=ny && ny<M && field[nx][ny]=='W'){
                dfs(nx,ny);
            }
        }
    }
    return ;
}

int main(){
    int ans = 0;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> field[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(field[i][j] == 'W'){
                dfs(i,j);
                ans ++;
            }
        }
    }
    cout << ans << endl;
}
