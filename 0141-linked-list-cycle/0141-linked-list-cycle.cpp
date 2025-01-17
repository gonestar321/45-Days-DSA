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
    bool hasCycle(ListNode *head) {
        //tortoise hare method bata rhe hain ye 
        //dekhte hain baaki...
        ListNode* fast = head;
        ListNode* slow = head;

        if( head==NULL || head->next ==NULL) return 0;

      while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next; 
            slow = slow->next;     

            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};