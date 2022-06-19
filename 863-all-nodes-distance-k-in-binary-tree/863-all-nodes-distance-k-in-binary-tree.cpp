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
    
    TreeNode* findParent(TreeNode* root,TreeNode* B, map<TreeNode*, TreeNode*>& mpp){
        queue<TreeNode*>qu;
        qu.push(root);
        TreeNode* res = NULL;
        while(qu.empty() == false){
            TreeNode* curr = qu.front();
            qu.pop();
            if(curr == B)
                res = curr;
            if(curr->left){
                mpp[curr->left] = curr;
                qu.push(curr->left);
            }
            if(curr->right){
                mpp[curr->right] = curr;
                qu.push(curr->right);
            }
        }
        return res;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*>parentMap;
        TreeNode *start = findParent(root,target,parentMap);
        map<TreeNode*, int>vis;
        vis[start] = 1;
        queue<TreeNode*>qu;
        qu.push(start);
        int lvl = 0;
        while(qu.empty() == false){
            int size =  qu.size();
            if(lvl == k)
                break;
            for(int i=0;i<size;i++){
                TreeNode* curr = qu.front();
                qu.pop();
                if(curr->left && !vis[curr->left]){
                    vis[curr->left] = 1;
                    qu.push(curr->left);
                }
                if(curr->right && !vis[curr->right]){
                    vis[curr->right] = 1;
                    qu.push(curr->right);
                }
                if(parentMap[curr] && !vis[parentMap[curr]]){
                    vis[parentMap[curr]] = 1;
                    qu.push(parentMap[curr]);
                }
            }
            lvl++;
        }
        vector<int>ans;

        while(qu.empty() == false){
            TreeNode* temp = qu.front();
            qu.pop();
            ans.push_back(temp->val);
        }
        return ans;    
    }
};