class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        // Sort events by end time
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        // dp[i][j] = max value using first i events, choosing j
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        // Build array of end times for binary search
        vector<int> ends;
        for (auto &e : events) ends.push_back(e[1]);

        for (int i = 1; i <= n; i++) {
            int start = events[i - 1][0];
            int value = events[i - 1][2];

            // Binary search: find the last event that ends < current start
            int prev = upper_bound(ends.begin(), ends.end(), start - 1) - ends.begin();

            for (int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + value);
            }
        }

        return dp[n][k];
    }
};
