/*************************************************************************
	> File Name: insertsort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月14日 星期二 20时03分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define Random(x) (rand() % x)

template<typename T>
class InsertSort{
    
public:
    void insertsort(T *x, int n);    
    void test(int n);
};

template<typename T>
inline void InsertSort<T>::insertsort(T *x, int n){
    for(int i=1; i<n; i++){
        for(int j=i; (j>0)&&(x[j]<x[j-1]); j--){
            swap(x[j], x[j-1]);
        }
    }
}

template<typename T>
inline void InsertSort<T>::test(int n){
    int x[n];
    cout<<"origin sequence:";
    for(int i=0; i<n; i++){
        x[i] = Random(15);
        cout<<x[i]<<' ';
    }
    cout<<endl;
    cout<<"test for insertsort:"<<endl;
    insertsort(x, n);
    for(int j:x){
       cout<<j<<' ';
    }
    cout<<endl;
}

int main()
{   
  int N;
  cin>>N;
  InsertSort<int> sort;
  sort.test(N);
  return 0;
}    
