/*************************************************************************
	> File Name: problem2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月25日 星期日 20时00分35秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<queue>
using namespace std;

typedef pair<int,int> State;


int main(){
    int n;
    cin>>n;
    queue<pair<int , int>> que;
    map<pair<int,int>, int> mp;

    que.push(make_pair(1,1));
    mp[make_pair(1,1)] = 0;

    while(!que.empty()){
        State state = que.front();
        que.pop();

        if(state.first == n){
            printf("%d", mp[state]);
            break;
        }

        int step = mp[state];

        // using map.count(state) to decide wheither adding in the queue;

        //op1
        State tmp = state;
        tmp.second = state.first;
        tmp.first = tmp.first * 2;
        que.push(tmp);
        if(mp.find(tmp)==mp.end()){
            mp[tmp] = step + 1;  
        }else{
            mp[tmp] = step+1>mp[tmp]? mp[tmp]:step+1;
        } 

        //op2
        tmp = state;
        tmp.first = tmp.first + tmp.second;
        que.push(tmp);
        if(mp.find(tmp)==mp.end()){
            mp[tmp] = step +1;
        }else{
            mp[tmp] = step+1?mp[tmp]: step+1;
        }
    }
    return 0;

}
