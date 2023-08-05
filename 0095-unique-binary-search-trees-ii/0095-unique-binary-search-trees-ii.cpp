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
    vector<TreeNode*> make_tree(int start, int end){
        vector<TreeNode*> v;
        if(start>end){
            v.push_back(nullptr);
            return v;
        }
        else if(start==end){
            v.push_back(new TreeNode(start));
            return v;
        }
        else{
            for(int i=start; i<=end; i++){
                vector<TreeNode*> l = make_tree(start, i-1);
                vector<TreeNode*> r = make_tree(i+1, end);
                
                for(auto le:l){
                    for(auto re:r){
                        TreeNode* root = new TreeNode(i);
                        root->left = le;
                        root->right = re;
                        v.push_back(root);
                    }
                }
            }
        }
        return v;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return make_tree(1,n);
    }
};