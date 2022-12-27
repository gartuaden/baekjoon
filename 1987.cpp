//
//  main.cpp
//  baek-joon 1987
//
//  Created by JungWon Lee on 2022/12/28.
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

int R, C;
int answer = 1;

typedef struct{
    int r, c;
}Move;

Move dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

vector<string> board;

void backtracking(int r, int c, int cur, vector<int>& check){
    
    if(r >= 0 && c >= 0 && r < R && c < C && check[int(board[r][c]) - 65] == 0){
        
        check[int(board[r][c] - 65)] = 1;
        
        for(int i = 0; i < 4; i++){
            backtracking(r + dir[i].r, c + dir[i].c, cur + 1, check);
        }
        check[int(board[r][c] - 65)] = 0;
    }
    else{
        if(answer < cur) answer = cur;
        return;
    }
}

int main(int argc, const char * argv[])
{
    
    cin >> R >> C;
    
    vector<int> check(25, 0);
    
    for(int i = 0; i < R; i++){
        string input;
        cin >> input;
        board.push_back(input);
    }
    
    backtracking(0, 0, 0, check);
    
    cout << answer << "\n";
    
    return 0;
}
