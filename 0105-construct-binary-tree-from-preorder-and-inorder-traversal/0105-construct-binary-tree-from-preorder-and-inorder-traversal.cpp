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
   unordered_map<int,int>mpp;

TreeNode* fun(int preStart,int preEnd,int inStart,int inEnd,vector<int>& preorder, vector<int>& inorder){
                        if(inEnd<inStart||preEnd<preStart)return NULL;

                     TreeNode*root=new TreeNode(preorder[preStart]);
                     int x=mpp[root->val]-inStart;
                     root->left=fun(preStart+1,preStart+x,inStart,mpp[root->val]-1,preorder,inorder);
                     root->right=fun(preStart+x+1,preEnd,mpp[root->val]+1,inEnd,preorder,inorder);

                     return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          
             for(int i=0;i<inorder.size();i++)mpp[inorder[i]]=i;

             TreeNode*root=fun(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder);
             return root;
    }
};