//
//  main.cpp
//  baek-joon 2388
//
//  Created by JungWon Lee on 2023/02/15.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, const char * argv[])
{
    int N, M;
    cin >> N >> M;
    
    vector<int> front(N + 1, 0);
    vector<int> side(M + 1, 0);
    
    for(int i = 0; i < N; i++) cin >> front[i];
    for(int i = 0; i < M; i++) cin >> side[i];
    
    sort(front.begin(), front.end(), greater<>());
    sort(side.begin(), side.end(), greater<>());
    
    int i = 0, j = 0;
    int min_sum = 0, max_sum = 0, cnt = 0;
    
    if(front[0] != side[0]){
        cout << "-1\n";
        return 0;
    }
    
    while(1){
        if(i == N && j == M) break;
        if(front[i] == side[j]){
            min_sum += front[i];
            if(i < N) i++;
            if(j < M) j++;
        }
        else if(front[i] > side[j]){
            min_sum += front[i];
            if(i < N) i++;
        }
        else if(front[i] < side[j]){
            min_sum += side[j];
            if(j < M) j++;
        }
    }

    i = 0;
    j = 0;
    
    while(1){
        if(i == N && j == M) break;
        if(front[i] == side[j]){
            cnt = (i + 1) * (j + 1) - i * j;
            max_sum += cnt * front[i];
            if(i < N) i++;
            if(j < M) j++;
        }
        else if(front[i] > side[j]){
            cnt = j;
            max_sum += front[i] * cnt;
            if(i < N) i++;
        }
        else if(front[i] < side[j]){
            cnt = i;
            max_sum += side[j] * cnt;
            if(j < M) j++;
        }
    }
    
    cout << min_sum << " " << max_sum << "\n";
    
    return 0;
}
