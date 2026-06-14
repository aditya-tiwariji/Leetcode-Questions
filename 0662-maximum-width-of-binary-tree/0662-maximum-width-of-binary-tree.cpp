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
    int widthOfBinaryTree(TreeNode* root) {
                   
                      queue<pair<TreeNode*,int>>q;
                      q.push({root,0});
                      int maxi=0;
                      while(!q.empty()){
                            int n=q.size();

                             int startidx=q.front().second;
                             int endidx=q.back().second;
                             maxi=max(maxi,(endidx-startidx)+1);

                            for(int i=0;i<n;i++)
                            {
                                    TreeNode*node=q.front().first;
                                    int idx=q.front().second;
                                    q.pop();

                                    if(node->left)q.push({node->left,(long long)2*idx+1});
                                    if(node->right)q.push({node->right,(long long )2*idx+2});
                            }
                      }
                      return maxi;
    }
};