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
      while(j>=1 && xs[pivot]<xs[--j]);
      if(j<i) break;
      swap(xs[i], xs[j]);
  }
  swap(xs[pivot], xs[j]);
  quicksort2(xs, l, j);
  quicksort2(xs, i, u);
  }
}


int main()
{ 
  int N;
  cin>>N;
  int x[N];
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
  cout<<endl;
  return 0;
}            
