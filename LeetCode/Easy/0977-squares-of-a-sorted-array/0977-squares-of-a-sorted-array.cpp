class Solution {
public:
    // void swap( int i , int j , vector<int>&nums){
    //     int b = nums[j];
    //     nums[j] = nums[i];
    //     nums[i] = b ;
    // }

    // vector<int> sortedSquares(vector<int>& nums) {   
    //     int n = nums.size();

    //     int start = 0 ;
    //     int end = n-1;
        
    //     for( int i = 0 ;  i < n ; i++){
    //         nums[i] *= nums[i];
    //     }

    //     while(start < end ){

    //         if( nums[start] > nums[end] ){
    //             swap(start ,  end , nums);
    //         }else if(nums[start] < nums[end]){
    //             end--;
    //         }
    //     }

    //     return nums;
    // }

    vector<int> sortedSquares(vector<int>& nums) { 
        for( int i = 0 ; i < nums.size() ; i++ ){
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin() , nums.end());

        for( int i = 0 ; i < nums.size() ; i++ ){
            nums[i] *= nums[i];
        }
return nums;

    }
};