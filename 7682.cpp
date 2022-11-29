//
//  main.cpp
//  baek-joon 7682
//
//  Created by JungWon Lee on 2022/11/29.
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

string input_str = "";

unsigned int bingo[8] = { 0b111000000, 0b000111000, 0b000000111,
                  0b100100100, 0b010010010, 0b001001001,
                  0b100010001, 0b001010100 };
unsigned int x_bit = 0;
unsigned int o_bit = 0;
bool bingo_x = false;
bool bingo_o = false;

void check(){
    for(int i = 0; i < 8; i++){
        if((int)(x_bit & bingo[i]) == bingo[i]) bingo_x = true;
        if((int)(o_bit & bingo[i]) == bingo[i]) bingo_o = true;
    }
}

void create_bit(){
    // X
    for(int i = 0; i < input_str.size(); i++){
        if(input_str[i] == 'X'){
            x_bit = x_bit << 1;
            x_bit += 1;
        }
        else x_bit = x_bit << 1;
    }
    
    // O
    for(int i = 0; i < input_str.size(); i++){
        if(input_str[i] == 'O'){
            o_bit = o_bit << 1;
            o_bit += 1;
        }
        else o_bit = o_bit << 1;
    }
}

int main(int argc, const char * argv[])
{
    vector<string> answer;
    int o = 0, x = 0;
    string result = "invalid";
    
    while(1){
        cin >> input_str;
        if(input_str == "end") break;
        
        for(int i = 0; i < input_str.size(); i++){
            if(input_str[i] == 'O') o++;
            else if(input_str[i] == 'X') x++;
        }
        
        create_bit();
        check();
        if(x == 5 && o == 4){
            if(bingo_x && !bingo_o) result = "valid";
            if(!bingo_x && !bingo_o) result = "valid";
        }
        if(x == o && x != 0){
            if(!bingo_x && bingo_o) result = "valid";
        }
        if(x - o == 1 && x < 5 && o < 4){
            if(bingo_x && !bingo_o) result = "valid";
        }
        
        answer.push_back(result);
        
        input_str = "";
        result = "invalid";
        o_bit = 0;
        x_bit = 0;
        o = 0;
        x = 0;
        bingo_x = false;
        bingo_o = false;
    }
    
    for(int i = 0; i < answer.size(); i++) cout << answer[i] << "\n";
    
    return 0;
}
