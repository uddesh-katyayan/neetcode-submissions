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
    bool isValidBST(TreeNode* root) {
        return checkIfvalid(root, INT_MIN, INT_MAX);
    }
private:
    bool checkIfvalid(TreeNode* root, int left_limit, int right_limit){
        if(root == NULL){
            return true;
        }
        cout << "Node_val: " << root->val << " limits: " << left_limit << ", " << right_limit <<endl;
        if(root->val <= left_limit || root->val >= right_limit){
            return false;
        }
        bool leftValid = checkIfvalid(root->left, left_limit, min(root->val, right_limit));
        bool rightValid = checkIfvalid(root->right, max(root->val, left_limit), right_limit);
        return leftValid && rightValid; 
    }
};
