//
//  main.cpp
//  baek-joon 1043
//
//  Created by JungWon Lee on 2023/01/26.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, T;
int people[51] = { 0, };
int party[51] = { 0, };
vector<int> nodes[51];

int main(int argc, const char * argv[])
{
    int answer = 0;
    
    cin >> N >> M;
    cin >> T;
    
    for(int i = 0; i < T; i++){
        int input;
        cin >> input;
        people[input] = 1;
    }
    
    for(int party_idx = 0; party_idx < M; party_idx++){
        int people_num;
        cin >> people_num;
        for(int j = 0; j < people_num; j++){
            int person_idx;
            cin >> person_idx;
            nodes[person_idx].push_back(party_idx);
            if(people[person_idx]) party[party_idx] = 1;
        }
    }
    
    for(int x = 0; x < N; x++){
        for(int person_i = 1; person_i <= N; person_i++){
            if(!people[person_i]){
                int flag = 0;
                for(auto party_i : nodes[person_i]) if(party[party_i]) flag = 1;
                if(flag) for(auto party_i : nodes[person_i]) party[party_i] = 1;
            }
        }
    }
    
    for(int i = 0; i < M; i++) if(!party[i]) answer++;
    cout << answer << "\n";
   
    return 0;
}
