#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <set>
#include <queue>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int calculate(int M, vector < string > strs) {
	vector<vector <pair<int, int> > > graph(5);
    for(auto str:strs){
        int source, dest;
        switch(str[0]){
                case 'A':
                    source=0;
                    break;
                case 'B':
                    source=1;
                    break;
                case 'C':
                    source=2;
                    break;
                case 'D':
                    source=3;
                    break;
                case 'E':
                    source=4;
                    break;
            }
	//cout<<"source:"<<source<<endl;
    	for(int i=1;i+1<str.size();i=i+2){
        	int dist = str[i]-48;
	//	cout<<str[i]<<endl;            
            switch(str[i+1]){
                case 'A':
                    dest=0;
                    break;
                case 'B':
                    dest=1;
                    break;
                case 'C':
                    dest=2;
                    break;
                case 'D':
                    dest=3;
                    break;
                case 'E':
                    dest=4;
                    break;
            }
            cout<<"source:"<<source<<"dist："<<dist<<"dest:"<<dest<<endl;
            graph[source].push_back(make_pair(dest, dist));
            source = dest;
            
        }
    }

    //set<int> reached;
    //queue<pair<int,int> > bfs;
    int max_dist=0;
    for(int i=0;i<graph.size();i++){
    	set<int> reached;
    	queue<pair<int,int> > bfs;
        bfs.push(make_pair(i,0));
        reached.insert(i);
        while(!bfs.empty()){
        	pair<int,int> state = bfs.front();
            bfs.pop();
            
            int s = state.first;
            int d = state.second;
            for(auto vec:graph[s]){
            	if(reached.count(vec.first)){
                	return -1;
                }else{
                	bfs.push(make_pair(vec.first,d+vec.second));
                    max_dist=max_dist>d+vec.second? max_dist:d+vec.second;
                }
            }
        	
            
        }
    }
    
    return max_dist;
}
/******************************结束写代码******************************/


int main() {
    int res;

    int _M;
    cin >> _M;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _strs_size = _M;
    vector<string> _strs;
    string _strs_item;
    for(int _strs_i=0; _strs_i<_strs_size; _strs_i++) {
        getline(cin, _strs_item);
        _strs.push_back(_strs_item);
    }
    
    res = calculate(_M, _strs);
    cout << res << endl;
    
    return 0;

}
