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
    void path(TreeNode* root, string s, vector<string>& v){
        if(root== NULL) return;

        
        s+=to_string(root->val);
        if(root->left == NULL && root->right ==NULL){
            v.push_back(s);
        }
        path(root->left,s,v);
        path(root->right,s,v);
    }
    int sumNumbers(TreeNode* root) {
        vector<string> v;
        if(root == NULL) return 0;
        string s="";

        path(root,s,v);
        int ans = 0;

        for(auto i : v){
            ans+=stoi(i);

        }
        return ans;
    }
};