//
//  main.cpp
//  baek-joon 4485
//  Dijkstra Algorithm
// 
//  Created by 이정원 on 2022/10/31.
//  Copyright © 2022 이정원. All rights reserved.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;

int graph[126][126] = { 0, };

int main(int argc, const char * argv[])
{
    vector<int> answer;
    int N, k;
    
    priority_queue<pair<int, int>> pq;
    
    while(1){
        cin >> N;
        if(N == 0) break;
        
        vector<pair<int, int>> nodes[N * N + 1];
        vector<int> dist_arr(N * N + 1, INT_MAX);
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++) {
                cin >> k;
                graph[i][j] = k;
            }
        }
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(j + 1 < N){
                    nodes[i * N + j + 1].push_back({i * N + j + 1 + 1, graph[i][j]});
                    nodes[i * N + j + 1 + 1].push_back({i * N + j + 1, graph[i][j + 1]});
                }
                if(i + 1 < N){
                    nodes[i * N + j + 1].push_back({(i + 1) * N + j + 1, graph[i][j]});
                    nodes[(i + 1) * N + j + 1].push_back({i * N + j + 1, graph[i + 1][j]});
                }
            }
        }
        
        
        dist_arr[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty()){
            int cur = pq.top().second;
            pq.pop();
            
            for(int i = 0; i < nodes[cur].size(); i++){
                int next = nodes[cur][i].first;
                int new_dist = nodes[cur][i].second + dist_arr[cur];
                int prev_dist = dist_arr[next];
                if(new_dist < prev_dist){
                    dist_arr[next] = new_dist;
                    pq.push({-1 * new_dist, next});
                }
            }
        }
        answer.push_back(dist_arr[N * N] + graph[N - 1][N - 1]);
        memset(graph, 0, sizeof(graph));
    }
    
    for(int i = 0; i < answer.size(); i++) cout << "Problem " << i + 1 << ": " << answer[i] << "\n";
    
    return 0;
 
}

