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
    
    int solve(TreeNode* root, int ans){
        if(root == NULL)
            return 0;
        ans = ans * 10 + root->val ;
        if(root->left == NULL &&  root->right == NULL)          // at the leaf node
            return ans;
        int la = solve(root->left, ans);
        int ra = solve(root->right, ans);
        
        return la+ ra;
    }
    
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};