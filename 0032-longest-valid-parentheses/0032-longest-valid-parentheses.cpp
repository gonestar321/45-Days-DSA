#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Initialize stack with base for boundary condition
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i); // Push the index of '('
            } else {
                st.pop(); // Pop the last '(' index
                if (st.empty()) {
                    st.push(i); // Push current index as new base
                } else {
                    // Calculate the length of current valid substring
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        
        return maxLen;
    }
};