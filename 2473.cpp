//
//  main.cpp
//  baek-joon 2473
//
//  Created by JungWon Lee on 2023/02/02.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main(int argc, const char * argv[])
{
    cin >> N;
    
    vector<long long> liquids(N);
    
    for(int i = 0; i < N; i++) cin >> liquids[i];
    
    sort(liquids.begin(), liquids.end());
    
    vector<long long> answer(3, 0);
    
    int start, end, mid;
    long long cur_min = 3000000001;
    
    for(int start = 0; start <= N - 3; start++){
        mid = start + 1;
        end = N - 1;
        while(mid < end){
            if(cur_min > abs(liquids[start] + liquids[mid] + liquids[end])){
                cur_min = abs(liquids[start] + liquids[mid] + liquids[end]);
                answer[0] = liquids[start];
                answer[1] = liquids[mid];
                answer[2] = liquids[end];
            }
            
            if(liquids[start] + liquids[mid] + liquids[end] < 0) mid++;
            else if(liquids[start] + liquids[mid] + liquids[end] > 0) end--;
            else break;
        }
    }
    
    for(int i = 0; i < 3; i++) cout << answer[i] << " ";
    cout << "\n";
  
    return 0;
}
