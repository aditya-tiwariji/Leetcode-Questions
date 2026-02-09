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

void preorder(TreeNode*root,vector<int>&a){
           if(!root)return ;

          preorder(root->left,a);
          a.push_back(root->val);
          preorder(root->right,a);

          
}
 
 TreeNode*MakeBST(int i,int j,vector<int>&a){
         
            if(j<i)return NULL;
            int mid=(i+j)/2;

            TreeNode*root=new TreeNode(a[mid]);
           root->left=MakeBST(i,mid-1,a);
           root->right=MakeBST(mid+1,j,a);

            return root;
              
 }

    TreeNode* balanceBST(TreeNode* root) {
            
            vector<int>a;
            preorder(root,a); 
            int n=a.size(); 
            
            TreeNode*finalRoot=MakeBST(0,n-1,a);
            return finalRoot;

                
    }
};