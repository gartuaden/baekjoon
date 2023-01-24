//
//  main.cpp
//  baek-joon 13549
//
//  Created by JungWon Lee on 2023/01/24.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

#define MAX 100001

int main(int argc, const char * argv[])
{
    int N, K;
    int dist[MAX] = { 0, };
    
    cin >> N >> K;
    
    deque<int> dq;
    dq.push_back(N);
    dist[N] = 1;
    
    while(!dq.empty()){
        int cur_v = dq.front();
        dq.pop_front();
        
        if(cur_v == K) break;
        
        if(cur_v * 2 < MAX && !dist[cur_v * 2]){
            dq.push_front(cur_v * 2);
            dist[cur_v * 2] = dist[cur_v];
        }
        
        if(cur_v + 1 < MAX && !dist[cur_v + 1]){
            dq.push_back(cur_v + 1);
            dist[cur_v + 1] = dist[cur_v] + 1;
        }
        
        if(cur_v - 1 >= 0 && !dist[cur_v - 1]){
            dq.push_back(cur_v - 1);
            dist[cur_v - 1] = dist[cur_v] + 1;
        }
    }
    
    cout << dist[K] - 1 << "\n";
    
    return 0;
}
