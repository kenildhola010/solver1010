/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {

        ListNode* node = head;
        int ct = 0;

        while (node->next != NULL) {
            ct++;
            node = node->next;
        }
           ct++;
        vector<int> v(ct / 2, 0);

        int k = 0;
     
        
        node = head;
        while (node != NULL) {
            if (k < ct/2) {
                v[k] = node->val;
                k++;
            } else {
                v[ct - k - 1] += node->val;
                k++;
            }
            node = node->next;
        }

        int ans = INT_MIN;
        for (int i : v) {
            cout << i << " ";
            ans = max(ans, i);
        }

        return ans;
    }
};