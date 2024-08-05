class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            switch (nums[mid]) {
                case 0:
                    // Swap nums[low] and nums[mid], increment low and mid
                    swap(nums[low++], nums[mid++]);
                    break;
                case 1:
                    // Move to the next element
                    mid++;
                    break;
                case 2:
                    // Swap nums[mid] and nums[high], decrement high
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
    }
    
    void inline swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
