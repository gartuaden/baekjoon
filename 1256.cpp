//
//  main.cpp
//  baek-joon 1256
//
//  Created by JungWon Lee on 2023/03/03.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{
    int N, M, K;
    long long dp[101][101];
    
    string answer = "";
    cin >> N >> M >> K;
    
    for(int i = 1; i <= 100; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            if(dp[i][j] > 1000000000) dp[i][j] = 1000000000;
        }
    }
    
    int a = N, z = M;
    
    if(dp[N][M] < K){
        cout << "-1\n";
        return 0;
    }
    
    for(int i = 0; i < N + M; i++){
        long long a_start = dp[a - 1][z];
        long long z_start = dp[a][z - 1];
        
        if(a == 0){
            cout << "z";
            z--;
            continue;
        }
        else if(z == 0){
            cout << "a";
            a--;
            continue;
        }
        
        if(K <= a_start){
            cout << "a";
            a--;
        }
        else{
            K -= a_start;
            cout << "z";
            z--;
        }
    }
 
    cout << "\n";
    
    return 0;
}
