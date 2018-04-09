/*************************************************************************
	> File Name: problem1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月09日 星期一 22时05分17秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    long t;
    cin>>t;
    for(int i=0;i<t;i++){
        long n,tmp;
        cin>>n;
        tmp=n;
        while(n%2==0){
            n=n>>1;
        }
        if(n==tmp){
            cout<<"No"<<endl;
        }else{
            cout<<n<<' '<<tmp/n<<endl;
        }
    }

    return 0;
}
