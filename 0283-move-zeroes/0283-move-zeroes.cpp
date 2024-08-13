class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_found ; //ptr1
        int num ; //ptr 2
        int n = nums.size();
        int l = 0;

        for( int i = 0; i< n ; i++){
            if( nums[i] != 0){
                swap(nums[l], nums[i]);
                l++;

            }
        }

        // for( int i = l ; i<n ; i++){
        //     nums[i]= 0;
        // }
        

    }
};