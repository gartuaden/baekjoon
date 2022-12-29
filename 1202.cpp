//
//  main.cpp
//  baek-joon 1202
//
//  Created by JungWon Lee on 2022/12/29.
//  Copyright © 2022 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <limits.h>
#include <climits>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    
    int N, K;
    long long answer = 0;
    
    cin >> N >> K;
    
    priority_queue<int> pq;
    vector<pair<int, int>> jewels(N);
    vector<int> bag(K);
    
    for(int i = 0; i < N; i++){
        int weight, price;
        cin >> weight >> price;
        jewels[i].first = weight;
        jewels[i].second = price;
    }
    
    for(int i = 0; i < K; i++){
        cin >> bag[i];
    }
    
    sort(jewels.begin(), jewels.end());
    sort(bag.begin(), bag.end());
    
    int idx = 0;
    
    for(int i = 0; i < K; i++){
        while(idx < N && jewels[idx].first <= bag[i]) pq.push(jewels[idx++].second);
        if(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}


