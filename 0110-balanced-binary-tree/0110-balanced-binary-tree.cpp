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

int  fun(TreeNode*root){
      if(!root)return 0;
      
       int left=fun(root->left);
       int right=fun(root->right);

       if(abs(left-right)>1)return -1;
       if(left==-1||right==-1)return -1;

       return 1+max(left,right);
       
}
    bool isBalanced(TreeNode* root) {
          
            if(fun(root)==-1)return false;
            return true;
    } 
};