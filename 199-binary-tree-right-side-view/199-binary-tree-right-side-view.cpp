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
    vector<int>ans;
    
    void lsv(TreeNode* root, int level, vector<int>& ans){
        if(root == NULL)
            return;
        if(ans.size() == level)
            ans.push_back(root->val);
        lsv(root->right, level+1, ans);
        lsv(root->left, level+1, ans);


    }
    vector<int> rightSideView(TreeNode* root) {

//Function to return a list containing elements of left view of the binary tree.



       vector<int> ans;
       int level =0;
       lsv(root, level, ans);
       return ans;
    }
    
    
    
//     void rsV(TreeNode* root, int level, vector<int> & ans){
//         if(root == NULL)
//             return;
//         if(ans.size() == level)
//             ans.push_back(root->val);
//         rsV(root->right, level+1, ans);
//         rsV(root->left, level+1, ans);
//     }

//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         int level = 0;
//         rsV(root, level, ans);
//         return ans;
//     }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};