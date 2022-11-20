//
//  main.cpp
//  baek-joon 1339
//
//  Created by  on 2022/11/20.
//  Copyright © 2022 . All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <limits.h>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[])
{
    int N;
    
    cin >> N;
    
    vector<string> voc;
    map<char, int> voc_map;
    
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        voc.push_back(str);
        for(int j = 0; j < str.size(); j++){
            voc_map.insert({str[j], -1});
        }
    }
    
    vector<char> alphabets(int(voc_map.size()));
    int idx = 0;
    for(auto it = voc_map.begin(); it != voc_map.end(); it++){
        alphabets[idx] = it->first;
        idx++;
    }
    
    vector<int> v;
    for(int i = 10 - int(voc_map.size()); i < 10; i++) v.push_back(i);
    int max_sum = -1;
    
    do{
        int cur_sum = 0;
        int index = 0;
        for(auto it = v.begin(); it != v.end(); it++){
            voc_map[alphabets[index]] = *it;
            index++;
        }
        
        for(int i = 0; i < N; i++){
            int cur_value = 0;
            for(int j = 0; j < voc[i].size(); j++){
                cur_value *= 10;
                cur_value += voc_map[voc[i][j]];
            }
            cur_sum += cur_value;
        }
        
        if(max_sum < cur_sum) max_sum = cur_sum;
        
    }while(next_permutation(v.begin(), v.end()));
    
    
    cout << max_sum << "\n";
    
    return 0;
}
