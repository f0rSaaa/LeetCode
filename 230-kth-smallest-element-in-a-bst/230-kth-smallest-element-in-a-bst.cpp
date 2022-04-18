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
    
    void solve(TreeNode*root , int k , priority_queue<int>&maxH){
        if(root == NULL)
            return;
        solve(root->left, k,maxH);
        maxH.push(root->val);
        if(maxH.size()>k){
            maxH.pop();
        }
        solve(root->right,k,maxH);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int>maxH;
        solve(root,k,maxH);
        return maxH.top();
    }
};