/******************************************************
 *
 * FileName	:	sort.h
 * Version 	:	0.10
 *  Author	:	fyhtea
 * Date 	:	2017.11.1
 * Comment	:	Implementation of sort algorithm
 *
******************************************************/

#include <iostream>

using namespace std;

#define Random(x) (rand() % x)

template<typename T>class Sort
{
  private:
  /*
  * Nico Lumuto parition algorithms. 
  */
  int partition(T* xs, int l, int u);
  int partition2(T* xs, int l, int u);
 
  public:
  void quicksort(T* xs, int l, int u);
   
  /*
  * Robert Sedgewick parition algorithms. 
  */
  void quicksort2(T* xs, int l, int u);
  
  /*
   * 3-way partition
  */ 
  void quicksort3(T* xs, int l, int u);

  /*
   * Another 3-way partition tenery quick sort based on N. Lomuto's method
   */
  void quicksort33(T* xs, int l, int u);
  /*
   * test
   */
  void test(int N);
};

template<typename T> 
inline int Sort<T>::partition(T* xs, int l, int u)
{
  int r,pivot=l;
  for (r=l+1;r<u;++r){
    if(!(xs[pivot]<xs[r])){
      ++l;
      swap(xs[l],xs[r]);  
    }
  }
  swap(xs[pivot], xs[l]);
  return l+1;
}

template<typename T>
inline int Sort<T>::partition2(T* xs, int l, int u)
{
  int i=l,j=u,pivot=l;

  while(1){
    while(i<u && xs[++i]<xs[pivot]);
    while(j>=l && xs[--j]>xs[pivot]);
    if(i<j){
      swap(xs[i],xs[j]);
    }else{
      break;
    }
  }

  swap(xs[pivot],xs[j]);
  return j+1;
}
template<typename T>
inline void Sort<T>::quicksort(T* xs, int l, int u)
{
  int m;
  if(l < u){
     m=partition2(xs, l, u);
     quicksort(xs, l, m-1);
     quicksort(xs, m, u);
  }
}                                 


template<typename T>
inline void Sort<T>::quicksort2(T* xs, int l, int u)
{
  int i,j,pivot;
  if(l<u-1){
    pivot=i=l;
    j=u;
    while(1){
      while(i<u && xs[++i]<xs[pivot]);
      while(j>=l && xs[pivot]<xs[--j]);
      if(j<i) break;
      swap(xs[i], xs[j]);
  }
  swap(xs[pivot], xs[j]);
  quicksort2(xs, l, j);
  quicksort2(xs, i, u);
  }
}

template<typename T>
inline void Sort<T>::quicksort3(T* xs, int l, int u)
{
    int i, j, k, p, q, pivot;
    if(l<u-1){
        i = p = l;
        j = q = u;
        pivot = l;
        while(1){
            while(i<u && xs[++i]<xs[pivot]);
            while(j>=l && xs[pivot]<xs[--j]);
            if(j<=i) break;
            swap(xs[i],xs[j]);
            if(xs[i]==xs[pivot]){++p; swap(xs[p], xs[i]);}
            if(xs[j]==xs[pivot]){--q; swap(xs[q], xs[j]);}
        }
        if(i==j && xs[i] == xs[pivot]){ --j, ++i; } //special case
        for(k=l; k <= p; ++k,--j){swap(xs[k], xs[j]);}
        for(k=u-1; k >= q; --k,++i){swap(xs[k],xs[i]);}
        quicksort3(xs, l, j+1);
        quicksort3(xs, i, u );
    }
}

template<typename T>
inline void Sort<T>::quicksort33(T* xs, int l, int u){
    int i, j, k;
    T pivot;
    if(l<u-1){
        i=l;j=u;pivot=xs[l];
        for(k=l+1;k<j;++k){
            while(pivot<xs[k]){--j;swap(xs[j],xs[k]);}
            if(xs[k]<pivot){swap(xs[i], xs[k]);++i;}
        }
        quicksort33(xs, l, i);
        quicksort33(xs, j, u);
    }
}

template<typename T>
    void Sort<T>::test(int N){
        int x[N];
        cout<<"origin sequence:";
        for(int i=0; i<N; i++){
            x[i] = Random(15);
            cout<<x[i]<<' ';
        }
        cout<<endl;
        cout<<"test for 3-way partition:"<<endl;
        quicksort33(x, 0, N);
        for(int j:x){
            cout<<j<<' ';
        }
        cout<<endl;
    }

int main()
{   
  int N;
  cin>>N;
 /* int x[N];
  for(int i=0;i<N;i++){
    x[i] = Random(11);
    cout<<x[i]<<' ';
  }
  cout<<endl;
  Sort<int> sort;
  sort.quicksort(x,0,N);
  for(int j:x){
    cout<<j<<' ';
  }
  cout<<endl;*/
  Sort<int> sort;
  sort.test(N);
  return 0;
}            
