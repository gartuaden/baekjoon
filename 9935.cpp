//
//  main.cpp
//  baek-joon 9935
//
//  Created by JungWon Lee on 2023/02/09.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    string str, exp_str;
    cin >> str;
    cin >> exp_str;
    
    int exp_idx = int(exp_str.size()) - 1;
    int str_size = 0;
    string answer = "";
    
    for(int i = 0; i < str.size(); i++){
        answer += str[i];
        
        if(answer[answer.size() - 1] == exp_str[exp_idx]){
            if(answer.size() >= exp_str.size()){
                int cnt = 1;
                for(int j = exp_idx - 1; j >= 0; j--){
                    if(answer[answer.size() - (exp_idx - j) - 1] == exp_str[j]) cnt++;
                }
                
                if(exp_str.size() == cnt){
                    for(int e = 0; e < exp_str.size(); e++) answer.pop_back();
                }
            }
        }
    }
   
    if(answer.size() > 0) cout << answer << "\n";
    else cout << "FRULA\n";
    
    return 0;
}
