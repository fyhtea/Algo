/*************************************************************************
	> File Name: dfs.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月16日 星期四 10时47分09秒
 ************************************************************************/

#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
#include<stack>
using namespace std;




typedef vector<int> State;
typedef list<State> Steps;
typedef list<Steps> Moves;



Steps pop(Moves& stack){
    Steps top = stack.front();
    stack.pop_front();
    return top;
}


Steps append(Steps steps, State s){
    steps.push_back(s);
    return steps;
}

State swap(State s, int i, int j){
    swap(s[i], s[j]);
    return s;
}


list<State> moves(State s){
    list<State> ms;

    int n=s.size(), p=find(s.begin(), s.end(), 0) - s.begin();

    if(p<n-2 && s[p+2] > 0){
        ms.push_back(swap(s, p, p+2));   //leap left  
    }
    if(p<n-1 && s[p+1] > 0){
        ms.push_back(swap(s, p, p+1));   //hop left    
    }
    if(p>1 && s[p-2]<0){
        ms.push_back(swap(s, p, p-2));   //leap right
    }
    if(p>1 && s[p-1]<0){
        ms.push_back(swap(s, p, p-1));
    }
    return ms;
}


Moves solve(State start, State end){
    Moves s, stack(1, Steps(1,start));
    while(!stack.empty()){
        Steps cur = pop(stack);
        if(cur.back()==end){
            s.push_back(cur);
        }
        else{
            list<State> attemps = moves(cur.back());
            list<State>::iterator it;
            for(it=attemps.begin();it!=attemps.end();it++){
                stack.push_front(append(cur, *it));
            }
        }
    }
    return s;
}

void print_line(State s) {
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, ", "));
    cout<<"\n";
}

void print(Moves s) {
    int i, n;
    Moves::iterator itm;
    Steps::iterator its;
    for (n = 0, itm = s.begin(); itm != s.end(); ++itm, ++n) {
        cout<<"solution "<< n + 1<<":\n";
        for (i = 0, its = itm->begin(); its != itm->end(); ++its, ++i)
            print_line(*its);
        cout<<"total "<<i - 1<<" steps.\n\n";
    }
    cout<<"total "<<n<<" solutions.\n";
}

void test() {
    for (int i = 1; i < 6; ++i) {
        State from(2*i+1, 0), to(2*i+1, 0);
        for(int j = 0; j < i; ++j) {
            from[j] = to[j+i+1] = -1;
            to[j] = from[j+i+1] = 1;
        }
        print(solve(from, to));
    }
}

int main(int argc, char** argv) {
    test();
    return 0;
}
