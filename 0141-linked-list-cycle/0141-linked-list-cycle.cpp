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
        //Floyd's Tortoise and Hare method
        //fast pointer and a slow pointer
        // we'll keep the loop on till the time fast pointer catches
        // the slow pointer
        // when it does... we call it a CYCLE IN LINKED LIST
        
         ListNode *tortoise = head, *hare = head ;

        if (head == nullptr || head->next == nullptr) {
        return false; // No cycle if the list is empty or has only one node
    }


    while(hare != nullptr && hare ->next != nullptr){
        tortoise = tortoise->next;
        hare = hare->next->next;

        if(tortoise == hare){
            return true;
        }
    }
    return false;

    }
};