//
//  main.cpp
//  baek-joon 2098
//
//  Created by JungWon Lee on 2023/01/04.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

int N;
int W[16][16];
int dp[16][1 << 16] = {0, };

#define INF 987654321

int TSP(int i, int subset){
    
    // all cities are visited
    if(subset == (1 << N) - 1){
        if(W[i][0]) return W[i][0];
        else return INF;
    }
    
    if(dp[i][subset] != 0) return dp[i][subset];
    
    dp[i][subset] = INF;
    
    for(int j = 0; j < N; j++){
        // i-j route is available and j is not in subset
        if(W[i][j] != 0 && (subset & (1 << j)) == 0){
            // go to j and add j to subset
            dp[i][subset] = min(dp[i][subset], TSP(j, subset | (1 << j)) + W[i][j]);
        }
    }
    
    return dp[i][subset];
}

int main(int argc, const char * argv[])
{
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> W[i][j];
    }

    int answer = TSP(0, 1);
    
    cout << answer << "\n";
    
    return 0;
}

