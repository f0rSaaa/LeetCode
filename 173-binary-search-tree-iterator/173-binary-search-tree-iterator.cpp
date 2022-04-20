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
class BSTIterator {
public:
    vector<int>in;
    int i=-1;
    void solve(TreeNode* root){
        if(root == NULL)
            return;
        solve(root->left);
        in.push_back(root->val);
        solve(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        i++;
        return in[i];
        
    }
    
    bool hasNext() {
        if(i+1 < in.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */