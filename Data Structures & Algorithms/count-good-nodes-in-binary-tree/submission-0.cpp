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
    int goodNodes(TreeNode* root) {
        int good_nodes = 0;
        multiset<int> trail;
        dfs(root, trail, good_nodes);
        return good_nodes;
    }
private:
    void dfs(TreeNode* root, multiset<int>& trail, int& good_nodes){
        if(root == NULL){
            return;
        }
        int max_till_now = trail.size()>0 ? (*(trail.rbegin())) : INT_MIN;
        if(root->val >= max_till_now){
            good_nodes++;
        }
        trail.insert(root->val);
        dfs(root->left, trail, good_nodes);
        dfs(root->right, trail, good_nodes);
        trail.erase(trail.find(root->val));
    }
};
