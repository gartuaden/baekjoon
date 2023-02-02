//
//  main.cpp
//  baek-joon 1916
//
//  Created by JungWon Lee on 2023/02/02.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int main(int argc, const char * argv[])
{
    int N, M, A, B;
    
    cin >> N;
    cin >> M;
    
    vector<pair<int, int>> nodes[N + 1];
    vector<int> dist_arr(N + 1, INT_MAX);
    priority_queue<pair<int, int>> pq;
    
    for(int i = 0; i < M; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        nodes[a].push_back({cost, b});
    }
    
    for(int i = 1; i <= N; i++) sort(nodes[i].begin(), nodes[i].end());
    
    cin >> A >> B;
    
    dist_arr[A] = 0;
    pq.push({0, A});
    
    while(!pq.empty()){
        int cur = pq.top().second;
        pq.pop();
        
        for(auto it: nodes[cur]){
            int next = it.second;
            int new_dist = it.first + dist_arr[cur];
            int prev_dist = dist_arr[next];
            
            if(new_dist < prev_dist){
                dist_arr[next] = new_dist;
                pq.push({-1 * new_dist, next});
            }
        }
    }
    
    cout << dist_arr[B] << "\n";
  
    return 0;
}
