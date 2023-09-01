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
    bool isValid(TreeNode* root, long long minn, long long maxx){
        if(root==nullptr) return true;
        if(root->val < maxx && root->val > minn){
            return isValid(root->left,minn,root->val)&&isValid(root->right,root->val,maxx);
        }
        else return false;
    }

    bool isValidBST(TreeNode* root) {
       return isValid(root,-1e10,1e10); 
    }
};