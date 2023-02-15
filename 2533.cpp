//
//  main.cpp
//  baek-joon 2533
//
//  Created by JungWon Lee on 2023/02/15.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> nodes[1000001];
int visited[1000001] = { 0, };
int dp[1000001][2] = { 0, };

void make_dp(int v){
    visited[v] = 1;
    dp[v][0] = 1;
    for(auto next : nodes[v]){
        if(!visited[next]){
            make_dp(next);
            dp[v][1] += dp[next][0];
            dp[v][0] += min(dp[next][1], dp[next][0]);
        }
    }
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;

    for(int i = 0; i < N - 1; i++){
        int u, v;
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    
    make_dp(1);
    
    cout << min(dp[1][0], dp[1][1]) << "\n";
    
    return 0;
}
