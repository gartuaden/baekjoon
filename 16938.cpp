//
//  main.cpp
//  baek-joon 16938
//
//  Created by JungWon Lee on 2023/01/12.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int A[16] = { 0, };

int N, L, R, X;
int answer = 0;

void backtracking(int subset, int cur_r, int idx, int sum, int max_i, int min_i){
    if(cur_r == 0){
        if(sum >= L && sum <= R && (X <= max_i - min_i)) answer++;
        return;
    }
    
    for(int i = idx; i < N; i++){
        if((subset & (1 << i)) == 0){
            int temp_max = max_i;
            int temp_min = min_i;
            
            subset = (subset | (1 << i));
            if(max_i < A[i]) max_i = A[i];
            if(min_i > A[i]) min_i = A[i];
            
            backtracking(subset, cur_r - 1, i, sum + A[i], max_i, min_i);
            
            subset = (subset & (~1 << i));
            max_i = temp_max;
            min_i = temp_min;
        }
    }
}

int main(int argc, const char * argv[])
{
    cin >> N >> L >> R >> X;

    for(int i = 0; i < N; i++) cin >> A[i];
    
    for(int r = 2; r <= N; r++) backtracking(0, r, 0, 0, 0, 1000001);
    
    cout << answer << "\n";
    
    return 0;
}
