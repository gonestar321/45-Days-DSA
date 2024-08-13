class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int si = 0;
        int ei = nums.size() - 1;

        while (si <= ei) {
            int mid = si + ((ei - si) / 2);
            if (nums[mid] == target) {
                return mid; 
            }
            if (nums[mid] < target) {
                si = mid + 1; 
            } else {
                ei = mid - 1; 
            }
        }

        
        return si;
    }
};
