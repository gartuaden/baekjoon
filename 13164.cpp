//
//  main.cpp
//  baek-joon 13164
//
//  Created by JungWon Lee on 2023/04/04.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

int main(int argc, const char * argv[])
{
    cin >> N >> K;
    
    vector<int> height(N, 0);
    
    for(int i = 0; i < N; i++) cin >> height[i];
    
    vector<int> diff(N - 1, 0);
    for(int i = 0; i < N - 1; i++){
        diff[i] = height[i + 1] - height[i];
    }
    
    sort(diff.begin(), diff.end());
    
    long long int answer = 0;
    
    for(int i = 0; i < N - K; i++) answer += diff[i];
    
    cout << answer << "\n";
    
    return 0;
}
