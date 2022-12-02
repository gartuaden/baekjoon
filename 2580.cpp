//
//  main.cpp
//  baek-joon 2580
//
//  Created by JungWon Lee on 2022/12/02.
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

int zero_count = 0;
int board[9][9] = {0, };

vector<pair<int, int>> zeros;

vector<vector<int>> row(9, vector<int>(10, 0));
vector<vector<int>> col(9, vector<int>(10, 0));
vector<vector<int>> cube(9, vector<int>(10, 0));

void init(int r, int c, int num, int x){
    row[r][num] = x;
    col[c][num] = x;
    cube[(r / 3) * 3 + c / 3][num] = x;
}

void backtracking(int level){
    
    if(level == zero_count){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
        return;
    }
    
    int r = zeros[level].first;
    int c = zeros[level].second;

    for(int num = 1; num < 10; num++){
        board[r][c] = num;
           
        if(row[r][num] || col[c][num] || cube[(r / 3) * 3 + c / 3][num]) board[r][c] = 0;
        else {
            init(r, c, num, 1);
            
            backtracking(level + 1);
            
            board[r][c] = 0;
            init(r, c, num, 0);
        }
    }
}

int main(int argc, const char * argv[])
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) zeros.push_back({i, j});
            else{
                row[i][board[i][j]] = 1;
                col[j][board[i][j]] = 1;
                cube[(i / 3) * 3 + j / 3][board[i][j]] = 1;
            }
        }
    }
    zero_count = int(zeros.size());
    
    backtracking(0);
    
    return 0;
}
