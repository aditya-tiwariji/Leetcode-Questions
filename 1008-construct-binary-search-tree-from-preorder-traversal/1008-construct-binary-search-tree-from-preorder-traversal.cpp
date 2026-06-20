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
TreeNode* fun(vector<int>& preorder,int i,int j){
                    if(i>j)return NULL;

                   TreeNode*node=new TreeNode(preorder[i]);
                   int x=-1;
                   for(int k=i+1;k<=j;k++){
                       if(preorder[k]>preorder[i]){
                             x=k-1;
                             break;
                       }
                   } 
                   if(x!=-1){
                       node->left=fun(preorder,i+1,x);
                       node->right=fun(preorder,x+1,j);
                   }
                   else{
                       node->left=fun(preorder,i+1,j);
                       node->right=NULL; 
                   }

                   return node;

}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
                   int n=preorder.size();

                   TreeNode*root=fun(preorder,0,n-1);
                   return root;
    }
};