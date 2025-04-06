class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Step 1: Sort

        int n = nums.size();
        vector<int> dp(n, 1);   // dp[i] = length of largest subset ending at i
        vector<int> prev(n, -1); // to track the path
        int maxIdx = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIdx]) {
                maxIdx = i;
            }
        }

        // Backtrack to get the answer
        vector<int> ans;
        while (maxIdx != -1) {
            ans.push_back(nums[maxIdx]);
            maxIdx = prev[maxIdx];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
