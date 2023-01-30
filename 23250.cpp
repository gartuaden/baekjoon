//
//  main.cpp
//  baek-joon 23250
//
//  Created by JungWon Lee on 2023/01/31.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;

unsigned long long pow(int x){
    unsigned long long result = 1;
        for (int i = 0; i < x; i++) result *= 2;
    return result;
}

int main(int argc, const char * argv[])
{
    int N, A, B;
    unsigned long long K, std, sstd;
    int cnt = 0;
    int from = 1, to = 3, mid = 2;
    
    cin >> N >> K;
    
    std = pow(N - 1);
    sstd = std / 2;
    
    while(1){
        if(std == K){
            A = from;
            B = to;
            break;
        }
        else if(std > K){
            cnt = to;
            to = mid;
            mid = cnt;
            std -= sstd;
        }
        else if(std < K){
            cnt = from;
            from = mid;
            mid = cnt;
            std += sstd;
        }
        sstd /= 2;
    }
    
    cout << A << " " << B << "\n";
   
    return 0;
}
