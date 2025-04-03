

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        vector<int> max_prefix(n, 0);
        max_prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            max_prefix[i] = max(max_prefix[i-1], nums[i]);
        }
        
        vector<int> max_diff(n, 0);
        for (int j = 1; j < n; ++j) {
            max_diff[j] = max_prefix[j-1] - nums[j];
        }
        
        vector<int> max_diff_up_to(n, 0);
        max_diff_up_to[1] = max_diff[1];
        for (int j = 2; j < n; ++j) {
            max_diff_up_to[j] = max(max_diff_up_to[j-1], max_diff[j]);
        }
        
        long long max_val = 0;
        for (int k = 2; k < n; ++k) {
            long long current = (long long)max_diff_up_to[k-1] * nums[k];
            if (current > max_val) {
                max_val = current;
            }
        }
        
        return max_val > 0 ? max_val : 0;
    }
};