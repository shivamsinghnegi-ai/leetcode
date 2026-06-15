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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode*p=head;
        ListNode*q=head;
        ListNode*prev=NULL;
        while(q !=NULL && q->next!=NULL){
            prev =p;
            p=p->next;
            q=q->next->next;
        }
        prev->next = p->next;
        return head;
    }
};