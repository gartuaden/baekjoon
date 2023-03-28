//
//  main.cpp
//  baek-joon 10026
//
//  Created by JungWon Lee on 2023/03/28.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;

int N;
int grid_N[101][101] = { 0, };
int grid_W[101][101] = { 0, };
int visited[101][101] = { 0, };

#define NORMAL 0
#define WEAK 1

typedef struct {
    int r, c;
} Move;

Move dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void DFS(int r, int c, int flag){
    for(int i = 0; i < 4; i++){
        int nr = r + dir[i].r;
        int nc = c + dir[i].c;
        if(nr >= 0 && nr < N && nc >= 0 && nc < N){
            if(visited[nr][nc]) continue;
            if(flag == NORMAL && grid_N[r][c] == grid_N[nr][nc]){
                visited[nr][nc] = 1;
                DFS(nr, nc, flag);
            }
            if(flag == WEAK && grid_W[r][c] == grid_W[nr][nc]){
                visited[nr][nc] = 1;
                DFS(nr, nc, flag);
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    cin >> N;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < N; j++){
            if(str.substr(j, 1) == "R") {
                grid_N[i][j] = 1;
                grid_W[i][j] = 1;
            }
            else if(str.substr(j, 1) == "G") {
                grid_N[i][j] = 2;
                grid_W[i][j] = 1;
            }
            else if(str.substr(j, 1) == "B") {
                grid_N[i][j] = 3;
                grid_W[i][j] = 3;
            }
        }
    }
    
    int field_normal = 0;
    int field_weak = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                visited[i][j] = 1;
                DFS(i, j, NORMAL);
                field_normal++;
            }
        }
    }
    
    memset(visited, 0, sizeof(visited));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                visited[i][j] = 1;
                DFS(i, j, WEAK);
                field_weak++;
            }
        }
    }
    
    cout << field_normal << " " << field_weak << "\n";
    
    return 0;
}
