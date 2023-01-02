//
//  main.cpp
//  baek-joon 1053
//
//  Created by JungWon Lee on 2023/01/02.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#include <cstring>

using namespace std;

int dp[51][51];
string input = "";

int check(int left, int right){
    
    if(dp[left][right] == -1){
        if(left >= right) return 0;
        int isExchanged = 0;
        if(input[left] != input[right]) isExchanged = 1;
        
        dp[left][right] = min({ check(left + 1, right) + 1, check(left, right - 1) + 1, check(left + 1, right - 1) + isExchanged});
    }
    
    return dp[left][right];
}

int main(int argc, const char * argv[])
{
    int answer = 0;
    
    cin >> input;
    
    int N = int(input.size());
    
    memset(dp, -1, sizeof(dp));
    
    answer = check(0, N - 1);
    
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            memset(dp, -1, sizeof(dp));
            swap(input[i], input[j]);
            answer = min(answer, check(0, N - 1) + 1);
            swap(input[i], input[j]);
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}

