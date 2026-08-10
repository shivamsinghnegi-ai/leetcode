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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode(0);
        ListNode* smallTail = small;
        ListNode* bigTail = big;
        ListNode* curr = head;
        while (curr != nullptr) {

            if (curr->val < x) {
                smallTail->next = curr;
                smallTail = smallTail->next;
            }
            else {
                bigTail->next = curr;
                bigTail = bigTail->next;
            }

            curr = curr->next;
        }
        bigTail->next = nullptr;
        smallTail->next = big->next;

        return small->next;
    }
};