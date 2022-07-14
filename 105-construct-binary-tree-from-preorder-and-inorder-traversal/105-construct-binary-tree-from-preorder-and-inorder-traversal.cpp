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
    TreeNode* build(vector<int>&pre, int preStart, int preEnd, vector<int>&ino, int inStart, int inEnd, unordered_map<int, int>& inMap){
        if(preStart> preEnd || inStart > inEnd)
            return NULL;
        TreeNode *root = new TreeNode(pre[preStart]);
        
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = build(pre, preStart+1, preStart+numsLeft, ino, inStart, inRoot-1, inMap);
        root->right = build(pre, preStart+numsLeft+1, preEnd, ino, inRoot+1, inEnd, inMap);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>inMap;
        for(int i=0;i<inorder.size();++i){
            inMap[inorder[i]] = i;   
        }
        TreeNode * root = build(preorder, 0, preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
};