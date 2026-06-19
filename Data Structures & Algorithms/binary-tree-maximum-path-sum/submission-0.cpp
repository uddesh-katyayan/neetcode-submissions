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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        pathSum(root, max_sum);
        return max_sum;
    }
private:
    int pathSum(TreeNode* root, int& max_path_sum){
        if(root==NULL)
            return 0;
        int left_sum = pathSum(root->left, max_path_sum);
        int right_sum = pathSum(root->right, max_path_sum);
        int mx_with_root = max({
            left_sum,
            right_sum,
            left_sum + right_sum
        });
        mx_with_root = max(mx_with_root + root->val, root->val);
        max_path_sum = max(mx_with_root, max_path_sum);
        return max({
            root->val + left_sum,
            root->val + right_sum,
            root->val
        });
    }
};
