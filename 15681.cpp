//
//  main.cpp
//  baek-joon 15681
//
//  Created by JungWon Lee on 2023/02/24.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, R, Q;
int num[100001] = { 0, };
int visited[100001] = { 0, };
vector<int> nodes[100001];

int dfs(int n){
    if(num[n] != 0) return num[n];
    visited[n] = 1;
    int ret = 1;
    for(auto it : nodes[n]){
        if(!visited[it]){
            ret += dfs(it);
        }
    }
    num[n] = ret;
    return ret;
}

int main(int argc, const char * argv[])
{
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> R >> Q;
    
    vector<int> queries;
    
    for(int i = 0; i < N - 1; i++){
        int U, V;
        cin >> U >> V;
        nodes[U].push_back(V);
        nodes[V].push_back(U);
    }
    
    num[R] = dfs(R);
    
    for(int i = 0; i < Q; i++){
        int q;
        cin >> q;
        queries.push_back(q);
    }

    for(int i = 0; i < Q; i++){
        cout << num[queries[i]] << "\n";
    }
    
    return 0;
}
