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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*>qu;
        qu.push(root);
        vector<int>aux;
        while(!qu.empty()){
            int size = qu.size();
            aux.clear();
            for(int i=0;i<size;++i){
                TreeNode* x= qu.front();
                qu.pop();
                aux.push_back(x->val);
                if(x->left)
                    qu.push(x->left);
                if(x->right)
                    qu.push(x->right);
            }
            ans.push_back(aux);
        }
        return ans;
    }
};