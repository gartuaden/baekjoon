//
//  main.cpp
//  baek-joon 16120
//
//  Created by JungWon Lee on 2023/03/06.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    string input_str;
    cin >> input_str;
    string answer = "";
    int idx = 0;
    
    while(1){
        if(idx == input_str.size() || (answer == "PPAP" && idx == input_str.size())) break;
        answer += input_str[idx];
        if(int(answer.size()) - 5 >= 0){
            if(answer.substr(int(answer.size()) - 4, 4) == "PPAP"){
                for(int j = 0; j < 4; j++) answer.pop_back();
                answer += "P";
            }
        }
        idx++;
    }
    
    if(answer == "PPAP" || answer == "P") cout << "PPAP\n";
    else cout << "NP\n";
    
    return 0;
}
