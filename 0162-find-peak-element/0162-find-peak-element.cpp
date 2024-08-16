class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0;
        int upp = n-1;
        int peak = INT_MIN;

        while( low < upp){
            int mid = low + (upp - low)/2;

            if(nums[mid]> nums[mid+1]){
                upp = mid;
            }else{
                low = mid + 1 ;
            }
        }
        return low;
    }
};