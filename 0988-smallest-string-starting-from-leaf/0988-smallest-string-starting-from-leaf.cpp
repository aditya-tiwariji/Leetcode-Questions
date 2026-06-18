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
   string ms="";
    void preorder(TreeNode*node,string s){
              if(!node)return ;

               s=char('a'+node->val)+s;
              if(!node->left && !node->right){
                     if(ms.empty())ms=s;
                     else {
                          if(s<ms)ms=s;
                     }
                     return ;

              }
               
                preorder(node->left,s);
                preorder(node->right,s);

               
    }
    string smallestFromLeaf(TreeNode* root) {
        
              string s="";
             preorder(root,s);

             return ms;
    }
};