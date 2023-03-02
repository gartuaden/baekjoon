//
//  main.cpp
//  baek-joon 9279
//
//  Created by JungWon Lee on 2023/03/03.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <memory.h>
#include <string.h>

using namespace std;

int N, C;
int visited[1001] = { 0, };
int dp[1001] = { 0, };
int sth[1001][1001] = { 0, };

void dfs(int cur, vector<int> node[1001]){
    visited[cur] = 1;
    for(auto next : node[cur]){
        if(!visited[next]){
            dfs(next, node);
            if(dp[next] != 0){
                if(sth[cur][next] > dp[next]) dp[cur] += dp[next];
                else dp[cur] += sth[cur][next];
            }
            else dp[cur] += sth[cur][next];
        }
    }
    return;
}

int main(int argc, const char * argv[])
{
    while(cin >> N >> C){
        vector<int> node[1001];
        for(int i = 0; i < N - 1; i++){
            int u, v, w;
            cin >> u >> v >> w;
            node[u].push_back(v);
            node[v].push_back(u);
            sth[u][v] = w;
            sth[v][u] = w;
        }
        dfs(C, node);
        cout << dp[C] << "\n";
        
        memset(visited, 0, sizeof(visited));
        memset(sth, 0, sizeof(sth));
        memset(dp, 0, sizeof(dp));
    }
    
    return 0;
}
