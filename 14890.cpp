//
//  main.cpp
//  baek-joon 14890
//
//  Created by JungWon Lee on 2022/12/09.
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

#define R 0
#define C 1

bool check_line(int idx, int rc, vector<vector<int>> roadmap, int N, int L){

    vector<int> check_road(N, 0);
    
    if(rc == R){
        for(int j = 0; j < N; j++){
            // UP
            if(j + 1 < N && roadmap[idx][j + 1] - roadmap[idx][j] == 1){
                if(j - L + 1 < 0) return false;
                for(int l = 0; l < L; l++){
                    if(check_road[j - l] || roadmap[idx][j - l] != roadmap[idx][j]) return false;
                    check_road[j - l] = 1;
                }
            }
            else if(j + 1 < N && roadmap[idx][j + 1] - roadmap[idx][j] > 1) return false;
            
            // DOWN
            if(j - 1 >= 0 && roadmap[idx][j - 1] - roadmap[idx][j] == 1){
                if(j + L - 1 >= N) return false;
                for(int l = 0; l < L; l++){
                    if(check_road[j + l] || roadmap[idx][j + l] != roadmap[idx][j]) return false;
                    check_road[j + l] = 1;
                }

            }
            else if(j - 1 >= 0 && roadmap[idx][j - 1] - roadmap[idx][j] > 1) return false;
        }
    }
    else if(rc == C){
        for(int i = 0; i < N; i++){
            // UP
            if(i + 1 < N && roadmap[i + 1][idx] - roadmap[i][idx] == 1){
                if(i - L + 1 < 0) return false;
                for(int l = 0; l < L; l++){
                    if(check_road[i - l] || roadmap[i - l][idx] != roadmap[i][idx]) return false;
                    check_road[i - l] = 1;
                }
            }
            else if(i + 1 < N && roadmap[i + 1][idx] - roadmap[i][idx] > 1) return false;
            
            // DOWN
            if(i - 1 >= 0 && roadmap[i - 1][idx] - roadmap[i][idx] == 1){
                if(i + L - 1 >= N) return false;
                for(int l = 0; l < L; l++){
                    if(check_road[i + l] || roadmap[i + l][idx] != roadmap[i][idx]) return false;
                    check_road[i + l] = 1;
                }
            }
            else if(i - 1 >= 0 && roadmap[i - 1][idx] - roadmap[i][idx] > 1) return false;
        }
    }
    
    
    return true;
}


int main(int argc, const char * argv[])
{
    int N, L;
    int answer = 0;
    
    cin >> N >> L;
    
    vector<vector<int>> roadmap(N, vector<int> (N, 0));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> roadmap[i][j];
        }
    }
    
    
    for(int i = 0; i < N; i++){
        if(check_line(i, R, roadmap, N, L)) answer++;

    }
    
    for(int j = 0; j < N; j++){
        if(check_line(j, C, roadmap, N, L)) answer++;
    }
    
    cout << answer << "\n";
    
    return 0;
}
