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
    int getDecimalValue(ListNode* head) {
          
        ListNode *ptr = head;
        int vals = 0;
        while (ptr) {
            vals++;
            ptr = ptr->next;
        }

        
        ptr = head;
        int decimalValue = 0;
        while (ptr) {
            
            decimalValue = (decimalValue << 1) | ptr->val;
            ptr = ptr->next;
        }

        return decimalValue;
    }
};