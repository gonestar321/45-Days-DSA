class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int nonZero = 0; // points to where the next non-zero should go

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[nonZero]);
                nonZero++;
            }
        }
    }
};