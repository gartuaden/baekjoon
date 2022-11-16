//
//  main.cpp
//  baek-joon 11060
//
//  Created by 이정원 on 2022/10/19.
//  Copyright © 2022 이정원. All rights reserved.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, const char * argv[])
{
    int N, Ai;
    
    cin >> N;
    
    vector<int> A(N + 2);
    vector<int> dp(N + 2, -1);
    
    for(int i = 1; i < N + 1; i++){
        cin >> Ai;
        A[i] = Ai;
    }
    
    dp[1] = 0;
    
    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < A[i] + 1; j++){
            if(i + j > N + 1) break;
            if(dp[i] != -1){
                if(dp[i + j] == -1) dp[i + j] = dp[i] + 1;
                else{
                    if(dp[i + j] > dp[i] + 1) dp[i + j] = dp[i] + 1;
                }
            }
        }
    }
    
    cout << dp[N];
    
    return 0;

}
