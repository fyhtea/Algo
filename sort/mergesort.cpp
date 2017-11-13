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
        void kmerge(T* x, T* tmp, int l, int m, int u);

        //for basic in-palce MergeSort        
        void naive_merge(T* x, int l, int m, int u);
        
        //improvement of naive
        void wmerge(T *x, int i, int m, int j, int n, int k;
        
    public:
        /*
         * Basic version
         */ 
        void msort(T* x, int l, int u);

        // basic in-palce merge
        void msort2(T* x, int l, int u);

        void kmsort(T* x, T* tmp, int l, int u);
        
        // wmerge
        void imsort(T* x, int l, int u);
        void wsort(T *x, int l, int u, int w);

        void msort3();

        void test(int N);
};

template<typename T> 
inline void MergeSort<T>::wsort(T *x, int l, int u, int w){
    int m;
    if(l<u-1){
        m = l+(u-l)/2;
        imsort(xs, l, m);
        imsort(xs, m, u);
        wmerge(xs, l, m, m, u, w);
    }
    else{
        while(l<u){

        }
    }
}


template<typename T>
inline void MergeSort<T>::wmerge(T *x, int i, int m, int j, int n, int k){
    while(i<m && j<n){
        if (x[i]<x[j]){
            swap(x[k], x[i]);
            i++;
        }else{
            swap(x[k], x[j]);
            j++;
        }
        k++;
    }
    while(i<m){
        swap(x[k++], x[i++]);
    }
    while(j<m){
        swap(x[k++]. x[j++])
    }
}


template<typename T>
inline void MergeSort<T>::naive_merge(T* x, int l, int m, int u){
    int i;
    T tmp;
    for(;l<m && m<u;++l){
        if(x[l]>=x[m]){
            tmp = x[m];
            for(i=m; i>l;--i){
                x[i]=x[i-1];    
            }
            x[l] = tmp;
            m++;
        }
    }
}


template<typename T>
void MergeSort<T>::msort2(T* x, int l, int u){
    int m;
    if(l<u-1){
        m = l+(u-l)/2;
        msort2(x, l, m);
        msort2(x, m, u);
        naive_merge(x, l, m, u);
    }
}

template<typename T>
inline void MergeSort<T>::kmerge(T* x, T* tmp, int l, int m, int u){
    int i,j,k;
    i=k=l; j=m;
    while(i<m && j<u){
        tmp[k++] = x[i]<x[j]? x[i++]:x[j++];
    }
    while(i<m){
        tmp[k++]=x[i++];
    }
    while(j<u){
        tmp[k++]=x[j++];
    }
    //memcpy((void*)(x),(void*)(tmp),sizeof(T)*(u));
    while(l<u){x[l]=tmp[l++];}
}

template<typename T>
inline void MergeSort<T>::kmsort(T *x, T *tmp, int l, int u){
    int m;
    if(l<u-1){
        m=l+(u-l)/2;
        kmsort(x, tmp, l, m);
        kmsort(x, tmp, m, u);
        kmerge(x, tmp, l, m, u);
    }
}


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
        int x[N],tmp[N];
        cout<<"origin sequence:";
        for(int i=0; i<N; i++){
            x[i] = Random(15);
            cout<<x[i]<<' ';
        }
        cout<<endl;
        cout<<"test for kMergeSort:"<<endl;
       // kmsort(x, tmp, 0, N);
        msort2(x, 0, N);
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
