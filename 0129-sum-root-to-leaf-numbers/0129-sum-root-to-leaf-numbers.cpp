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
int sum=0;
void  preorder(TreeNode*node,int x){
                  if(!node)return ;

                  x=x*10+node->val;
              if(!node->left&&!node->right){
                        sum+=x;
                        return ;
              }   
          

              preorder(node->left,x);
              preorder(node->right,x);

              x=x/10;

}
    int sumNumbers(TreeNode* root) {
        
               preorder(root,0);

               return sum;
    }
};