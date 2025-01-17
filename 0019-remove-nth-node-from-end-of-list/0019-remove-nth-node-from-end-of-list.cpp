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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* total = head;
       
        if( total == NULL || total->next == NULL){
           return (n == 1) ? NULL : head;
        }
            int count = 0;
        while( total != NULL ){
            total = total ->next;
                count ++;
        }

        ListNode* remover = head;   

        int rem = count - n;

        if( rem == 0 ){
            return head->next;
        }

        for( int i = 1 ; i< rem ; ++i){
            
            remover = remover->next;
        }
        remover ->next = remover->next->next;
        return head;
    }
};