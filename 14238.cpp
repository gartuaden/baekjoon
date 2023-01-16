//
//  main.cpp
//  baek-joon 14238
//
//  Created by JungWon Lee on 2023/01/17.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int N;
string answer = "";

int workers[3] = { 0, };

bool dp[51][51][51][3][3] = { false, };

bool DFS(int A, int B, int C, int prev_1, int prev_2){
    
    if(A == workers[0] && B == workers[1] && C == workers[2]) return true;
    if(dp[A][B][C][prev_1][prev_2]) return false;
    
    dp[A][B][C][prev_1][prev_2] = true;
    
    if(A + 1 <= workers[0]){
        answer += "A";
        if(DFS(A + 1, B, C, 0, prev_1)) return true;
        answer.erase(answer.size() - 1);
    }
    if(B + 1 <= workers[1]){
        answer += "B";
        if(prev_1 != 1 && DFS(A, B + 1, C, 1, prev_1)) return true;
        answer.erase(answer.size() - 1);
    }
    if(C + 1 <= workers[2]){
        answer += "C";
        if(prev_1 != 2 && prev_2 != 2 && DFS(A, B, C + 1, 2, prev_1)) return true;
        answer.erase(answer.size() - 1);
    }

    return false;
}
 
int main(int argc, const char * argv[])
{
    string S;
    cin >> S;
    
    N = int(S.size());
 
    for(int i = 0; i < S.size(); i++) workers[int(S[i]) - 65]++;
    
    if(DFS(0, 0, 0, -1, -1)) cout << answer << "\n";
    else cout << "-1\n";

    return 0;
}
