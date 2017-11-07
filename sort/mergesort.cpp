/*************************************************************************
	> File Name: mergesort.cpp
	> Author:    fyhtea
	> Mail:      ~
	> Created Time: 2017年11月07日 星期二 10时21分15秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

#define Random(x) (rand() % x)
#define NN  100000
#define INF NN + 1

template<typename T> class MergeSort{
    private:

    public:
        /*
         * Basic version
         */ 
        void msort(T* x, int l, int u);


        void test(int N);
};

template<typename T>
inline void MergeSort<T>::msort(T* xs, int l, int u){
    int i, j, m;
    T *as, *bs;
    if(l<u-1){
        m = l + (u-l)/2;
        msort(xs, l, m);
        msort(xs, m, u);

        as = (T*) malloc(sizeof(T) * (m-l+1));
        bs = (T*) malloc(sizeof(T) * (u-m+1));
        memcpy((void*)as, (void*)(xs+l), sizeof(T)*(m-l));
        memcpy((void*)bs, (void*)(xs+m), sizeof(T)*(u-m));
        as[m-l]=bs[u-m]=INF;
        for(i=j=0;l<u;++l){
            xs[l]=as[i]<bs[j]?as[i++]:bs[j++];
        }
        free(as);
        free(bs);
    }
}

template<typename T>
    void MergeSort<T>::test(int N){
        int x[N];
        cout<<"origin sequence:";
        for(int i=0; i<N; i++){
            x[i] = Random(15);
            cout<<x[i]<<' ';
        }
        cout<<endl;
        cout<<"test for MergeSort:"<<endl;
        msort(x, 0, N);
        for(int j:x){
            cout<<j<<' ';
        }
        cout<<endl;
    }

int main(){
    int N;
    cin>>N;
    MergeSort<int> sort;
    sort.test(N);
    return 0;
}