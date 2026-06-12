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
    vector<string> binaryTreePaths(TreeNode* root) {
              
                 vector<string>v;

                 queue<pair<TreeNode*,string>>q;
                 q.push({root,""});

                 while(!q.empty()){
                        int n=q.size();

                        for(int i=0;i<n;i++)
                        {
                               TreeNode*node=q.front().first;
                               string s=q.front().second;

                               q.pop();
                             
                               if(s.size()==0){
                                  s+=to_string(node->val);
                               }
                               else{
                                   s=s+"->"+to_string(node->val);
                               }

                               if(node->left)q.push({node->left,s});
                               if(node->right)q.push({node->right,s});
                               else if(!node->left&&!node->right){
                                     v.push_back(s);
                               }
                        }
                 }

                 return v;
    }
};