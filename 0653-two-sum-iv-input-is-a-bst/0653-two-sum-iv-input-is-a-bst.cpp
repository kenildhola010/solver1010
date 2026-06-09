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
class BSTItretor{
    private:
    stack<TreeNode*> st;
    bool reverse;

    public:
    BSTItretor(TreeNode* root, bool reverse){
        this->reverse = reverse;
        pushall(root);
    }

    int next(){
        TreeNode* node = st.top();
        st.pop();

        if(reverse){
            pushall(node->left);
        }
        else{
            pushall(node->right);
        }
        return node->val;
    }


    bool hasNext(){
        return !st.empty();
    }

    void pushall(TreeNode* root){
        while(root!=NULL){
            st.push(root);

            if(reverse){
                root = root->right;
            }else{
                root = root->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        if(!root) return 0;

        BSTItretor l(root,false);  
        BSTItretor r(root,true);    

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i+j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }

        return false;
    }
};