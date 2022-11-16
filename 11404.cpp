//
//  main.cpp
//  baek-joon 11404
//
//  Created by 이정원 on 2022/11/14.
//  Copyright © 2022 이정원. All rights reserved.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <math.h>

using namespace std;

#define INF 1000000000

int main(int argc, const char * argv[])
{
    int n, m;
    
    cin >> n;
    cin >> m;
    
    int city[n + 2][n + 2];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) city[i][j] = 0;
            else city[i][j] = INF;
        }
    }
    
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(city[a][b] == INF) city[a][b] = c;
        else{
            if(city[a][b] > c) city[a][b] = c;
        }
    }
    
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(city[i][k] + city[k][j] < city[i][j]) city[i][j] = city[i][k] + city[k][j];
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(city[i][j] == INF) {
                cout << "0 ";
            }
            else cout << city[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

