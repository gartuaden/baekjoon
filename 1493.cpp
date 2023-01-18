//
//  main.cpp
//  baek-joon 1493
//
//  Created by JungWon Lee on 2023/01/18.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int answer = 0, fail = 0;
int box_board[21] = { 0, };

vector<pair<int, int>> boxes;

void divide(int l, int w, int h, int box_idx){
    if(l == 0 || w == 0 || h == 0) return;

    for(int i = box_idx; i < boxes.size(); i++){
        int b = boxes[i].first;
        if(boxes[i].second != 0 && b <= l && b <= w && b <= h){
            boxes[i].second--;
            answer++;
            divide(l, w, h - b, i);
            divide(l - b, b, b, i);
            divide(l, w - b, b, i);
            return;
        }
    }
    
    fail = 1;
}

int main(int argc, const char * argv[])
{
    int length, width, height;
    
    cin >> length >> width >> height;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        box_board[a] += b;
    }
    
    for(int i = 19; i >= 0; i--){
        if(box_board[i] != 0) boxes.push_back({pow(2, i), box_board[i]});
    }
    
    divide(length, width, height, 0);
    
    if(fail) cout << "-1\n";
    else cout << answer << "\n";
    
    return 0;
}
