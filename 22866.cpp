//
//  main.cpp
//  baek-joon 22866
//
//  Created by 이정원 on 2022/11/18.
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

int main(int argc, const char * argv[])
{
    int N;
    
    cin >> N;
    
    vector<int> L(N + 2);
    vector<vector<int>> tp(N + 2, vector<int>(2, 0));
    
    for(int i = 0; i < N; i++) cin >> L[i + 1];

    stack<pair<int, int>> st;
    
    for(int i = 1; i <= N; i++){
        while(!st.empty() && st.top().first <= L[i]) st.pop();
        
        tp[i][0] += st.size();
        if(!st.empty()) tp[i][1] = st.top().second;

        st.push({L[i], i});
    }
    
    while(!st.empty()) st.pop();
    
    for(int i = N; i >= 1; i--){
        while(!st.empty() && st.top().first <= L[i]) st.pop();
      
        tp[i][0] += st.size();
        if(!st.empty()){
            if(tp[i][1] == 0) tp[i][1] = st.top().second;
            else{
                if(abs(tp[i][1] - i) > abs(st.top().second - i)) tp[i][1] = st.top().second;
            }
        }
        
        st.push({L[i], i});
    }
    
    for(int i = 1; i <= N; i++){
        if(!tp[i][0]) cout << "0\n";
        else cout << tp[i][0] << " " << tp[i][1] << "\n";
    }
    
    return 0;
}
