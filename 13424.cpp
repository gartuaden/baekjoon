//
//  main.cpp
//  baek-joon 13424
//
//  Created by JungWon Lee on 2022/11/21.
//  Copyright © 2022 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <climits>
#include <cmath>

using namespace std;

#define INF 1e9

int main(int argc, const char * argv[])
{
    int T;
    int graph[101][101];
    vector<int> friends;
    vector<int> ans;
    
    cin >> T;
    
    for(int t = 0; t < T; t++){
        int N, M, K;
        
        cin >> N >> M;
        
        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                if(i == j) continue;
                graph[i][j] = INF;
            }
        }
        friends.clear();
        
        for(int i = 0; i < M; i++){
            int a, b, c;
            cin >> a >> b >> c;
            graph[a][b] = c;
            graph[b][a] = c;
        }
        
        cin >> K;
        
        while(K--) {
            int f;
            cin >> f;
            friends.push_back(f);
        }
        
        for(int k = 1; k <= N; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    if(i != j && graph[i][k] + graph[k][j] < graph[i][j]) graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }

        int min_sum = INF;
        int answer = 0;
        for(int i = 1; i <= N; i++){
            int cur_sum = 0;
            for(int k = 0; k < friends.size(); k++) cur_sum += graph[i][friends[k]];

            if(cur_sum < min_sum){
                answer = i;
                min_sum = cur_sum;
            }
        }
        ans.push_back(answer);
    }
    
    
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
    
    return 0;
}
