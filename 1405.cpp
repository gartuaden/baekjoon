//
//  main.cpp
//  baek-joon 1405
//
//  Created by JungWon Lee on 2022/12/12.
//  Copyright © 2022 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <climits>
#include <cmath>

using namespace std;

#define MAX_SIZE 15

int board[2 * MAX_SIZE + 2][2 * MAX_SIZE + 2] = { 0, };

typedef struct{
    int r, c;
}Move;

Move dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

double dir_p[4] = { 0, };

int N;
double answer = 0;

void backtracking(int r, int c, int cur_N, double p){
    if(board[r][c] == 0){
        if(cur_N == N){
            answer += p;
            return;
        }
        board[r][c] = 1;
        for(int i = 0; i < 4; i++){
            backtracking(r + dir[i].r, c + dir[i].c, cur_N + 1, p * dir_p[i]);
        }
        board[r][c] = 0;
    }
}

int main(int argc, const char * argv[])
{
    cin >> N;
    
    for(int i = 0; i < 4; i++){
        double input;
        cin >> input;
        dir_p[i] = input / 100;
    }
    
    cout.precision(11);
    cout << fixed;
    
    backtracking(MAX_SIZE, MAX_SIZE, 0, 1);
    
    cout << answer << "\n";
    
    return 0;
}
