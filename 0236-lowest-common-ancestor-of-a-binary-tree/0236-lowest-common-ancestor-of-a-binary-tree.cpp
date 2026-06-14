/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                // make parent
                // check  moving 1 node at a time
                   unordered_map<TreeNode*,TreeNode*>parent;

                   queue<TreeNode*>qu;
                   qu.push(root);
                   parent[root]=root;

                   while(!qu.empty()){
                         int n=qu.size();

                         for(int i=0;i<n;i++)
                         {
                              TreeNode* node=qu.front();
                              qu.pop();

                              if(node->left){
                                  qu.push(node->left);
                                  parent[node->left]=node;
                                  
                              }
                              if(node->right){
                                  qu.push(node->right);
                                  parent[node->right]=node;

                              }

                         }
                   }

                   unordered_set<TreeNode*>seen;
                    TreeNode*node=p;
                    seen.insert(node);
                   while(parent[node]!=node){
                          node=parent[node];
                          seen.insert(node);
                   }
                   
                   node=q;

                   while(seen.count(node)==0){
                           node=parent[node];
                   }

                   return node;




    }
};