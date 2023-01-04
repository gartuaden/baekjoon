//
//  main.cpp
//  baek-joon 16166
//
//  Created by JungWon Lee on 2023/01/04.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>
#include <set>
#include <map>

using namespace std;

int main(int argc, const char * argv[])
{
    int N,  K, last_station;
    
    set<int> stations;
    
    cin >> N;
    
    vector<vector<int>> subway(N + 1);
    
    // start, {destination, line}
    multimap<int, pair<int, int>> nodes;

    vector<int> start_lines;
    
    for(int i = 1; i <= N; i++){
        cin >> K;
        for(int j = 0; j < K; j++){
            int station;
            cin >> station;
            subway[i].push_back(station);
            stations.insert(station);
            if(station == 0) start_lines.push_back(i);
        }
    }
    
    cin >> last_station;
    
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < subway[i].size() - 1; j++){
            nodes.insert({subway[i][j], {subway[i][j + 1], i}});
            nodes.insert({subway[i][j + 1], {subway[i][j], i}});
        }
    }
    
    map<int, int> dist_map;
    
    // dist, {current station, current line}
    priority_queue<pair<int, pair<int, int>>> pq;
    
    int answer = INT_MAX;
    
    for(int i = 0; i < start_lines.size(); i++){
        
        for(auto it = stations.begin(); it != stations.end(); it++) dist_map[*it] = INT_MAX;

        dist_map[0] = 0;
        pq.push({0, {0, start_lines[i]}});
        
        while(!pq.empty()){
            int cur_station = (pq.top().second).first;
            int cur_line = (pq.top().second).second;
            pq.pop();
            
            for(auto it = nodes.lower_bound(cur_station); it != nodes.upper_bound(cur_station); it++){
                int next_station = (it->second).first;
                int next_line = (it->second).second;
                int new_dist;
                
                if(cur_line != next_line) new_dist = 1 + dist_map[cur_station];
                else new_dist = dist_map[cur_station];

                int prev_dist = dist_map[next_station];
                if(new_dist < prev_dist){
                    dist_map[next_station] = new_dist;
                    pq.push({-1 * new_dist, {next_station, next_line}});
                }
            }
        }
        
        if(answer > dist_map[last_station]) answer = dist_map[last_station];
    }
    
    if(answer == INT_MAX) answer = -1;
    
    cout << answer << "\n";
    
    return 0;
}

