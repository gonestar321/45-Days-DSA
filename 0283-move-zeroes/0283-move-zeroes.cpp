class Solution {
public:
    void swap(int& a , int& b){
        int c = a;
        a = b;
        b= c;
    }


    void moveZeroes(vector<int>& nums) {
        int left = 0;
            int n = nums.size();

            //BRUTE APPROACH
            // for( int i =0 ; i< n ; ++i){

            //     if( nums[i] == 0 ){
            //         for( int j = i ; j<n ; ++j){
            //             if(nums[ j] != 0){
            //                 swap(nums[i], nums[j]);
            //                 break;
            //             }
            //         }
            //     }
            // }

            //Optimal Approach
        for (int i = 0; i < n ; ++i) {
            if (nums[i] != 0) {
                swap(nums[left], nums[i]);
                left++;
            }
        }
    }

    
};