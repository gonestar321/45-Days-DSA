class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        int n = nums.size();
        int i = 0;
        int l = n - 1;

        while (i <= l) {
            int mid = i + (l - i) / 2;
            if (nums[mid] == target) {
                first = mid;
                last = mid;

                // Find the first occurrence
                while (first > 0 && nums[first - 1] == target) {
                    first--;
                }

                // Find the last occurrence
                while (last < n - 1 && nums[last + 1] == target) {
                    last++;
                }
                return {first, last};
            }
            if (nums[mid] < target) {
                i = mid + 1;
            } else {
                l = mid - 1;
            }
        }
        return {-1, -1};
    }
};
