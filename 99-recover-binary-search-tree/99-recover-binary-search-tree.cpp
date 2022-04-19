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
    
    void solve(TreeNode* root, TreeNode*& prev, TreeNode* &start, TreeNode* &end){
        if(root == nullptr)
            return;
        solve(root->left, prev,start,end);
        if(prev != NULL){
            if(root->val < prev->val){
                if(start == NULL)
                    start = prev;
                end = root;
            }
        }
        prev = root;
        solve(root->right,prev,start,end);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode * start = NULL, *prev = NULL, *end = NULL;
        solve(root, prev, start, end);
        swap(start->val, end->val);
        return;
    }
};