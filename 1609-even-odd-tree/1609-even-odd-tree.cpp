/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;

        if (root == NULL)
            return 0;
        q.push(root);
        int k = 0;

        while (!q.empty()) {

            int size = q.size();
            int temp = 0;
            vector<int> level;
            int fg1 = 0, fg2= 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                int data = node->val;
                if(k==0){
                    if(data % 2 == 0) return false;
                    if(!level.empty() && level[i-1] >= data) return false;
                }
                else{
                    if(data&1) return false;
                   if(!level.empty() && level[i-1] <= data) return false;
                }
                level.push_back(data);
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if(k==0) k=1;
            else k = 0;
        }
        return true;
    }
};