//
//  main.cpp
//  baek-joon 9241
//
//  Created by JungWon Lee on 2023/02/13.
//  Copyright © 2023 JungWon Lee. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, const char * argv[])
{
    string DNA1, DNA2;
    cin >> DNA1;
    cin >> DNA2;
    
    deque<string> org;
    deque<string> chg;
    
    for(int i = 0; i < DNA1.size(); i++) org.push_back(DNA1.substr(i, 1));
    for(int i = 0; i < DNA2.size(); i++) chg.push_back(DNA2.substr(i, 1));
    
    if(DNA1 == DNA2){
        cout << "0\n";
        return 0;
    }
    
    while(1){
        if(org.size() == 0){
            cout << chg.size() << "\n";
            return 0;
        }
        
        if(chg.size() == 0) break;
        
        bool flag = true;
        if(org.front() == chg.front()){
            org.pop_front();
            chg.pop_front();
            flag = false;
        }
        
        if(org.size() == 0){
            cout << chg.size() << "\n";
            return 0;
        }
        
        if(chg.size() == 0) break;
        
        if(org.back() == chg.back()){
            org.pop_back();
            chg.pop_back();
            flag = false;
        }
        
        if(flag) break;
    }
    
    cout << chg.size() << "\n";
    
    return 0;
}
