//
//  main.cpp
//  baek-joon 2251
//
//  Created by 이정원 on 2022/11/07.
//  Copyright © 2022 이정원. All rights reserved.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <limits.h>
#include <tuple>
#include <set>

using namespace std;

#define A 0
#define B 1
#define C 2

int main(int argc, const char * argv[])
{
    int A_max, B_max, C_max;
    
    cin >> A_max >> B_max >> C_max;
    
    queue<tuple<int, int, int>> qtree;
    vector<vector<int>> visited;
    
    qtree.push({0, 0, C_max});
    
    set<int> answer;
    
    while(!qtree.empty()){
        
        int cur_A = get<A>(qtree.front());
        int cur_B = get<B>(qtree.front());
        int cur_C = get<C>(qtree.front());
        
        vector<int> v;
        v.push_back(cur_A);
        v.push_back(cur_B);
        v.push_back(cur_C);
        if(find(visited.begin(), visited.end(), v) == visited.end()) {
            visited.push_back(v);
            if(cur_A == 0) answer.insert(cur_C);
        }
        else{
            qtree.pop();
            continue;
        }
        
        // A -> B
        if(cur_A + cur_B > B_max) qtree.push({cur_A + cur_B - B_max, B_max, cur_C});
        else qtree.push({0, cur_A + cur_B, cur_C});
        
        // B -> A
        if(cur_B + cur_A > A_max) qtree.push({A_max, cur_B + cur_A - A_max, cur_C});
        else qtree.push({cur_B + cur_A, 0, cur_C});
        
        // B -> C
        if(cur_B + cur_C > C_max) qtree.push({cur_A, cur_B + cur_C - C_max, C_max});
        else qtree.push({cur_A, 0, cur_B + cur_C});
        
        // C -> B
        if(cur_C + cur_B > B_max) qtree.push({cur_A, B_max, cur_C + cur_B - B_max});
        else qtree.push({cur_A, cur_C + cur_B, 0});
        
        // A -> C
        if(cur_A + cur_C > C_max) qtree.push({cur_A + cur_C - C_max, cur_B, C_max});
        else qtree.push({0, cur_B, cur_A + cur_C});
        
        // C -> A
        if(cur_C + cur_A > A_max) qtree.push({A_max, cur_B, cur_C + cur_A - A_max});
        else qtree.push({cur_C + cur_A, cur_B, 0});
       
    }
    
   
    for(auto it = answer.begin(); it != answer.end(); ++it) cout << *it << " ";
    
    return 0;

}
