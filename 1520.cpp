//
//  main.cpp
//  baek-joon 1520
//
//  Created by JungWon Lee on 2023/03/31.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int N, M;
int board[501][501] = { 0, };
int visited[501][501] = { 0, };
int dp[501][501] = { 0, };

#define MAX_HEIGHT 100001

typedef struct {
    int r, c;
} Move;

Move dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int DFS(int r, int c, int prev_height){
    
    if(r >= N || r < 0 || c >= M || c < 0 || board[r][c] >= prev_height) return 0;
    if(r == N - 1 && c == M - 1) return 1;
    if(dp[r][c] != -1) return dp[r][c];
    
    dp[r][c] = 0;
    for(int i = 0; i < 4; i++){
        int new_r = r + dir[i].r;
        int new_c = c + dir[i].c;
        dp[r][c] += DFS(new_r, new_c, board[r][c]);
    }
    
    return dp[r][c];
}

int main(int argc, const char * argv[])
{
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    int answer = DFS(0, 0, MAX_HEIGHT);
    
    cout << answer << "\n";
    
    return 0;
}
