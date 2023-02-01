//
//  main.cpp
//  baek-joon 11049
//
//  Created by JungWon Lee on 2023/02/01.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int matrix[501][2] = { 0, };
int dp[501][501] = { 0, };
#define INF 987654321

int main(int argc, const char * argv[])
{
    cin >> N;
    
    for(int i = 1; i <= N; i++) cin >> matrix[i][0] >> matrix[i][1];
    
    for(int k = 1; k < N; k++){
        for(int i = 1; i + k <= N; i++){
            dp[i][i + k] = INF;
            
            for(int x = i; x <= i + k; x++){
                dp[i][i + k] = min(dp[i][i + k], dp[i][x] + dp[x + 1][i + k] + matrix[i][0] * matrix[x][1] * matrix[i + k][1]);
            }
        }
    }
    
    cout << dp[1][N] << "\n";
  
    return 0;
}
