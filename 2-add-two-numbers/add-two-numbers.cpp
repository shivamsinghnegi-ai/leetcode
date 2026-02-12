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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1 = "", s2 = "";
        while (l1) {
            s1 = char(l1->val + '0') + s1;
            l1 = l1->next;
        }
        while (l2) {
            s2 = char(l2->val + '0') + s2;
            l2 = l2->next;
        }
        string result = "";
        int carry = 0;
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += s1[i--] - '0';
            if (j >= 0) sum += s2[j--] - '0';
            result = char(sum % 10 + '0') + result;
            carry = sum / 10;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int k = result.size() - 1; k >= 0; k--) {
            curr->next = new ListNode(result[k] - '0');
            curr = curr->next;
        }
        return dummy->next;
    }
};
