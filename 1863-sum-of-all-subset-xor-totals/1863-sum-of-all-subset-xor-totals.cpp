class Solution {
public:
    int dfs(vector<int>& nums, int i, int xorSum) {
        if (i == nums.size()) {
            return xorSum;  // ek subset ka xor mil gaya
        }

        // Include current element
        int include = dfs(nums, i + 1, xorSum ^ nums[i]);

        // Exclude current element
        int exclude = dfs(nums, i + 1, xorSum);

        return include + exclude;  // dono cases ka sum
    }

    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};
