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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> left, right;
        unordered_set<int> parent, child;

        for (auto &it : descriptions) {
            int p = it[0];
            int c = it[1];
            int isLeft = it[2];

            parent.insert(p);
            child.insert(c);

            if (isLeft)
                left[p] = c;
            else
                right[p] = c;
        }

        int rt = -1;
        for (auto x : parent) {
            if (!child.count(x)) {
                rt = x;
                break;
            }
        }

        TreeNode* root = new TreeNode(rt);

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (left.count(node->val)) {
                node->left = new TreeNode(left[node->val]);
                q.push(node->left);
            }

            if (right.count(node->val)) {
                node->right = new TreeNode(right[node->val]);
                q.push(node->right);
            }
        }

        return root;
    }
};