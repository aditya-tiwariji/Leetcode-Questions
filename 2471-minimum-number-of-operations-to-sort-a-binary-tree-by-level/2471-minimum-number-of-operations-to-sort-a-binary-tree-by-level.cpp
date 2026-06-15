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
    int minimumOperations(TreeNode* root) {
              
                 queue<TreeNode*>q;
                 q.push(root);
                 int cnt=0;
                 while(!q.empty()){
                       int n=q.size();

                        vector<int>temp;


                       for(int i=0;i<n;i++)
                       {
                            TreeNode*node=q.front();
                            q.pop();
                            temp.push_back(node->val);

                            if(node->left)q.push(node->left);
                            if(node->right)q.push(node->right);

                       }

                       vector<pair<int,int>>v;

                       for(int i=0;i<temp.size();i++){
                                 v.push_back({temp[i],i});
                       }

                         sort(v.begin(),v.end());
                       for(int i=0;i<n;i++){
                              if(v[i].second==i)continue;
                              else{
                                  cnt++;
                                  swap(v[i],v[v[i].second]);
                                  i--;
                              }
                       }



                       
                 }

                 return cnt;
    }
};