/*************************************************************************
	> File Name: stack.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月21日 星期二 10时10分05秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include "stack.h"

static void PrintValue(const int nRetCode, const int nValue)
{
    if(nRetCode){
        cout<<nValue<<endl;
    }
    else{
        cout<<"error!"<<endl;
    }
}

int main(){
    CStack<int> stack;
    int nValue;
    int nRetCode;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    nRetCode = stack.top(&nValue);
    PrintValue(nRetCode, nValue);
    
    nRetCode = stack.pop(&nValue);
    PrintValue(nRetCode, nValue);

    nRetCode = stack.pop(&nValue);
    PrintValue(nRetCode, nValue);

    nRetCode = stack.pop(&nValue);
    PrintValue(nRetCode, nValue);
}
