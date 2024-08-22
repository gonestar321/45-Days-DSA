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
        //tortoise and hare method
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!= NULL&& fast->next!=NULL){
            slow= slow->next;
            fast = fast->next->next;
            if(fast == slow){
                ListNode* ptr = head;
                
                while( ptr != slow){
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return NULL;
    }
};