/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head;
        ListNode * slow = head;
// pehle loop find kardo tortoise har method se
        while( fast!= NULL && fast ->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
// intersection point found
            if( fast == slow){
//abb chalega 
                ListNode* entry = head;
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return NULL;

    }
};