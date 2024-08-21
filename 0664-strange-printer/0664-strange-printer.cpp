class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (n == 0) return 0;

        // Initialize a 2D DP array
        vector<vector<int>> dp(n, vector<int>(n, n));
        
        // Base case: Single character substrings
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Fill the DP table
        for (int len = 2; len <= n; len++) { // len is the length of the substring
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                // If the characters at both ends are the same
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j-1];
                } else {
                    // Try to minimize the number of turns by splitting
                    for (int k = i; k < j; k++) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
};
