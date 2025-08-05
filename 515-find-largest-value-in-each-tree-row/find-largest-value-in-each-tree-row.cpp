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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int maxVal = INT_MIN;  
            for (int i = 0; i < levelSize; i++) {
                TreeNode* n = q.front();
                q.pop();

                maxVal = max(maxVal, n->val);

                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }

            res.push_back(maxVal);
        }

        return res;
    }
};
