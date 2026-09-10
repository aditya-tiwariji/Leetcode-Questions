/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int cnt=0;


pair<int,int> fun(TreeNode*root){
           if(!root)return {0,0};

           pair<int,int>left=fun(root->left);
           pair<int,int>right=fun(root->right);

           int n=1+left.first+right.first;
           int sum=root->val+left.second+right.second;

           int avg=sum/n;

           if(root->val==avg)cnt++;
         
           
           return {1+left.first+right.first,root->val+left.second+right.second};
}
    int averageOfSubtree(TreeNode* root) {
        
             pair<int,int>p=fun(root);
             return cnt;
            

    }
};