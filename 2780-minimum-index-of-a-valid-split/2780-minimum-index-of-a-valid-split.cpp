class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the dominant element using Boyer-Moore's Voting Algorithm
        int candidate = -1, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        // Step 2: Verify the dominant element
        int totalCount = count_if(nums.begin(), nums.end(), [&](int num) { return num == candidate; });
        if (totalCount * 2 <= n) return -1; // No dominant element (shouldn't happen per problem statement)

        // Step 3: Find the minimum valid split index
        int prefixCount = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == candidate) {
                prefixCount++;
            }
            int suffixCount = totalCount - prefixCount;
            
            if (prefixCount * 2 > (i + 1) && suffixCount * 2 > (n - i - 1)) {
                return i;
            }
        }
        
        return -1; // No valid split found
    }
};
