//
//  main.cpp
//  baek-joon 1516
//
//  Created by JungWon Lee on 2023/05/13.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int cost[501] = { 0, };
int entry[501] = { 0, };
int answer[501] = { 0, };

int main(int argc, const char * argv[])
{
    cin >> N;
    vector<int> edge[N + 1];
    
    for(int i = 1; i <= N; i++){
        cin >> cost[i];
        int input;
        while(1){
            cin >> input;
            if(input == -1) break;
            edge[input].push_back(i);
            entry[i]++;
        }
    }
    
    queue<int> q;
    
    for(int i = 1; i <= N; i++){
        if(entry[i] == 0){
            q.push(i);
            answer[i] = cost[i];
        }
    }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < edge[cur].size(); i++){
            int next = edge[cur][i];
            entry[next]--;
            
            answer[next] = max(answer[next], answer[cur] + cost[next]);
            if(entry[next] == 0) q.push(next);
        }
    }
    
    for(int i = 1; i <= N; i++) cout << answer[i] << "\n";
    
    return 0;
}
