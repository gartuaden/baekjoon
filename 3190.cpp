//
//  main.cpp
//  baek-joon 3190
//
//  Created by JungWon Lee on 2023/04/11.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>

using namespace std;

int N, K, L;
int answer = 0;
int board[101][101] = { 0, };
deque<pair<int, int>> snake;

typedef struct {
    int r, c;
} Move;

Move dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void move_snake(int time, int hr, int hc, int direction, queue<pair<int, string>> q){
    if(!q.empty()){
        int cur_t = q.front().first;
        string cur_d = q.front().second;
        if(cur_t == time){
            if(cur_d == "D") direction = (direction + 1) % 4;
            else if(cur_d == "L"){
                if(direction - 1 < 0) direction = 3;
                else direction = direction - 1;
            }
            q.pop();
        }
    }

    bool flag = true;
    if(!(hr == 1 && hc == 1)){
        for(auto it = snake.begin(); it != snake.end(); it++){
            if(it->first == hr && it->second == hc) flag = false;
        }
    }

    if(hr > 0 && hr <= N && hc > 0 && hc <= N && flag){
        snake.push_front({hr, hc});
        if(board[hr][hc] == 1) {
            board[hr][hc] = 0;
            move_snake(time + 1, hr + dir[direction].r, hc + dir[direction].c, direction, q);
        }
        else{
            snake.pop_back();
            move_snake(time + 1, hr + dir[direction].r, hc + dir[direction].c, direction, q);
        }
    }
    else{
        answer = time;
        return;
    }
}

int main(int argc, const char * argv[])
{
    queue<pair<int, string>> q;
    
    cin >> N;
    cin >> K;
    for(int i = 0; i < K; i++){
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
    }
    cin >> L;
    for(int i = 0; i < L; i++){
        int X;
        string C;
        cin >> X >> C;
        q.push({X, C});
    }
    
    snake.push_front({1, 1});
    move_snake(0, 1, 1, 0, q);
    
    cout << answer << "\n";
    
    return 0;
}
