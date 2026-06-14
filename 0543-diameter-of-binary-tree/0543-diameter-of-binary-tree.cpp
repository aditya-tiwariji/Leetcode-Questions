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
int maxi=0;

int fun(TreeNode*root){
            if(!root)return 0;

                   int left=0;
             
                   if(root->left){
                      left=fun(root->left);
                   }

                   int right=0;
                   if(root->right){
                      right=fun(root->right);
                   }
                   maxi=max(maxi,left+right);  
                   return 1+max(left,right);

                 
}
    int diameterOfBinaryTree(TreeNode* root) {
        
                 int ans=fun(root);
                 return maxi;
    }
};