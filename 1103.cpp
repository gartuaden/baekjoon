//
//  main.cpp
//  baek-joon 1103
//
//  Created by JungWon Lee on 2023/03/07.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, answer;
int board[51][51] = { 0, };
int visited[51][51] = { 0, };
int dp[51][51] = { 0, };

int backtracking(int r, int c){
    
    if(r >= N || r < 0 || c >= M || c < 0 || board[r][c] == -1) return 0;
    if(visited[r][c]){
        cout << "-1\n";
        exit(0);
    }
    if(dp[r][c] != -1) return dp[r][c];
    
    visited[r][c] = 1;
    dp[r][c] = 0;
    dp[r][c] = max(dp[r][c], backtracking(r + board[r][c], c) + 1);
    dp[r][c] = max(dp[r][c], backtracking(r, c + board[r][c]) + 1);
    dp[r][c] = max(dp[r][c], backtracking(r - board[r][c], c) + 1);
    dp[r][c] = max(dp[r][c], backtracking(r, c - board[r][c]) + 1);
    visited[r][c] = 0;
    
    return dp[r][c];
}

int main(int argc, const char * argv[])
{
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < M; j++){
            if(str.substr(j, 1) == "H") board[i][j] = -1;
            else board[i][j] = stoi(str.substr(j, 1));
        }
    }
    
    memset(dp, -1, sizeof(dp));
    answer = backtracking(0, 0);
    
    cout << answer << "\n";
    
    return 0;
}
