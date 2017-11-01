/////////////////////////////////////////////////////
//
// FileName	:	sort.h
// Version 	:	0.10
// Author	:	fyhtea
// Date 	:	2017.11.1
// Comment	:	Implementation of sort algorithm
/////////////////////////////////////////////////////



#include <iostream>

using namespace std;

#define Random(x) (rand() % x)

template<typename T>class Sort
{
  private:
  //T* xs;
  int partition(T* xs, int l, int u);
  public:
  void quicksort(T* xs, int l, int u);
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
inline void Sort<T>::quicksort(T* xs, int l, int u)
{
  int m;
  if(l < u){
     m=partition(xs, l, u);
     quicksort(xs, l, m-1);
     quicksort(xs, m, u);
  }
}                                 

int main()
{
  int x[6];
  for(int i=0;i<6;i++){
    x[i] = Random(11);
    cout<<x[i]<<' ';
  }
  cout<<endl;
  Sort<int> sort;
  sort.quicksort(x,0,6);
  for(int j:x){
    cout<<j<<' ';
  }  
  cout<<endl;
  return 0;
}            
