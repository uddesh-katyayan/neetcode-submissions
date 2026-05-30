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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<int> ans;
        //pair of node, level
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root,0));
        int cur_level = -1;
        while(!Q.empty()){
            TreeNode* cur_node = Q.front().first;
            int level = Q.front().second;
            Q.pop();
            if(level != cur_level){
                ans.push_back(cur_node->val);
                cur_level = level;
            }
            if(cur_node->right != NULL){
                Q.push(make_pair(cur_node->right, level+1));
            }
            if(cur_node->left != NULL){
                Q.push(make_pair(cur_node->left, level+1));
            }
        }
        return ans;
    }
};
