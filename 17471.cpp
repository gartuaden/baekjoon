//
//  main.cpp
//  baek-joon 17471
//  BFS Algorithm
//
//  Created by 이정원 on 2022/11/08.
//  Copyright © 2022 이정원. All rights reserved.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <cstring>
#include <limits.h>
#include <math.h>

using namespace std;

int N;

bool isConnected(vector< vector<int >>& n, vector<int>& a, vector<int>& b){
    
    vector<int> visited(N + 1, 0);
    queue<int> q;
    int count_a = 0;
    q.push(a[0]);
    visited[a[0]] = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        count_a++;
        for(auto it : n[cur]){
            if(!visited[it] && find(a.begin(), a.end(), it) != a.end()){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    
    int count_b = 0;
    fill(visited.begin(), visited.end(), 0);
    
    q.push(b[0]);
    visited[b[0]] = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        count_b++;
        for(auto it : n[cur]){
            if(!visited[it] && find(b.begin(), b.end(), it) != b.end()){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    
    if(count_a == a.size() && count_b == b.size()) return true;
    
    return false;
}

int main(int argc, const char * argv[])
{
    int answer = 100000;

    cin >> N;
    
    vector<int> population(N + 1, 0);
    
    for(int i = 1; i <= N; i++) cin >> population[i];

    vector< vector<int> > nodes(N + 1);
    
    for(int i = 1; i <= N; i++){
        int adj_num;
        cin >> adj_num;
        
        for(int j = 0; j < adj_num; j++){
            int adj;
            cin >> adj;
            nodes[i].push_back(adj);
        }
    }
    
    for(int i = 1; i <= N / 2; i++){
        vector<bool> v(N - i, false);
        v.insert(v.end(), i, true);
        
        do{
            vector<int> A;
            vector<int> B;
            for(int j = 1; j <= N; j++){
                if(v[j - 1]) A.push_back(j);
                else B.push_back(j);
            }
            
            if(isConnected(nodes, A, B)){
                int A_sum = 0, B_sum = 0;

                for(int x = 0; x < A.size(); x++) A_sum += population[A[x]];
                for(int x = 0; x < B.size(); x++) B_sum += population[B[x]];
                
                if(abs(A_sum - B_sum) < answer) answer = abs(A_sum - B_sum);
            }
            
        } while(next_permutation(v.begin(), v.end()));
    }
    
    if(answer == 100000) answer = -1;
    cout << answer << "\n";
    
    return 0;
} 

