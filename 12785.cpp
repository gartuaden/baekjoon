//
//  main.cpp
//  baek-joon 12785
//
//  Created by JungWon Lee on 2023/01/11.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[])
{
    long long answer_1, answer_2;
    int w, h, x, y;
    
    cin >> w >> h;
    cin >> x >> y;
    
    long long dp[202][202] = { 0, };
    dp[1][1] = 1;
    for(int i = 1; i <= y; i++){
        for(int j = 1; j <= x; j++){
            if(i == 1 && j == 1) continue;
            else if(i == 1) dp[i][j] = 1;
            else if(j == 1) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000007;
        }
    }
    
    answer_1 = dp[y][x] % 1000007;
    
    memset(dp, 0, sizeof(dp));
    
    dp[y][x] = 1;
    for(int i = y; i <= h; i++){
        for(int j = x; j <= w; j++){
            if(i == y && j == x) continue;
            else if(i == y) dp[i][j] = 1;
            else if(j == x) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000007;
        }
    }
    
    answer_2 = dp[h][w] % 1000007;
    
    if(w == x && h == y) cout << answer_1 % 1000007 << "\n";
    else cout << (answer_1 * answer_2) % 1000007 << "\n";
    
    return 0;
}

