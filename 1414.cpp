//
//  main.cpp
//  baek-joon 1414
//
//  Created by JungWon Lee on 2023/02/08.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int parents[101];

bool comp( const vector<int>& v1, const vector<int>& v2){
    return v1[2] < v2[2];
}

int getParent(int idx){
    if(parents[idx] == idx) return idx;
    return parents[idx] = getParent(parents[idx]);
}

bool myFind(int a, int b){
    a = getParent(a);
    b = getParent(b);
    
    if(a == b) return true;
    else return false;
}

void myUnion(int a, int b){
    a = getParent(a);
    b = getParent(b);
    
    if(a > b) parents[a] = b;
    else parents[b] = a;
}

int main(int argc, const char * argv[])
{
    int N, sum = 0, is_connected = 1;
    cin >> N;

    vector<vector<int>> costs;
    vector<int> check(N + 1);
    int total_sum = 0;
    
    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        for(int j = 0; j < N; j++){
            int cost;
            if(input[j] == '0') cost = 0;
            else if(int(input[j]) >= 97) cost = int(input[j]) - 96;
            else cost = int(input[j]) - 38;
            total_sum += cost;
            vector<int> v;
            v.push_back(i);
            v.push_back(j);
            v.push_back(cost);
            if(i != j && cost != 0) costs.push_back(v);
        }
    }
    
    sort(costs.begin(), costs.end(), comp);
    for(int i = 0; i < N; i++) parents[i] = i;
    
    for(int i = 0; i < costs.size(); i++){
        if(!myFind(costs[i][0], costs[i][1])){
            myUnion(costs[i][0], costs[i][1]);
            sum += costs[i][2];
        }
    }
    
    int cmp = getParent(0);
    for(int i = 1; i < N; i++) if(getParent(i) != cmp) is_connected = 0;
    
    if(!is_connected) cout << "-1\n";
    else cout << total_sum - sum << "\n";
    
    return 0;
}
