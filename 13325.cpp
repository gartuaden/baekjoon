//
//  main.cpp
//  baek-joon 13325
//
//  Created by JungWon Lee on 2023/05/05.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int k;
int tree_size;
int answer = 0;
int arr[1 << 21];

int DFS(int idx){
    
    if(idx * 2 >= tree_size){
        answer += arr[idx];
        return arr[idx];
    }
    else{
        int left = DFS(idx * 2);
        int right = DFS(idx * 2 + 1);
        answer += arr[idx] + abs(left - right);
        return arr[idx] + max(left, right);
    }
    
}

int main(int argc, const char * argv[])
{
    cin >> k;
    
    tree_size = 1 << (k + 1);
    for(int i = 2; i < tree_size; i++) cin >> arr[i];
    
    DFS(1);
    
    cout << answer << "\n";
    
    return 0;
}
