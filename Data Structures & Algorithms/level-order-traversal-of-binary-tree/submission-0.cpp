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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root,0));
        vector<vector<int>> ans;
        vector<int> level_nodes;
        int cur_level = 0;
        while(!Q.empty()){
            TreeNode* node = Q.front().first;
            int level = Q.front().second;
            Q.pop();
            if(cur_level == level){
                level_nodes.push_back(node->val);
            }
            else{
                ans.push_back(level_nodes);
                level_nodes = {node->val};
                cur_level++;
            }
            if(node->left != NULL){
                Q.push(make_pair(node->left, level+1));
            }
            if(node->right != NULL){
                Q.push(make_pair(node->right, level+1));
            }
        }
        if(level_nodes.size()>0){
            ans.push_back(level_nodes);
        }
        return ans;

    }
};
