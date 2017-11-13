/*************************************************************************
	> File Name: k-selection.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月13日 星期一 10时25分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define Random(x) (rand()%x)

template<typename T> 
class Search{
    protected:
    int partition(T *x, int l, int u);


    public:
    int top(int k, T *x, int l, int u);

    void test(int k, int N);
};

template<typename T>
inline int Search<T>::partition(T *x, int l, int u){
    int r,p=l;
    for(r=l+1;r<u;r++){
        if(x[r]<=x[p]){
            swap(x[r],x[++l]);
        }
    }
    swap(x[l],x[p]);
    return l;
}

template<typename T>
inline int Search<T>::top(int k, T *x, int l, int u){
    int p;
    if(l<u){
        p = partition(x, l, u);
        if(p-l+1==k){
            return p;
        }
        else if(k<p-l+1){
            return top(k, x, l, p);
        }else{
            return top(k-p+l-1, x, p+1, u);
        }
    }
    return -1;
}

template<typename T>
void Search<T>::test(int k, int N){
    int x[N];
    cout<<"origin sequence:";
    for(int i=0; i<N; i++){
        x[i] = Random(15);
        cout<<x[i]<<' ';
    }
    cout<<endl;
    

    cout<<"test for k-th selection:"<<endl;
    
    int index = top(k,x, 0, N);
    if(index>=0){
    cout<<"result:"<<x[index]<<endl;
    }else{
        cout<<"find failure!"<<endl;
    }
}

int main(){
    int k,N;
    cout<<"input length N:"<<endl;
    cin>>N;
    cout<<"input k:"<<endl;
    cin>>k;
    Search<int> search;
    search.test(k,N);
    return 0;
}
