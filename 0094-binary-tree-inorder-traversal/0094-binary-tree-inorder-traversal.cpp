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
  vector<int>ans;
   void inorder(TreeNode*node){
        if(!node)return ;

        if(node->left)inorder(node->left);
        ans.push_back(node->val);
        if(node->right)inorder(node->right);
   }
    vector<int> inorderTraversal(TreeNode* root) {
           
              inorder(root);
              return ans;
    }
};