class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> q;  // Stores number -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // If complement exists in the map, return indices
            if (q.count(complement)) {
                return {q[complement], i};
            }

            // Otherwise, store current number with its index
            q[nums[i]] = i;
        }

        return {};  // No solution found
    }
};
