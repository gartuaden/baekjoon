//
//  main.cpp
//  baek-joon 2042
//
//  Created by JungWon Lee on 2023/03/18.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, K;
vector<long long> seg_tree;
vector<long long> numbers;

long long init(int node, int start, int end){
    if(start == end) return seg_tree[node] = numbers[start];
    int mid = (start + end) / 2;
    
    return seg_tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

long long part_sum(int node, int start, int end, int left, int right){
    
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return seg_tree[node];
    
    int mid = (start + end) / 2;
    return part_sum(node * 2, start, mid, left, right) + part_sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, long long diff){
    if(index < start || index > end) return;
    seg_tree[node] = seg_tree[node] + diff;
    
    if(start != end){
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main(int argc, const char * argv[])
{
    vector<long long> answer;
    
    cin >> N >> M >> K;
    
    numbers.resize(N, 0);
    for(int i = 0; i < N; i++) cin >> numbers[i];
    
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));
    seg_tree.resize(tree_size, 0);
    
    init(1, 0, N - 1);
    
    for(int i = 0; i < M + K; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        
        if(a == 1){
            update(1, 0, N - 1, b - 1, c - numbers[b - 1]);
            numbers[b - 1] = c;
        }
        else if(a == 2){
            long long sum = part_sum(1, 0, N - 1, b - 1, int(c - 1));
            answer.push_back(sum);
        }
    }
    
    for(int i = 0; i < K; i++) cout << answer[i] << "\n";
    
    return 0;
}
