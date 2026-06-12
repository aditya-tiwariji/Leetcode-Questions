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
    vector<int> rightSideView(TreeNode* root) {
                 if(!root)return {};
                 queue<TreeNode*>q;
                 q.push(root);
                
                 vector<int>ans;
              
                       
                 

                 while(!q.empty()){
                        int n=q.size();
                         stack<int>st;
                        for(int i=0;i<n;i++){
                               TreeNode*node=q.front();
                               q.pop();

                               if(node->left){
                                   q.push(node->left);
                                
                               }
                               if(node->right){
                                   q.push(node->right);
                                  
                               }
                              
                                 st.push(node->val);
                        }

                        ans.push_back(st.top());
                       
                 }

                 return ans;
    }
};