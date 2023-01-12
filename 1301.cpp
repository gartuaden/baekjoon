//
//  main.cpp
//  baek-joon 1301
//
//  Created by JungWon Lee on 2023/01/13.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, sum = 0;

int marble[6] = { 0, };
long long dp[11][11][11][11][11][6][6] = { 0, };

long long backtracking(int prev, int current, int count){
    if(count == sum) return 1;
    
    long long result = dp[marble[1]][marble[2]][marble[3]][marble[4]][marble[5]][prev][current];
    
    if(result != -1) return result;

    result = 0;
    for(int i = 1; i <= N; i++){
        if(prev != i && current != i && marble[i]){
            marble[i]--;
            result += backtracking(current, i, count + 1);
            marble[i]++;
        }
    }
    
    dp[marble[1]][marble[2]][marble[3]][marble[4]][marble[5]][prev][current] = result;

    return result;
}
 
int main(int argc, const char * argv[])
{
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> marble[i];
        sum += marble[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << backtracking(0, 0, 0) << "\n";
    
    return 0;
}
