//
//  main.cpp
//  baek-joon 2579
//
//  Created by JungWon Lee on 2023/01/10.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int main(int argc, const char * argv[])
{
    int N;
    
    cin >> N;
    
    vector<int> score(N + 1, 0);
    vector<vector<int>> dp(N + 1, vector<int> (3, -1));
    
    for(int i = 1; i < N + 1; i++) cin >> score[i];
    
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    
    dp[1][0] = score[1];
    dp[1][1] = 0;
    dp[1][2] = 0;
    
    for(int i = 2; i < N + 1; i++){
        if(dp[i - 1][0] > dp[i - 2][0]){
            if(dp[i - 1][2] > dp[i - 1][0]){
                dp[i][0] = dp[i - 1][2] + score[i];
                dp[i][1] = dp[i - 1][1] + 1;
            }
            else{
                if(dp[i - 1][1] < 1) {
                    dp[i][0] = dp[i - 1][0] + score[i];
                    dp[i][1] = dp[i - 1][1] + 1;
                }
                else {
                    if(dp[i - 2][0] > dp[i - 1][2]){
                        dp[i][0] = dp[i - 2][0] + score[i];
                        dp[i][1] = 0;
                    }
                    else{
                        dp[i][0] = dp[i - 1][2] + score[i];
                        dp[i][1] = dp[i - 1][1] + 1;
                    }
                }
            }
            dp[i][2] = dp[i - 2][0] + score[i];
        }
        else{
            dp[i][0] = dp[i - 2][0] + score[i];
            dp[i][1] = 0;
            dp[i][2] = dp[i - 2][0] + score[i];
        }
    }
    
    cout << max(dp[N][0], dp[N][2]) << "\n";
    
    return 0;
}

