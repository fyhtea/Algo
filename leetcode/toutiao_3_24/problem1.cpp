/*************************************************************************
	> File Name: problem1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月25日 星期日 19时24分44秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6+7;
int a[N];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    sort(a, a+n);
    n = unique(a, a+n)-a;

    int j=0;
    int count = 0;
    for(int i=0;i<n;i++){
        j=i+1;
        while(a[j]-a[i]<k && j<n) j++;
        if(a[j]-a[i]==k && j<n) count++;
    }
    
    printf("%d", count);

    return 0;

}

