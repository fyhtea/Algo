/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月27日 星期二 22时09分28秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* recursive(vector<int> pre, vector<int> vin){
       
    if(pre.empty()) return nullptr;
    
    int rootValue = pre[0];
    TreeNode* node = new TreeNode(rootValue);
        
    auto itor = find(vin.begin(), vin.end(), rootValue);
    int rootPos = distance(vin.begin(), itor);
        
    vector<int> pre_left;
    pre_left.insert(pre_left.begin(),pre.begin()+1,pre.begin()+rootPos+1);
        
    vector<int> pre_right;
    pre_right.insert(pre_right.begin(), pre.begin()+rootPos+1, pre.end());
        
    vector<int> in_left;
    in_left.insert(in_left.begin(), vin.begin(), vin.begin()+rootPos);
      
    vector<int> in_right;
    in_right.insert(in_right.begin(), vin.begin()+rootPos+1, vin.end());
        
        
    node->left = recursive(pre_left, in_left);
    node->right = recursive(pre_right, in_right);
    
    return node;
        
    
}


TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        
        if(pre.empty()) return nullptr;
        
        int rootValue = pre[0];
        TreeNode* node = new TreeNode(rootValue);
        
        auto itor = find(vin.begin(), vin.end(), rootValue);
        int rootPos = distance(vin.begin(), itor);
        
        vector<int> pre_left;
        pre_left.insert(pre_left.begin(),pre.begin()+1,pre.begin()+rootPos+1);
        
        vector<int> pre_right;
        pre_right.insert(pre_right.begin(), pre.begin()+rootPos+1, pre.end());
        
        vector<int> in_left;
        in_left.insert(in_left.begin(), vin.begin(), vin.begin()+rootPos);
        
        vector<int> in_right;
        in_right.insert(in_right.begin(), vin.begin()+rootPos+1, vin.end());
        
        
        node->left = recursive(pre_left, in_left);
        node->right = recursive(pre_right, in_right);
        
        return node;
 
    }

int main(){
    int a[8] = {1,2,4,7,3,5,6,8};
    vector<int> pre(a,a+8);

    int b[8] = {4,7,2,1,5,3,8,6};
    vector<int> vin(b,b+8);

    TreeNode *node = reConstructBinaryTree(pre, vin);

    return 0;
}
