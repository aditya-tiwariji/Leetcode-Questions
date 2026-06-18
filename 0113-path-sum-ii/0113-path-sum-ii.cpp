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
  
  vector<vector<int>>ans;
   
   void  preorder(TreeNode*node,int target,vector<int>&v){
                   if(!node)return ;

                   v.push_back(node->val);  
                   if(!node->left&&!node->right){
                        if(target-node->val==0){
                                ans.push_back(v);
                        }
                   }

                   preorder(node->left,target-node->val,v);
                   preorder(node->right,target-node->val,v);

                   v.pop_back();
             
   }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
                vector<int>v;
               preorder(root,targetSum,v);

               return ans;
    }
};