class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int si = 0;
        int ei = nums.size() - 1;

        while (si <= ei) {
            int mid = si + ((ei - si) / 2);
            if (nums[mid] == target) {
                return mid; // Target found at mid index
            }
            if (nums[mid] < target) {
                si = mid + 1; // Move to the right half
            } else {
                ei = mid - 1; // Move to the left half
            }
        }

        // When target is not found, si is the correct insert position
        return si;
    }
};
