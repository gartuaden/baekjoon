//
//  main.cpp
//  baek-joon 16987
//
//  Created by JungWon Lee on 2023/05/13.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int S[301] = { 0, };
int W[301] = { 0, };
int answer = 0;

void backtracking(int idx){

    if(idx == N) {
        int cnt = 0;
        for(int i = 0; i < N; i++) if(S[i] <= 0) cnt++;
        answer = max(answer, cnt);
        return;
    }
    if(S[idx] <= 0){
        backtracking(idx + 1);
        return;
    }
    
    bool flag = false;
    for(int i = 0; i < N; i++){
        if(i == idx || S[i] <= 0) continue;
        
        flag = true;
        S[idx] -= W[i];
        S[i] -= W[idx];
        backtracking(idx + 1);
        S[idx] += W[i];
        S[i] += W[idx];
    }
    
    if(!flag) backtracking(idx + 1);
}

int main(int argc, const char * argv[])
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> S[i] >> W[i];
    }
    
    backtracking(0);
    
    cout << answer << "\n";
    
    return 0;
}
