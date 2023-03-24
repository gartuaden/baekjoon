//
//  main.cpp
//  baek-joon 1039
//
//  Created by JungWon Lee on 2023/03/24.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>

using namespace std;

int N, K;
#define NUM_MAX 1000001

int main(int argc, const char * argv[])
{
    cin >> N >> K;
    
    int visited[NUM_MAX] = { 0, };
    priority_queue<int> pq;
    queue<pair<string, int>> q;
    
    int N_size = int(to_string(N).size());
    
    if(N_size == 1){
        cout << "-1\n";
        exit(0);
    }
    
    q.push({to_string(N), 0});
    int flag = 0;
    
    while(!q.empty()){
        string cur_num = q.front().first;
        int cur_cnt = q.front().second;
        
        if(cur_cnt != flag){
            flag = cur_cnt;
            memset(visited, 0, sizeof(visited));
        }
        
        if(cur_cnt == K){
            pq.push(stoi(cur_num));
            q.pop();
            continue;
        }
        
        for(int i = 0; i < N_size - 1; i++){
            for(int j = i + 1; j < N_size; j++){
                string tmp = cur_num;
                if(tmp[j] == '0' && i == 0) continue;
                swap(tmp[i], tmp[j]);
                if(!visited[stoi(tmp)]){
                    visited[stoi(tmp)] = 1;
                    q.push({tmp, cur_cnt + 1});
                }
            }
        }
        q.pop();
    }
    
    if(K == 0) cout << N << "\n";
    else if(pq.empty()) cout << "-1\n";
    else cout << pq.top() << "\n";
    
    return 0;
}
