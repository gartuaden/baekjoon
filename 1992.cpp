//
//  main.cpp
//  baek-joon 1992
//
//  Created by JungWon Lee on 2023/01/26.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int graph[65][65] = { 0, };
string answer = "";

void quad_tree(int cur_N, int cur_i, int cur_j){
    
    if(cur_N < 1){
        answer += ")";
        return;
    }
    
    answer += "(";
    int flag = 0;
    
    for(int i = cur_i; i < cur_i + cur_N; i++){
        for(int j = cur_j; j < cur_j + cur_N; j++){
            if(graph[cur_i][cur_j] != graph[i][j]) {
                quad_tree(cur_N / 2, cur_i, cur_j);
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    
    if(!flag) answer += to_string(graph[cur_i][cur_j]);
    flag = 0;
    
    for(int i = cur_i; i < cur_i + cur_N; i++){
        for(int j = cur_j + cur_N; j < cur_j + 2 * cur_N; j++){
            if(graph[cur_i][cur_j + cur_N] != graph[i][j]) {
                quad_tree(cur_N / 2, cur_i, cur_j + cur_N);
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    
    if(!flag) answer += to_string(graph[cur_i][cur_j + cur_N]);
    flag = 0;
    
    for(int i = cur_i + cur_N; i < cur_i + 2 * cur_N; i++){
        for(int j = cur_j; j < cur_j + cur_N; j++){
            if(graph[cur_i + cur_N][cur_j] != graph[i][j]) {
                quad_tree(cur_N / 2, cur_i + cur_N, cur_j);
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    
    if(!flag) answer += to_string(graph[cur_i + cur_N][cur_j]);
    flag = 0;
    
    for(int i = cur_i + cur_N; i < cur_i + 2 * cur_N; i++){
        for(int j = cur_j + cur_N; j < cur_j + 2 * cur_N; j++){
            if(graph[cur_i + cur_N][cur_j + cur_N] != graph[i][j]) {
                quad_tree(cur_N / 2, cur_i + cur_N, cur_j + cur_N);
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    
    if(!flag) answer += to_string(graph[cur_i + cur_N][cur_j + cur_N]);
    answer += ")";
    
    return;
}

int main(int argc, const char * argv[])
{
    cin >> N;
    
    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        for(int j = 0; j < N; j++) graph[i][j] = input[j] - 48;
    }
    
    int flag = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph[0][0] != graph[i][j]) flag = 1;
        }
    }
    
    if(!flag) answer = to_string(graph[0][0]);
    else quad_tree(N / 2, 0, 0);
    
    cout << answer << "\n";
    
    return 0;
}
