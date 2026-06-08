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
int i = 0;
    void inorder(TreeNode* root,vector<int>& in){
        if(root==NULL) return;

        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);

    }

    void path(TreeNode* root,vector<int>& map){
        if(root==NULL) return;

        path(root->left,map);
        root->val = map[i];
        i++;
        path(root->right,map);

    }
    TreeNode* convertBST(TreeNode* root) {
        if(root== NULL) return NULL;
        vector<int> in;
        vector<int> sum;
        
        inorder(root,in);
        int temp = 0;
        reverse(in.begin(),in.end());
        for(int i :in){
            temp +=i;
            sum.push_back(temp);
        }
       reverse(sum.begin(),sum.end());
        path(root,sum);

        return root;
    }
};