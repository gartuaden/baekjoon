//
//  main.cpp
//  baek-joon 1305
//
//  Created by JungWon Lee on 2022/11/30.
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

vector<int> KMP(string str, int L){
    
    vector<int> table(L, 0);

    int j = 0;
    for(int i = 1; i < L; i++){
        while(j > 0 && str[i] != str[j]) j = table[j - 1];
        if(str[i] == str[j]) table[i] = ++j;
    }
    
    return table;
}


int main(int argc, const char * argv[])
{
    int L;
    string input_str;
    
    cin >> L;
    cin >> input_str;
    
    auto result = KMP(input_str, L);

    cout << L - result[L - 1] << "\n";
        
    return 0;
}
