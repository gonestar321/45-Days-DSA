class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;  // Edge case: Single node or empty list
        
        ListNode* fast = head;
        ListNode* slow = head;

        // Step 1: Find the middle of the list
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Step 2: Reverse the second half using stack
        stack<int> st;
        ListNode* temp = slow;
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Step 3: Compare the stack values with the first half
        temp = head;
        while (!st.empty()) {
            if (temp->val != st.top()) {
                return false;
            }
            st.pop();
            temp = temp->next;
        }

        return true;
    }
};
