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
   vector<int>in;
 void inorder(TreeNode*root){
         
            if(!root)return ;

            inorder(root->left);
            in.push_back(root->val);
            inorder(root->right);

 }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
                 
                   inorder(root);
                    vector<vector<int>>ans;
                   for(auto it:queries){
                             
                               auto x=lower_bound(in.begin(),in.end(),it);
                                 
                               if(x==in.end()){
                                    
                                    ans.push_back({in.back(),-1});
                               }
                               else{
                                   int   ind=x-in.begin();
                                   
                               if(in[ind]==it)ans.push_back({it,it});
                               else if(ind==0)ans.push_back({-1,in[ind]});
                               else ans.push_back({in[ind-1],in[ind]});
                               }
                   }

                   return ans;
    }
};