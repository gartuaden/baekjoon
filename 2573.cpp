//
//  main.cpp
//  baek-joon 2573
//
//  Created by JungWon Lee on 2023/03/29.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>

using namespace std;

int N, M;
int iceberg[301][301] = { 0, };
int org_iceberg[301][301] = { 0, };
int visited[301][301] = { 0, };

typedef struct {
    int r, c;
} Move;

Move dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void DFS(int r, int c){
    for(int i = 0; i < 4; i++){
        int nr = r + dir[i].r;
        int nc = c + dir[i].c;
        if(nr >= 0 && nr < N && nc >= 0 && nc < M){
            if(visited[nr][nc]) continue;
            if(iceberg[nr][nc] != 0){
                visited[nr][nc] = 1;
                DFS(nr, nc);
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    cin >> N >> M;
    queue<pair<int, int>> q;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> iceberg[i][j];
            org_iceberg[i][j] = iceberg[i][j];
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(iceberg[i][j] != 0) q.push({i, j});
        }
    }
    
    int year = 0;
    
    while(1){
        if(q.empty() || q.size() == 1){
            year = 0;
            break;
        }
        int q_size = int(q.size());
        for(int x = 0; x < q_size; x++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            int zero_cnt = 0;
            
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i].r;
                int nc = c + dir[i].c;
                if(nr >= 0 && nr < N && nc >= 0 && nc < M){
                    if(org_iceberg[nr][nc] == 0) zero_cnt++;
                }
            }
            
            if(org_iceberg[r][c] - zero_cnt <= 0) iceberg[r][c] = 0;
            else{
                iceberg[r][c] -= zero_cnt;
                q.push({r, c});
            }
        }

        int field_cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!visited[i][j] && iceberg[i][j] != 0){
                    visited[i][j] = 1;
                    DFS(i, j);
                    field_cnt++;
                }
            }
        }
        
        year++;
        
        if(field_cnt >= 2) break;
        memset(visited, 0, sizeof(visited));
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                org_iceberg[i][j] = iceberg[i][j];
            }
        }
    }
    
    cout << year << "\n";
    
    return 0;
}
