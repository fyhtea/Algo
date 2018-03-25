/*************************************************************************
	> File Name: problem3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月25日 星期日 20时47分29秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int calculate(string &s){

    vector<char> stk;
    int op1,op2,res;

    for(size_t i=0;i<s.length();i++){
        
        if(s.at(i) == '*'){
            op1 = stk.back()-'0';
            stk.pop_back();
            op2 = s.at(i+1)-'0';
            res = op1 * op2;
            stk.push_back((char)res+'0');
            i = i+1;
        }else{
            stk.push_back(s.at(i));
        }
    }

    res = stk[0]-'0';
    for(int i =1;i<stk.size();i++){
        
    
        switch(stk[i]){
            case '+':
                res+=(stk[++i]-'0');
                break;
            case '-':
                res-=(stk[++i]-'0');
                break;
        }
    }
    return res;
}

int main(){
    string input = "1+9*2*2*6+2";
    int res = calculate(input);

    printf("%d", res);
}
