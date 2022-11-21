//
//  main.cpp
//  baek-joon 1756
//
//  Created by JungWon Lee on 2022/11/20.
//  Copyright © 2022 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[])
{
    int D, N;
    
    cin >> D >> N;
    
    vector<int> oven(D);
    vector<int> doughs(N);
    
    for(int i = 0; i < D; i++) cin >> oven[i];
    for(int i = 0; i < N; i++) cin >> doughs[i];
    
    int cur_min = oven[0];
    
    if(doughs[0] > cur_min){
        cout << 0;
        return 0;
    }
    
    for(int i = 0; i < D; i++){
        if(oven[i] > cur_min) oven[i] = cur_min;
        else cur_min = oven[i];
    }
    
    int left = 0, right = D, mid = 0;
    
    for(int i = 0; i < N; i++){
        
        while(left < right){
            mid = (left + right) / 2;
            if(oven[mid] < doughs[i]) right = mid;
            else left = mid + 1;
        }
        
        right--;
        left = 0;
        if(right < 0) break;
    }
    
    cout << right + 1;
    
    return 0;
}
