/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        int rootV =  root->val;
        if(rootV< p->val && rootV < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }else if(rootV > p->val && rootV> q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
        
    }
};