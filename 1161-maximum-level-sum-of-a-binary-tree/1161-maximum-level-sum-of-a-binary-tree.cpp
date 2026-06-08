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
    int maxLevelSum(TreeNode* root) {
        map<int,int> mp;
        queue<TreeNode*> q;


        if(root == NULL) return 0;
        q.push(root);
        int  k = 1;

        while(!q.empty()){
            
            int size = q.size();
            int temp = 0;

            for(int i = 0; i<size; i++)
            {
                TreeNode* node = q.front();
                temp+=node->val;
                q.pop();

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            mp[k] = temp;
            k++;
        }

        int ans =INT_MIN;
        int mx = 0;

        for(auto i : mp){
            if(i.second > ans){
                ans = i.second;
                mx = i.first;
            }
        }

        return mx;
    }
};