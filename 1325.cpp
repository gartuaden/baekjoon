//
//  main.cpp
//  baek-joon 1325
//
//  Created by 이정원 on 2022/10/14.
//  Copyright © 2021 이정원. All rights reserved.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int main(int argc, const char * argv[])
{
    int N, M;
    int A, B;
    cin >> N >> M;
    
    vector<int> result(N + 2);
    vector< vector<int> > node(N + 2);
    
    for(int i = 0; i < M; i++){
        cin >> A >> B;
        node[B].push_back(A);
    }
    
    int max = 0;
    int count = 0;
    
    for(int i = 1; i < N + 1; i++){
        
        queue<int> dq;
        vector<int> visited(N + 2, 0);
        dq.push(i);
        visited[i] = 1;
        count = 1;
        
        while(!dq.empty()){
            int cur = dq.front();
            dq.pop();
            
            for(auto it : node[cur]){
                if(!visited[it]){
                    dq.push(it);
                    visited[it] = 1;
                    count++;
                }
            }
        }
        
        if(count >= max){
            result[i] = count;
            max = count;
        }
    }
    
    vector<int> answer;
    
    for(int i = 1; i < N + 1; i++){
        if(result[i] == max) answer.push_back(i);
    }
    
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << "\n";
    }
    
    return 0;

}
