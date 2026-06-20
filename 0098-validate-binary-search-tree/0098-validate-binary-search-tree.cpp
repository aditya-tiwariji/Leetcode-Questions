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
bool fun(TreeNode*root,long long  min_val,long long  max_val){
               if(!root)return true;
           
                if(root->val>min_val&&root->val<max_val){
                         return fun(root->left,min_val,root->val)&&fun(root->right,root->val,max_val);
                }
                else{
                       return false;
                }
}
    bool isValidBST(TreeNode* root) {
                
                 bool ans=fun(root,LLONG_MIN,LLONG_MAX);
                 return ans;
    }
};