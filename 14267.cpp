//
//  main.cpp
//  baek-joon 14267
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

vector<int> node[100001];

int dp[100001] = { 0, };

void DFS(int cur){
    for(auto next : node[cur]){
        dp[next] += dp[cur];
        DFS(next);
    }
}

int main(int argc, const char * argv[])
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        int boss;
        cin >> boss;
        if(boss != -1) node[boss].push_back(i);
    }
    
    for(int i = 0; i < m; i++){
        int idx, w;
        cin >> idx >> w;
        dp[idx] += w;
    }
    
    DFS(1);
    
    for(int i = 1; i <= n; i++) cout << dp[i] << " ";

    return 0;
}
