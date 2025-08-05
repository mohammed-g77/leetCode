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
    string answer = "~";  

    void dfs(TreeNode* node, string path) {
        if (!node) return;

         
        path = char('a' + node->val) + path;

         
        if (!node->left && !node->right) {
            if (path < answer) {
                answer = path;
            }
        }

         
        dfs(node->left, path);
        dfs(node->right, path);
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return answer;
    }
};
