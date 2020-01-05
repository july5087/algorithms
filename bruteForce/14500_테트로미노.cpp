//
//  main.cpp
//  14500_테트로미노(retry)
//
//  Created by Kim Seong Jin on 2020. 1. 4..
//  Copyright © 2020년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

#define MAX 501
using namespace std;

int dy[4]{-1, 1, 0, 0};
int dx[4]{0, 0, -1, 1};
int ret;
bool visited[MAX][MAX];
int table[MAX][MAX];
int n, m;


bool inRange(int y, int x){
    return 0<= y && y < n && 0 <= x && x< m;
}

void dfs(int y, int x, int cnt, int sum){
    
    if(cnt == 4){
        ret = max(ret, sum);
        return;
    }
   
    for(int i = 0 ; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(!visited[ny][nx] && inRange(ny, nx)){
            visited[ny][nx] = true;
            dfs(ny, nx, cnt+1, sum+table[ny][nx]);
            visited[ny][nx] = false;
        }
    }
}

void checkB5V(int y, int x){
    ret = max(ret, table[y][x] + table[y+1][x] + table[y+2][x] + table[y+1][x+1]);
    ret = max(ret, table[y][x+1] + table[y+1][x+1] + table[y+2][x+1] + table[y+1][x]);
}

void checkB5H(int y, int x){
    ret = max(ret, table[y+1][x] + table[y+1][x+1] + table[y+1][x+2] + table[y][x+1]);
    ret = max(ret, table[y][x] + table[y][x+1] + table[y][x+2] + table[y+1][x+1]);
}

void solve(){
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            visited[y][x] = true;
            dfs(y, x, 1, table[y][x]);
            visited[y][x] = false;
        }
    }
    
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            if(y+1 < n && x+2 < m){
                checkB5H(y, x);
            }
            if(y+2 < n && x+1 < m){
                checkB5V(y, x);
            }

        }
    }
    
}

void build(){
    cin>>n>>m;
    
    for(int y = 0 ; y < n ; y++){
        for(int x = 0 ; x < m ; x++){
            cin>>table[y][x];
        }
    }
}

int main(int argc, const char * argv[]) {
    build();
    solve();
    cout<<ret<<endl;
    return 0;
}
