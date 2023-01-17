//
//  main.cpp
//  baek-joon 17492
//
//  Created by JungWon Lee on 2023/01/17.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, pieces_count;
int board[11][11] = { 0, };

typedef struct{
    int r, c;
}Move;

Move dir[8] = { {2, 0}, {0, 2}, {2, 2},
    {-2, 0}, {0, -2}, {-2, 2}, {2, -2}, {-2, -2} };

Move dir_check[8] = { {1, 0}, {0, 1}, {1, 1},
    {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {-1, -1} };

void backtracking(int count){
    if(count == 1) {
        pieces_count = 1;
        return;
    }
    
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            if(board[r][c] == 2){
                for(int i = 0; i < 8; i++){
                    int next_r = r + dir[i].r;
                    int next_c = c + dir[i].c;
                    
                    if(next_r >= 0 && next_c >= 0 && next_r < N && next_c < N){
                        int nr = r + dir_check[i].r;
                        int nc = c + dir_check[i].c;
                        if(board[next_r][next_c] == 0 && board[nr][nc] == 2){
                            board[r][c] = 0;
                            board[next_r][next_c] = 2;
                            board[nr][nc] = 0;
                            backtracking(count - 1);
                            board[r][c] = 2;
                            board[next_r][next_c] = 0;
                            board[nr][nc] = 2;
                        }
                    }
                }
            }
        }
    }
    
}

int main(int argc, const char * argv[])
{
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) pieces_count++;
        }
    }

    backtracking(pieces_count);
 
    if(pieces_count == 1) cout << "Possible\n";
    else cout << "Impossible\n";
  
    return 0;
}
