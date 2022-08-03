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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        bool l2r =  true;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            vector<int>aux(size);
            for(int i=0;i<size;++i){
                TreeNode *x = qu.front();
                qu.pop();
                int idx = l2r?i : size-i-1;
                aux[idx] = x->val;
                if(x->left){
                    qu.push(x->left);
                }
                if(x->right)
                    qu.push(x->right);
                
            }
            l2r = !l2r;
            ans.push_back(aux);
        }
        return ans;
    }
};