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
    // int maxDepth(TreeNode* root) {
    //     if(root == NULL){
    //         return 0;
    //     }
    //     return 1 + max(maxDepth(root->left), maxDepth(root->right));
    // }
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root,1));
        int max_depth = 1;
        while(!Q.empty()){
            auto front = Q.front();
            Q.pop();
            if(front.first->left!=NULL){
                max_depth = max(max_depth, 1+front.second);
                Q.push(make_pair((front.first->left), 1+front.second));
            }
            if(front.first->right!=NULL){
                max_depth = max(max_depth, 1+front.second);
                Q.push(make_pair((front.first->right), 1+front.second));
            }
        }
        return max_depth;
    }
};
