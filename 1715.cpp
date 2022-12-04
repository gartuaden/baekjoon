//
//  main.cpp
//  baek-joon 1715
//
//  Created by JungWon Lee on 2022/12/04.
//  Copyright © 2022 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <climits>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    int N;
    int cmp_num = 0;
    int total = 0;
    
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        pq.push(input);
    }
    
    if(N == 1) total = 0;
    else{
        while(!pq.empty()){
            cmp_num += pq.top();
            pq.pop();
            cmp_num += pq.top();
            pq.pop();
            total += cmp_num;
            if(pq.empty()) break;
            pq.push(cmp_num);
            cmp_num = 0;
        }
    }
    cout << total << "\n";
    
    return 0;
}
