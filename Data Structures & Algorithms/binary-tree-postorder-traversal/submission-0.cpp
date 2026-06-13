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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> first_stack;
        stack<int> second_stack;
        if(root)
            first_stack.push(root);
        while(!first_stack.empty()){
            TreeNode* node = first_stack.top();
            first_stack.pop();
            second_stack.push(node->val);
            if(node->left){
                first_stack.push(node->left);
            }
            if(node->right){
                first_stack.push(node->right);
            }
        }
        vector<int> ans;
        while(!second_stack.empty()){
            ans.push_back(second_stack.top());
            second_stack.pop();
        }
        return ans;
    }
};