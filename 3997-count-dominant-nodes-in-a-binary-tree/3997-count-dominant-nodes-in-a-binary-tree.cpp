class Solution {
public:
    int cnt = 0;

    int dfs(TreeNode* root) {
        if (root == NULL)
            return INT_MIN;

        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);

        int subtreeMax = max({root->val, leftMax, rightMax});

        if (root->val >= subtreeMax)
            cnt++;

        return subtreeMax;
    }

    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};