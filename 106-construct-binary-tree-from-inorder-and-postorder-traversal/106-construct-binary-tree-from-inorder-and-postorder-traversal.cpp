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
    
    TreeNode *build(vector<int>&ino, int inStart, int inEnd, vector<int>&post, int poStart, int poEnd, map<int, int>&inMap){
        if(inStart > inEnd || poStart > poEnd){
            return NULL;
        }
        TreeNode * root = new TreeNode(post[poEnd]);
        
        int inRoot = inMap[root->val];
        int nleft = inRoot - inStart;
        
        TreeNode * left = build(ino, inStart, inRoot-1, post, poStart, poStart+ nleft-1, inMap);
        TreeNode *right = build(ino, inRoot+1, inEnd, post, poStart+ nleft, poEnd-1, inMap);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())
            return NULL;
        map<int, int>inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        TreeNode * newRoot = build(inorder,0, inorder.size() -1, postorder, 0, postorder.size()-1,inMap);
        return newRoot;
    }
    
    
};