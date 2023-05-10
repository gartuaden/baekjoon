//
//  main.cpp
//  baek-joon 3109
//
//  Created by JungWon Lee on 2023/05/10.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int R, C;
int board[10001][501] = { 0, };
int answer = 0;
int cur_pipe = 0;

typedef struct{
    int r, c;
} Move;

Move dir[3] = { {-1, 1}, {0, 1}, {1, 1} };

void DFS(int r, int c){
    board[r][c] = 1;
    answer = cur_pipe;

    if(c == C - 1) cur_pipe++;
    else{
        for(int d = 0; d < 3; d++) {
            int nr = r + dir[d].r;
            int nc = c + dir[d].c;
            if(nr >= 0 && nr < R && nc >= 0 && nc < C && !board[nr][nc]){
                if(answer != cur_pipe) return;
                DFS(nr, nc);
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    cin >> R >> C;
    
    for(int i = 0; i < R; i++){
        string input;
        cin >> input;
        for(int j = 0; j < C; j++){
            if(input.substr(j, 1) == "x") board[i][j] = 1;
        }
    }
    
    for(int i = 0; i < R; i++) DFS(i, 0);
    
    cout << answer << "\n";
    
    return 0;
}
