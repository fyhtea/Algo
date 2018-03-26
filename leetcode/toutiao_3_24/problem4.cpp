/*************************************************************************
	> File Name: problem4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月26日 星期一 10时06分15秒
 ************************************************************************/

#include<iostream>
#include<set>
#include<stdio.h>
using namespace std;

float compute_mean(set<int> set_in){
    auto set_it = set_in.cbegin();
    float sum=0;
    while(set_it!=set_in.cend()){
        sum += *set_it;
        ++set_it;
    }
    return sum/(set_in.size());
}

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int tmp;
    set<int> set_small;
    set<int> set_large;
    for(int i=0;i<m;i++){
        scanf("%d", &tmp);
        //printf("%d",tmp);
        set_small.insert(tmp);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &tmp);
        set_large.insert(tmp);
    }

    float mean1 = compute_mean(set_small);
    float mean2 = compute_mean(set_large);

    //auto it1 = set_large.begin();

    bool flag = true;
    bool flag2 = false;
    int count = 0;
    while(flag){
        auto it1 = set_large.begin();
        while(it1!=set_large.end() && *it1<mean2){
            if(*it1>mean1 && !set_small.count(*it1)){
                set_small.insert(*it1);
                set_large.erase(it1);
                mean1 = compute_mean(set_small);
                mean2 = compute_mean(set_large);
                flag2 = true;
                it1++;
                count++;
                break;
            }else{
                it1++;
            }
        }
        flag = flag2==true? true:false;
        flag2 = false;
    }

    printf("%d",count);
    return 0;
}

