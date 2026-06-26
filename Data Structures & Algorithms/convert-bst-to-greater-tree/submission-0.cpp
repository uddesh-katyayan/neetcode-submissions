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
    TreeNode* convertBST(TreeNode* root) {
        convertBSTHelper(root, 0);
        return root;
    }
private:
    int convertBSTHelper(TreeNode* root, int to_be_added){
        if(root == NULL){
            return 0;
        }
        int right_sum = convertBSTHelper(root->right, to_be_added);
        int left_sum = convertBSTHelper(root->left, to_be_added+root->val+right_sum);
        int org = root->val;
        root->val += to_be_added + right_sum;
        return right_sum + left_sum + org; 
    }
};