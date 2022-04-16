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
    void solve(TreeNode* root, int& update){
        if(root == NULL) return;
        solve(root->right, update);
        root->val =  root->val + update;
        update = root->val;
        solve(root->left,update);
    }
    
    
    TreeNode* bstToGst(TreeNode* root) {
        int update = 0;
        solve(root,update);
        return root;
    }
};