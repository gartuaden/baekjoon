//
//  main.cpp
//  baek-joon 17073
//
//  Created by  on 2022/11/19.
//  Copyright © 2022 . All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[])
{
    int N, W;
    double result;
    double count = 0;
    
    cin >> N >> W;
    
    vector<int> P(500001, 0);
    
    for(int i = 0; i < N - 1; i++){
        int U, V;
        cin >> U >> V;
        if(P[U] < 2) P[U]++;
        if(P[V] < 2) P[V]++;
    }
    
    for(int i = 2; i <= 500000; i++){
        if(P[i] == 1) count++;
    }
    
    cout.precision(10);
    
    result = W / count;
    
    cout << fixed << result;
    
    return 0;
}

