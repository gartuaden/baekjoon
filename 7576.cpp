//
//  main.cpp
//  baek-joon 7576
//  BFS Algorithm
// 
//  Created by 이정원 on 2022/11/01.
//  Copyright © 2022 이정원. All rights reserved.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;

int storage[1001][1001] = { 0, };

typedef struct{
    int r, c;
}Move;

Move dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };


int main(int argc, const char * argv[])
{
    vector<pair<int, int>> tmt;
    queue<pair<int, int>> q;
    int day = 0;
    int zero_count = 0;
    int M, N;
    bool flag = false;
    
    cin >> M >> N;
    int input;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> input;
            storage[i][j] = input;
            if(input == 1) q.push({i, j});
            if(input == 0) {
                flag = true;
                zero_count++;
            }
        }
    }
    
    if(!flag){
        cout << 0;
        return 0;
    }
    
    q.push({-1, -1});
    
    while(!q.empty()){
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        
        if(cur_r == -1 && cur_c == -1){
            if(q.front().first == -1){
                day = -1;
                break;
            }
            q.push({-1, -1});
            day++;
            continue;
        }
        
        for(int i = 0; i < 4; i++){
            int next_r = cur_r + dir[i].r;
            int next_c = cur_c + dir[i].c;
            
            if(next_r >= 1 && next_r <= N && next_c >= 1 && next_c <= M){
                if(storage[next_r][next_c] == 0){
                    storage[next_r][next_c] = 1;
                    zero_count--;
                    q.push({next_r, next_c});
                }
            }
        }
        
        if(zero_count == 0) {
            day++;
            break;
        }
        
    }
    
    cout << day;
    
    return 0;

}
