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
    void solve(TreeNode* root,TreeNode*& temp){
        if(root == NULL)
            return;
        solve(root->left,temp);
        TreeNode* newNode = new TreeNode(root->val);
        temp->right = newNode;
        temp = temp->right;
        solve(root->right,temp);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp = new TreeNode();
        TreeNode* head = temp;
        solve(root, temp);
        return head->right;
    }
};