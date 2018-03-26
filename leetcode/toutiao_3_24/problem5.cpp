/*************************************************************************
	> File Name: problem5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月26日 星期一 10时53分59秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>

using namespace std;

int main(){
    int n,h,k;
    cin>>n>>k>>h;
    int stair_tmp;
    vector<int> stairs;
    for(int i=0;i<n;i++){
        cin>>stair_tmp;
        stairs.push_back(stair_tmp);
    }

    queue<pair<int,int> > que;
    que.push(make_pair(0,0));
    int stair = 0;
    int max = 0;
    while(!que.empty()){
        
        pair<int,int> cur_h = que.front();
        que.pop();

        cout<<'('<<cur_h.first<<cur_h.second<<')'<<endl;
        if(cur_h.second==k){
            max = cur_h.first>max? cur_h.first:max;
        }

        for(stair=cur_h.second;stair<n;stair++){
            if(stairs[stair]<=cur_h.first+h){
                que.push(make_pair(2*stairs[stair]-cur_h.first,cur_h.second+1));
            }else{
                break;
            }
        }
    
    }
    cout<<max<<endl;
    return 0;
}

