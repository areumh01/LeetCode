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
    vector<vector<TreeNode*>> answer;
    
    vector<TreeNode*> solve(int n){
        if(n==1) return answer[1]= {new TreeNode()};
        if(n%2==0) return answer[n] = {};
        if(answer[n].size()>0) return answer[n];
        
        vector<TreeNode*> subAnswer;
        
        for(int i=1; i<n-1; i+=2){
            vector<TreeNode*> left = solve(i);
            vector<TreeNode*> right = solve(n-1-i);
            
            for(auto l : left){
                for(auto r : right){
                    TreeNode* newNode = new TreeNode();
                    newNode->left = l;
                    newNode->right = r;
                    subAnswer.push_back(newNode);
                }
            }
        }
        return answer[n]=subAnswer;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        answer.resize(n+2);
        return solve(n);
    }
};